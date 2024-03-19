#pragma once
#include "map.h"
#include <iostream>
#include "../enums/enums.cpp"
#include "../utils.cpp"
#include <deque>
#include "../point/point.cpp"

class Map
{
private:
	static const int width = 40;
	static const int height = 20;

public:
	char map[height][width];
	std::deque<Point>apples = {};

	Map()
	{
		for (int r = 0; r < this->height; r++)
		{
			for (int c = 0; c < this->width; c++)
			{
				if (
					(r == 0 || r == this->height - 1) ||
					(c == 0 || c == this->width - 1))
				{
					this->map[r][c] = Enums::MapObjects::Wall;
				}
				else
				{
					this->map[r][c] = Enums::MapObjects::Clear;
				}
			}
		}
	};

	void update()
	{
		for (int r = 0; r < this->height; r++)
		{
			for (int c = 0; c < this->width; c++)
			{
				std::cout << this->map[r][c];
			}
			std::cout << std::endl;
		}
	};

	void clear(int x, int y) {
		this->map[y][x] = Enums::MapObjects::Clear;
	}

	int getMapWidth() {
		return this->width;
	}

	int getMapHeight() {
		return this->height;
	}

	void addApple() {
		int x = random(2, this->width - 2);
		int y = random(2, this->height - 2);

		Point a = {x,y};
		this->apples.push_back(a);

		this->map[y][x] = Enums::MapObjects::Apple;
	}

	void removeApple(int x, int y) {
		for (int i = 0; i < this->apples.size(); i++) {
			if (this->apples[i].x == x && this->apples[i].y == y) {
				this->apples.erase(this->apples.begin(),this->apples.begin()+ (i+1));
			}
		}
	}
};
