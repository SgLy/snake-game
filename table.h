#ifndef TABLE_INCLUDED
#define TABLE_INCLUDED

#include <vector>
#include "util.h"

class table {
public:
    int width, height;
    std::vector<bool> map;
    table (int w, int h);
};

int HashXY(int width, int x, int y);

#endif