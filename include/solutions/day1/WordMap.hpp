#pragma once

#include <unordered_map>
#include <iostream>

namespace solutions {
	class WordMap {
		struct MapLayer {
			std::unordered_map<char, MapLayer> CharToLayer = std::unordered_map<char, MapLayer>();
			char Result = '\0';
		};

	private:
		MapLayer _rootLayer = MapLayer();
		MapLayer* _currentLayer;

	public:
		WordMap(const char **words, const char *results, const int count);
		bool addNextChar(const char c, bool &success, char &result); // Returns: Whether char c matches
		void setToRoot(); // This will also be automatically called internally when a word is found, or letter doesn't fit a sequence.
	};
}