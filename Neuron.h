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
#ifndef NEURON_H
#define NEURON_H


class Neuron
{
public:
	Neuron(double weight) : m_weight(weight) {};
	Neuron(double weight, std::string name) : m_weight(weight), m_name(name) {};

	double GetNeuronWeight()
	{
		return m_weight;
	}
	std::string GetNeuronName()
	{
		return m_name;
	}
	void SetNeuronWeight(double& xx)
	{
		this->m_weight = xx;
	}
	void SetNeuronName(std::string& ss)
	{
		this->m_name = ss;
	}

	~Neuron() {};

private:
	double m_weight{};
	std::string m_name{};
};


#endif