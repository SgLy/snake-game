#ifndef SNAKE_INCLUDED
#define SNAKE_INCLUDED

#include <deque>
#include "util.h"

const int SNAKE_UP = 0;
const int SNAKE_DOWN = 1;
const int SNAKE_LEFT = 2;
const int SNAKE_RIGHT = 3;

const point SNAKE_GO[4] = {point(-1, 0), point(1, 0), point(0, -1), point(0, 1)};

class snake {
public:
    int direction;
    point head;
    std::deque<point> body;
    snake(int x, int y, int len, int dir);
    void Forward(bool grow);
    void ChangeDirection(int dir);
};

#endif