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
#include "Maps.h"

#ifndef NEURON_H
#define NEURON_H


class Neuron
{
public:
	Neuron() {};
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
//--------------------------------------------------------------------------------------
//======================================================================================
template <typename T, Neuron& ...>
class Neuron_Layer : public Neuron
{
private:
	static unsigned int m_layer_number;
	unsigned int m_number_of_neurons = 0;
	std::vector<Neuron> neuronLayer;


public:
	Neuron_Layer(unsigned int numNeurons, Neuron& ... T) : m_number_of_neurons(numNeurons)
	{
		for (int i = 0; i < numNeurons; ++i) 
		{
			neuronLayer.push_back(T);
		}
		m_layer_number += 1;
	}
	void PrintNeuronLayer()
	{
		for (auto& i : neuronLayer)
		{
			std::cout << neuronLayer[i] << '\n';
		}
	}
	~Neuron_Layer() {};

};


#endif