#include <iostream>
#include <Eigen/dense>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <iterator>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <random>
//==== C - L - A - S - S ===========================================================================
class Neuron {
public:
	Neuron(double weight) : p_neuron_weight(weight) {};
	Neuron(std::string neuronName, double weight) : p_neuron_name(neuronName), p_neuron_weight(weight){};
	std::string get_p_neuron_name() {
		return p_neuron_name;
	}
	double get_p_neuron_weight() {
		return p_neuron_weight;
	}
	

	friend std::ostream& operator<<(std::ostream& out, Neuron neuron);
	~Neuron() {};
private:
	std::string p_neuron_name{};
	double p_neuron_weight{};
};

std::ostream& operator<<(std::ostream& out, Neuron neuron) {
	out << neuron.get_p_neuron_name() << '\t' << neuron.get_p_neuron_weight() << '\n';
	return out;
};
//--------------------------------------------------------------------------------------------------
struct Grid_4x4 {
	std::array<bool, 4> sWhite = { true, true, true, true };
	std::array<bool, 4> sBlack = { false, false, false, false };
	std::array<bool, 4> hWhite = { true, false, true, false };
	std::array<bool, 4> hBlack = { false, true, false, true };
	std::array<bool, 4> vWhite = { true, true, false, false };
	std::array<bool, 4> vBlack = { false, false, true, true };
	std::array<bool, 4> dWhite = { true, false, true, false };
	std::array<bool, 4> dBlack = { false, true, false, true };
};


/*
std::vector<Neuron*> neuronVector;

void createNeurons(int& numNeurons) {
	for (int i = 1; i <= numNeurons; ++i) {
		std::string neuronName = "neur_";
		neuronName += std::to_string(i);
		neuronVector.push_back(new Neuron (neuronName, 0.0));
	
	}
}

void deleteNeurons() {
	for (int i = 0; i < neuronVector.size(); ++i) {
		std::cout << "Deleting NEURON named " << neuronVector[i]->get_p_neuron_name();
		delete neuronVector[i];
		neuronVector[i] = nullptr;
		std::cout << "\nDeleted.\n";
	}
}

void printNeurons() {
	std::cout << "NAME: " << "WEIGHT: \n";
	//std::cout << vec;
}*/

double Squash(Neuron& a, Neuron& b) {
	double v{};
	double sum = a.get_p_neuron_weight() + b.get_p_neuron_weight();
	v = (sum * sum) / (1 + (sum * sum));
	return v;
}

//==== M - A - I - N ===========================================================================
int main() {
	double min = 0.0;
	double max = 1.0;
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_real_distribution<double> distr(min, max);
	std::array<double, 4> neuronWeightings{};
	for (int i = 0; i < 4; ++i) {
		neuronWeightings[i] = distr(eng);
	}
	//LAYER ONE
	Neuron L1_N1(neuronWeightings[0]);
	Neuron L1_N2(neuronWeightings[1]);
	Neuron L1_N3(neuronWeightings[2]);
	Neuron L1_N4(neuronWeightings[3]);

	//LAYER TWO
	Neuron L2_N1(Squash(L1_N1, L1_N2));
	Neuron L2_N2(Squash(L1_N1, L1_N3));
	Neuron L2_N3(Squash(L1_N2, L1_N4));
	Neuron L2_N4(Squash(L1_N3, L1_N4));

	//LAYER THREE
	Neuron L3_N1(Squash(L2_N1, L2_N4));
	Neuron L3_N2(Squash(L2_N2, L2_N3));
	Neuron L3_N3(Squash(L2_N2, L2_N4));
	Neuron L3_N4(Squash(L2_N3, L2_N4));

	//LAYER FOUR
	Neuron L4_N1(Squash(L3_N1, L3_N2));
	Neuron L4_N2(Squash(L3_N1, L3_N3));
	Neuron L4_N3(Squash(L3_N2, L3_N4));
	Neuron L4_N4(Squash(L3_N3, L3_N4));

	Grid_4x4 testgrid;

	bool topLeft, bottomLeft, topRight, bottomRight;
	if (L4_N1.get_p_neuron_weight() < 0.5000) { topLeft = false; }
	else { topLeft = true; };
	if (L4_N2.get_p_neuron_weight() < 0.5000) {	bottomLeft = false;	}
	else { bottomLeft = true; };
	if (L4_N3.get_p_neuron_weight() < 0.5000) {	topRight= false; }
	else { topRight = true; };
	if (L4_N4.get_p_neuron_weight() < 0.5000) {	bottomRight = false; }
	else { bottomRight = true; };

	std::array<bool, 4> guess{topLeft, bottomLeft, topRight, bottomRight};

	if (guess == testgrid.sWhite) {
		std::cout << "This is correct!";
	}
	else
	{
		double error = 0.0;
		if (topLeft != testgrid.sWhite[0]) {
			error +=  
		}
	}

/*	std::cout << "LAYER 1:\n";
	std::cout << L1_N1.get_p_neuron_weight() << '\n';
	std::cout << L1_N2.get_p_neuron_weight() << '\n';
	std::cout << L1_N3.get_p_neuron_weight() << '\n';
	std::cout << L1_N4.get_p_neuron_weight() << '\n';

	std::cout << "LAYER 2:\n";
	std::cout << L2_N1.get_p_neuron_weight() << '\n';
	std::cout << L2_N2.get_p_neuron_weight() << '\n';
	std::cout << L2_N3.get_p_neuron_weight() << '\n';
	std::cout << L2_N4.get_p_neuron_weight() << '\n';
*/

	return 0;
};