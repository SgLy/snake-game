#include "table.h"

int HashXY(int width, int x, int y) {
    return x * width + y;
}

table::table (int w, int h){
    width = w;
    height = h;
    for (int i = 0; i < w * h; ++i)
        map.push_back(true);
    for (int i = 0; i < h; ++i) {
        map[HashXY(w, i, 0)] = false;
        map[HashXY(w, i, w - 1)] = false;
    }
    for (int i = 0; i < w; ++i) {
        map[HashXY(w, 0, i)] = false;
        map[HashXY(w, h - 1, i)] = false;
    }
    GenerateApple();
}

void table::GenerateApple() {
    apple = point(random(20) + 1, random(20) + 1);
}