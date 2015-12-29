#include "ai.h"
#include "util.h"

#include <string.h>
#include <queue>

struct rec {
    point p;
    int dir, dep;
    rec() {
        p = point();
        dir = 0;
        dep = 0;
    }
    rec(point init_p) {
        p = init_p;
        dir = 0;
        dep = 0;

    }
    rec(point init_p, int init_dir, int init_dep) {
        p = init_p;
        dir = init_dir;
        dep = init_dep;
    }
};

int FindRoute(int h, int w, bool map[], point src, point dest, int &dist) {
    std::queue<rec> q;
    q.push(rec(src));
    bool f[h * w];
    memset(f, true, sizeof(f));
    rec head, tail;
    point pt;
    int res = -1;
    dist = 0;

    while (!q.empty()) {
        head = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            pt = head.p + SNAKE_GO[i];
            if (pt.x < 0 || pt.x >= h) continue;
            if (pt.y < 0 || pt.y >= w) continue;
            if (!map[HashXY(w, pt.x, pt.y)]) continue;
            if (!f[HashXY(w, pt.x, pt.y)]) continue;
            dist++;
            if (head.p == src)
                tail = rec(pt, i, head.dep + 1);
            else
                tail = rec(pt, head.dir, head.dep + 1);
            q.push(tail);
            f[HashXY(w, pt.x, pt.y)] = false;
            if (tail.p == dest) {
                f[HashXY(w, pt.x, pt.y)] = true;
                return tail.dir;
            }
        }
    }
    return res;
}

int ChaseApple(table t, snake s) {
    bool m[t.height * t.width];
    for (int i = 0; i < t.height * t.width; ++i)
        m[i] = t.map[i];
    for (int i = 0; i < s.body.size(); ++i)
        m[HashXY(t.width, s.body[i].x, s.body[i].y)] = false;
    int tmp;
    return FindRoute(t.height, t.width, m, s.body[0], t.apple, tmp);
}

int ChaseTail(table t, snake s) {
    bool m[t.height * t.width];
    for (int i = 0; i < t.height * t.width; ++i)
        m[i] = t.map[i];
    for (int i = 0; i < s.body.size() - 1; ++i)
        m[HashXY(t.width, s.body[i].x, s.body[i].y)] = false;
    point tail = s.body[s.body.size() - 1];
    int d;
    int res = FindRoute(t.height, t.width, m, s.body[0], tail, d);
    if (d > s.body.size()) return ChaseApple(t, s);
    return res;
}

int AutoDecide(table t, snake s) {
    // chase its tail if no way to the apple
    int tmp = ChaseApple(t, s);
    if (tmp == -1) 
        return ChaseTail(t, s);
    // use a fake snake "a" to test if move towards the apple
    //   will crash itself
    snake a = s;
    a.ChangeDirection(tmp);
    a.Forward(a.isEatApple(t));
    // to be solve:
    // how to judge if a snake will die after eating the apple
    if (ChaseTail(t, a) == -1)
        return ChaseTail(t, s);
    else
        return ChaseApple(t, s);
}