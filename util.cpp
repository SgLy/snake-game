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