#include <windows.h>
#include <iostream>
#include <string>
#include "myutils.h"

using namespace std;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);

HWND hWnd = NULL;

string titleSearch = "Flappy Main";

int main()
{
	//Parses through all windows on screen searching for one with title containing titleSearch
	EnumWindows(EnumWindowsProc, NULL);
	if (hWnd == NULL)
	{
		//If window is not found, close the program
		cout << "No matches for windows containing title \"" << titleSearch << "\"" << endl;
		system("pause");
		return 0;
	}
	else
	{
		cout << "Found window containing title \"" << titleSearch << "\"" << endl;
	}

	//Get HBITMAP for screen (get image of the window's screen)
	HBITMAP hbitmap = NULL;

	HDC hdc = GetWindowDC(hWnd);
	if (hdc)
	{
		HDC hdcMem = CreateCompatibleDC(hdc);
		if (hdcMem)
		{
			RECT rc;
			GetWindowRect(hWnd, &rc);

			hbitmap = CreateCompatibleBitmap(hdc, rc.right - rc.left, rc.bottom - rc.top);
			if (hbitmap)
			{
				SelectObject(hdcMem, hbitmap);

				PrintWindow(hWnd, hdcMem, 0);

				OpenClipboard(NULL);
				EmptyClipboard();
				SetClipboardData(CF_BITMAP, hbitmap);
				CloseClipboard();

				DeleteObject(hbitmap);
			}
			DeleteObject(hdcMem);
		}
		ReleaseDC(hWnd, hdc);
	}

	//If fails, exit the program
	if (!hbitmap)
	{
		cout << "Could not get HBITMAP for window screen" << endl;
		system("pause");
		return 0;
	}



	system("pause");
	return 0;
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	char title[80];
	GetWindowText(hwnd, title, sizeof(title));
	string ltitle = toLowerCase(title);

	if (ltitle.find(toLowerCase(titleSearch)) != string::npos)
	{
		hWnd = hwnd;
	}

	return TRUE;
}