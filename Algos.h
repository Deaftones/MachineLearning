#pragma once
#ifndef ALGOS_H
#define ALGOS_H
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
#include "Neuron.h"

void LSquash(std::vector<Neuron>& vec)
{
	for (auto& i : vec)
	{
		double wt = i.GetNeuronWeight() / (i.GetNeuronWeight() + 1);
		i.SetNeuronWeight(wt);
	}
}

void NSquash(Neuron& neu)
{
	double wt = neu.GetNeuronWeight() / (neu.GetNeuronWeight() + 1);
	neu.SetNeuronWeight(wt);
}

void LRectify(std::vector<Neuron>& vec)
{
	for (auto& i : vec)
	{
		if (i.GetNeuronWeight() < 0)
		{
			double wt = 0.0f;
			i.SetNeuronWeight(wt);
		}
	}
}

void NRectify(Neuron& neu)
{
	if (neu.GetNeuronWeight() < 0)
	{
		double wt = 0.0f;
		neu.SetNeuronWeight(wt);
	}
}


#endif
