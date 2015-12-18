#ifndef TABLE_INCLUDED
#define TABLE_INCLUDED

#include <vector>
#include "util.h"

class table {
public:
    int width, height;
    int cnt;
    point apple;
    std::vector<bool> map;
    table (int w, int h);
    void GenerateApple();
};

int HashXY(int width, int x, int y);

#endif