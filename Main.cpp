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

int main() {
	
	Neuron a(2.12, "One");
	Neuron b(44.1, "Two");
	Neuron c(23.1, "Three");
	Neuron d(3.1, "Four");

	Neuron_Layer abc (4, a);

	return 0;
}