#include "../../../include/solutions/day2/Day2.hpp"

namespace solutions {
	Day2::CubeData::CubeData(const Day2::Colour colour, const int amount) {
		Colour = colour;
		Amount = amount;
	}

	void Day2::print() {
		std::ifstream fStream = std::ifstream("../../../inputs/Day2.txt");
		std::string line;

		int possibleTotal = 0;
		int powerTotal = 0;
		int lineIdx = 0;

		while (std::getline(fStream, line)) {
			lineIdx++;		

			bool isAboveLimits = false;
			int maxRed = 0;
			int maxGreen = 0;
			int maxBlue = 0;

			for (int i = line.find(':') + 2; i < line.length(); i += 2) {
				CubeData cubeData = parse(line, i);
				
				// Check For New Colour Maximum //
				switch (cubeData.Colour) {
				case Colour::Red:
					if (cubeData.Amount > maxRed) { maxRed = cubeData.Amount; }
					break;

				case Colour::Green:
					if (cubeData.Amount > maxGreen) { maxGreen = cubeData.Amount; }
					break;

				case Colour::Blue:
					if (cubeData.Amount > maxBlue) { maxBlue = cubeData.Amount; }
					break;
				}
				//

				isAboveLimits |= aboveLimits(cubeData);
			}
			if (!isAboveLimits) { possibleTotal += lineIdx; }
			powerTotal += maxRed * maxGreen * maxBlue;
		}

		std::cout << "Part 1: " << possibleTotal << std::endl;
		std::cout << "Part 2: " << powerTotal << std::endl;
	}

	Day2::CubeData Day2::parse(const std::string &str, int &i) {
		std::stringstream val;
		std::stringstream colour;

		for (; i < str.length(); i++) {
			if (str[i] == ' ') { break; }

			val << str[i];
		}
		for (++i; i < str.length(); i++) {
			if (str[i] == ' ' || str[i] == ',' || str[i] == ';') { break; }

			colour << str[i];
		}

		return CubeData(getColour(colour.str()), std::stoi(val.str()));
	}

	bool Day2::aboveLimits(const CubeData &cubeData) {
		if (cubeData.Colour == Colour::Red)   { return cubeData.Amount > 12; }
		if (cubeData.Colour == Colour::Green) { return cubeData.Amount > 13; }
		if (cubeData.Colour == Colour::Blue)  { return cubeData.Amount > 14; }

		return false;
	}

	Day2::Colour Day2::getColour(const std::string &str) {
		if (str == "red")   { return Colour::Red; }
		if (str == "blue")  { return Colour::Blue; }
		if (str == "green") { return Colour::Green; }

		throw std::invalid_argument(std::format("\"{}\" is not a defined colour", str));
	}
}