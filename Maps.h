#pragma once
#ifndef MAPS_H
#define MAPS_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <iterator>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <random>

class Maps
{
private:
	int m_rows = 0;
	int m_columns = 0;
	double m_minvalue = -1.0f;
	double m_maxvalue = 1.0f;
	std::vector<double> PixelMap;

public:
	Maps(int rows, const int columns) : m_rows(rows), m_columns(columns) {};
	int GetMRows() { return m_rows; };
	int GetMColumns() { return m_columns; };
	int NumElements() { return GetMRows() * GetMColumns(); };
	void CreateMap()
	{
		for (int i = 0; i < NumElements(); ++i)
		{
			PixelMap.push_back(0.0f);
		}
	}
	void PrintMap()
	{
		int rows = GetMRows();
		for (int i = 0; i < NumElements(); ++i)
		{
			std::cout << PixelMap[i] << '\t';
			if ((i + 1) % GetMRows() == 0)
			{
				std::cout << '\n' << '\n' << '\n' << '\n';
			}
			
		}
	}
	~Maps() {};

};







#endif