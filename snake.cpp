#include "snake.h"
#include <stdio.h>

int findDirection(point p) {
    for (int i = 0; i < 4; ++i)
        if (p == SNAKE_GO[i]) return i;
    return -1;
}

int InvertDirection(int dir) {
    if (dir == SNAKE_UP) return SNAKE_DOWN;
    if (dir == SNAKE_DOWN) return SNAKE_UP;
    if (dir == SNAKE_LEFT) return SNAKE_RIGHT;
    if (dir == SNAKE_RIGHT) return SNAKE_LEFT;
}

snake::snake () {
    direction = SNAKE_RIGHT;
    steps = 0;
    body.push_back(point(0, 0));
}

snake::snake (int x, int y, int len, int dir) {
    direction = dir;
    steps = 0;
    for (int i = 0; i < len; ++i) {
        x -= SNAKE_GO[dir].x;
        y -= SNAKE_GO[dir].y;
        body.push_back(point(x, y));
    }
}

void snake::Forward(bool grow) {
    steps++;
    body.push_front(point(body[0].x + SNAKE_GO[direction].x, body[0].y + SNAKE_GO[direction].y));
    if (!grow) body.pop_back();
}

snake snake::operator = (snake a) {
    snake c;
    c.direction = a.direction;
    c.body = a.body;
    return c;
}

void snake::ChangeDirection(int dir) {
    if (dir / 2 == direction / 2) return;
    direction = dir;
}

bool snake::isCrashTable(table t) {
    return !t.map[HashXY(t.width, body[0].x, body[0].y)];
}

bool snake::isCrashSnake(snake s) {
    int r = 0;
    if (body[1] == s.body[1]) r = 1;
    for (int i = r; i < s.body.size(); ++i)
        if (body[0].x == s.body[i].x && body[0].y == s.body[i].y) return true;
    return false;
}

bool snake::isEatApple(table &t) {
    point a = body[0] + SNAKE_GO[direction];
    return (body[0] + SNAKE_GO[direction] == t.apple);
}

bool snake::isCover(point p) {
    for (int i = 0; i < body.size(); ++i)
        if (body[i] == p) return true;
    return false;
}