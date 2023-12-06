#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <sstream>
#include "../Day.hpp"

namespace solutions {
	class Day2 : public Day {
	private:
		enum Colour {
			Red,
			Green,
			Blue
		};

		struct CubeData {
			Colour Colour;
			int Amount;

			CubeData(const Day2::Colour colour, const int amount);
		};
	
	public:
		void print();

	private:
		CubeData parse(const std::string &str, int &i);
		bool aboveLimits(const CubeData &cubeData);
		Colour getColour(const std::string &str);
	};
}