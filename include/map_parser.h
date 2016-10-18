#pragma once
#include <standard_includes.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

struct Map{

	int size_x;
	int size_y;
	int res;
	int grid_size;
	std::vector<std::vector<double>> grid;
};

class MapParser{

public:

	MapParser(std::string filename);
	void readMap(std::string file);
	void printMap();
	void displayMap();
	void getMap(Map* map);

private:

	Map *map_;

};