#ifdef SNAKE_H
#define SNAKE_H

#include <iostream>
#include "../map/map.h"
#include "../enums/enums.cpp"

class Snake
{
public:
    Direction head ;

    std::deque<Point> tails ;
    int eatenAppleCount;
    bool isKilled ;

    Snake(int initialLength);

public:
    void addTail(int x, int y);

    void move();

    void changeDirection(char dir);

    void moveTail();

    void addTail(int x, int y);

    void addMoreTails(int count, int x, int y);

    void eatApple();

    void killed();
};

#endif // SNAKE_H