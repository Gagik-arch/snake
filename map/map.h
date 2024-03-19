#ifdef MAP_H
#define MAP_H

class Map
{

private:
      int width ;
      int height ;

public:
    char map[height][width];
    std::deque<Point>apples = {};


public:
    Map();

public:
    void update();

    void clear(int x, int y);
    int getMapWidth();
    void addApple();
    void removeApple(int x, int y);
};

#endif // MAP_H
