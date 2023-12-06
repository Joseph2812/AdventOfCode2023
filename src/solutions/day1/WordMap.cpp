#include "../../../include/solutions/day1/WordMap.hpp"

namespace solutions {
	WordMap::WordMap(const char **words, const char *results, const int count) {
		setToRoot();

		for (int i = 0; i < count; i++) {
			MapLayer* layer = &_rootLayer;

			for (const char* p = words[i]; *p != '\0'; p++) {
				if (!(*layer).CharToLayer.contains(*p)) {
					(*layer).CharToLayer[*p] = MapLayer();
				}
				layer = &(*layer).CharToLayer[*p];
			}
			(*layer).Result = results[i];
		}	
	}

	bool WordMap::addNextChar(const char c, bool &success, char &result) {
		success = false;
		
		if ((*_currentLayer).CharToLayer.contains(c)) {
			_currentLayer = &(*_currentLayer).CharToLayer[c];

			if ((*_currentLayer).Result != '\0') {
				result = (*_currentLayer).Result;
				setToRoot();

				success = true;
			}
			return true;
		}
		setToRoot();
		return false;
	}

	void WordMap::setToRoot() { _currentLayer = &_rootLayer; }
}