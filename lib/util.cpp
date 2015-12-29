#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "util.h"

void milliSleep(int ms) {
    timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}

int random(int range) {
    return rand() % range;
}

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int CalcTime(int max_time, int min_time, int interval, int len) {
    int res = max_time - interval * (len - 4);
    res = max(min_time, res);
    return res;
}


bool operator == (const point a, const point b) {
    return a.x == b.x && a.y == b.y;
}

bool operator != (const point a, const point b) {
    return !(a == b);
}

point operator - (const point a) {
    return point(-a.x, -a.y);
}

point operator + (const point a, const point b) {
    return point(a.x + b.x, a.y + b.y);
}

point operator - (const point a, const point b) {
    return a + (-b);
}