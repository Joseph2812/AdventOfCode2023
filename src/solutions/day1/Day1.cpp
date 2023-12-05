#include "../../../include/solutions/day1/Day1.hpp"

namespace solutions {
	void Day1::print() {
		std::ifstream fStream = std::ifstream("../../../inputs/Day1.txt");

		const char* words[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
		const char results[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		WordMap wordMap = WordMap(
			words,
			results,
			9
		);

		std::cout << "Part 1: " << run(fStream, wordMap, false) << std::endl;
		fStream.seekg(0);
		std::cout << "Part 2: " << run(fStream, wordMap, true) << std::endl;
	}

	int Day1::run(std::ifstream &fStream, WordMap &wordMap, bool part2) {
		int total = 0;
		std::string line;

		while (fStream.good()) {
			fStream >> line;

			char first = -1;
			char last = 0;
			int rootIdx = 0; // Scans each potential word starting from this index. Gradually moves along the characters.
			bool canUpdateRootIdx = true;

			for (int i = 0; i < line.length(); i++) {
				char c = line[i];

				if (isNumber(c)) {
					if (first == -1) { first = c; }
					last = c;

					rootIdx = i + 1;
					wordMap.setToRoot();				
				}
				else {
					if (!part2) { continue; }

					bool success;
					char result;
					if (wordMap.addNextChar(c, success, result)) {
						if (success) {
							if (first == -1) { first = result; }
							last = result;

							i = rootIdx++;
						}
						else if (canUpdateRootIdx) {
							canUpdateRootIdx = false;
							rootIdx = i;
						}
					}
					else if (!canUpdateRootIdx)
					{
						canUpdateRootIdx = true;
						i = rootIdx;
					}
				}
			}
			wordMap.setToRoot();
			total += std::stoi(std::string{ first, last });
		}
		return total;
	}

	bool Day1::isNumber(char c) { return c >= '0' && c <= '9'; }
}