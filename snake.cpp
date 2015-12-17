#include "snake.h"

snake::snake (int x, int y, int len, int dir) {
    direction = dir;
    head.x = x;
    head.y = y;
    for (int i = 0; i < len; ++i) {
        x -= SNAKE_GO[dir].x;
        y -= SNAKE_GO[dir].y;
        body.push_back(point(x, y));
    }
}

void snake::Forward(bool grow) {
    body.push_front(point(body[0].x + SNAKE_GO[direction].x, body[0].y + SNAKE_GO[direction].y));
    if (!grow) body.pop_back();
}

void snake::ChangeDirection(int dir) {
    if (dir / 2 == direction / 2) return;
    direction = dir;
}