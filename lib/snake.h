#ifndef SNAKE_INCLUDED
#define SNAKE_INCLUDED

#include <deque>
#include "table.h"
#include "util.h"

const int SNAKE_UP = 0;
const int SNAKE_DOWN = 1;
const int SNAKE_LEFT = 2;
const int SNAKE_RIGHT = 3;

const point SNAKE_GO[4] = {point(-1, 0), point(1, 0), point(0, -1), point(0, 1)};

int findDirection(point p);
int InvertDirection(int dir);

class snake {
public:
    int direction, steps;
    std::deque<point> body;
    snake();
    snake(int x, int y, int len, int dir);
    snake operator = (snake a);
    void Forward(bool grow);
    void ChangeDirection(int dir);
    bool isCrashTable(table t);
    bool isCrashSnake(snake s);
    bool isEatApple(table &t);
    bool isFakeEatApple(table &t);
    bool isCover(point p);
};


#endif