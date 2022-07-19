#pragma once
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
#ifndef MAPS_H
#define MAPS_H

class Maps
{
private:
	int m_rows = 0;
	int m_columns = 0;
	double m_minvalue = -1.0f;
	double m_maxvalue = 1.0f;
	std::vector<std::vector<double>> PixelMap() {};

public:
	Maps(int rows, const int columns) : m_rows(rows), m_columns(columns) {};
	int GetMRows()
	{
		return m_rows;
	};
	int GetMColumns()
	{
		return m_columns;
	};
	int NumElements()
	{
		return GetMRows() * GetMColumns();
	};
	void PrintMapsVector()
	{
		

	};
};







#endif