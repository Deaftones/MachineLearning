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
#include "bitmap_image.hpp"


int main()
{
	const std::string file = "penguin.bmp";
	bitmap_image testing(file);
	testing.rgb_to_bgr();
	testing.save_image("penguintest.bmp");


	//Maps abc(7, 7);
	//abc.CreateMap();
	//abc.PrintMapsVector();
	
	
	return 0;
}