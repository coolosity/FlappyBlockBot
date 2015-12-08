#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include <algorithm>

std::vector<std::string> readFile(std::string file)
{
	std::vector<std::string> lines;
	std::ifstream infile;
	infile.open(file);
	std::string line;
	while (std::getline(infile, line))
	{
		lines.push_back(line);
	}
	infile.close();
	return lines;
}

bool fileExists(std::string fileName)
{
	std::ifstream infile(fileName);
	return infile.good();
}

std::vector<std::string> split(std::string str, std::string delim)
{
	std::vector<std::string> lines;
	int ind = str.find(delim);
	int last = 0;
	while (ind != std::string::npos)
	{
		lines.push_back(str.substr(last, ind - last));
		last = ind + delim.length();
		ind = str.find(delim, ind + 1);
	}
	lines.push_back(str.substr(last));
	return lines;
}

int getTime()
{
	time_t  timev;
	return static_cast<int>(time(&timev));
}

std::string toLowerCase(std::string str)
{
	std::string lower = str;
	transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
	return lower;
}