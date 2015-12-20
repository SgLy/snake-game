#include "snake.h"
#include <stdio.h>

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
    bool res = (body[0] + SNAKE_GO[direction] == t.apple);
    if (res) do {
        t.GenerateApple();
    } while (isCover(t.apple));
    return res;
}

bool snake::isCover(point p) {
    for (int i = 0; i < body.size(); ++i)
        if (body[i] == p) return true;
    return false;
}