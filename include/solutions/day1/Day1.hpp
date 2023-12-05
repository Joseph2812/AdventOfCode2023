#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../Day.hpp"
#include "WordMap.hpp"

namespace solutions {
	class Day1 : public Day {
	public:
		void print();

	private:
		int run(std::ifstream &fStream, WordMap &wordMap, bool part2);
		bool isNumber(char c);
	};
}