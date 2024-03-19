#include "snake.h"
#include <iostream>
#include <Windows.h>
#include "../direction/direction.cpp"
#include "../map/map.cpp"
#include <deque>

class Snake : public Map
{
public:
	Direction head = Direction(5, 5, 'r');

	std::deque<Point> tails = {};
	int eatenAppleCount{0};
	bool isKilled = false;

	Snake(int initialLength = 3)
	{
		this->addApple();
		this->eatenAppleCount = 0;

		this->map[head.y][head.x] = Enums::MapObjects::Snake;
		for (int i = this->head.x - initialLength; i < this->head.x; i++)
		{
			Point z = { i,this->head.x };

			this->tails.push_back(z);
			this->map[z.y][z.x] = Enums::MapObjects::Snake;
		}
	};

	void move()
	{
		this->clear(this->head.x, this->head.y);


		if (this->head.side == 'u' ) {
			this->head.y--;
		}
		else if (this->head.side == 'd' ) {
			this->head.y++;
		}
		else if (this->head.side == 'l') {
			this->head.x--;
		}
		else if (this->head.side == 'r' ) {
			this->head.x++;
		}
		this->killed();

		this->eatApple();
		this->eatApple();
		this->map[this->head.y][this->head.x] = Enums::MapObjects::Snake;
		this->moveTail();
	}

	void changeDirection(char dir) {
		if (
			(dir == 'u' && this->head.side == 'd') ||
			(dir == 'l' && this->head.side == 'r') ||
			(dir == 'd' && this->head.side == 'w') ||
			(dir == 'r' && this->head.side == 'l')
			) {
			return;
		}
		else {
			this->head.side = dir;
		}
	}
	void moveTail() {
		for (int i = 0; i < this->tails.size(); i++) {
			this->clear(tails[i].x, tails[i].y);
		}

		this->tails.pop_front();
		Point tail = { this->head.x,this->head.y };
		this->tails.push_back(tail);
		for (int i = 0; i < this->tails.size(); i++) {
			this->map[tails[i].y][tails[i].x] = Enums::MapObjects::Snake;
		}
	}

	void addTail(int x, int y)
	{
		Point tail = { x, y };

	     this->tails.push_back(tail);
	}

	void addMoreTails(int count,int x ,int y) {
		for (int i = 0; i < count; i++) {
			this->addTail(x,y);
		}
	}

	void eatApple() {
		for (int i = 0; i < this->apples.size(); i++) {
			if (this->apples[i].x == this->head.x &&
				this->apples[i].y == this->head.y
				) {
				this->addApple();
				this->eatenAppleCount++;
				this->removeApple(this->apples[i].x, this->apples[i].y);

				Point lastE = this->tails.back();
				this->addMoreTails(10,lastE.x, lastE.y);

				break ;
			}
		}
		return ;
	}

	void killed() {
		if (map[this->head.y][this->head.x] == Enums::MapObjects::Wall ||
			map[this->head.y][this->head.x] == Enums::MapObjects::Snake
			) {
			this->isKilled = true;
		}
	}
};