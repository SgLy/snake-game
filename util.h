#ifndef UTIL_INCLUDED
#define UTIL_INCLUDED

#include <map>

void milliSleep(int ms);

struct point {
    int x, y;
    point () : x(0), y(0) {}
    point (int xx, int yy) : x(xx), y(yy) {}
};

bool operator == (const point a, const point b);
bool operator != (const point a, const point b);
point operator - (const point a);
point operator + (const point a, const point b);
point operator - (const point a, const point b);

#endif