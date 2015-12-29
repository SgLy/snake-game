#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

#include "lib//draw.h"
#include "lib//table.h"
#include "lib//util.h"
#include "lib//ai.h"

int play(int num) {
    table t(60, 20);
    snake s(5, 5, 4, SNAKE_RIGHT);
    clear();
    move(0, 0);
    printw("#%d test running", num);
    refresh();

    while (true) {
        int aud = AutoDecide(t, s);
        if (aud == -1)
            aud = s.direction;
        s.ChangeDirection(aud);
        if (s.isEatApple(t)) {
            s.Forward(true);
            do {
                t.GenerateApple();
            } while (s.isCover(t.apple));
        } else {
            s.Forward(false);
        }
        if (s.isCrashTable(t) || s.isCrashSnake(s))
            return s.body.size() - 4;
    }
}

int main(int argc, char const *argv[])
{
    DrawInitialization();
    atexit(DrawFinalization);
    srand(time(0));


    clear();
    int n = 100;
    sscanf(argv[1], "%d", &n);
    int res = 0;
    for (int i = 0; i < n; ++i)
        res += play(i);
    FILE* f;
    f = fopen("ai_status.txt", "w");
    fprintf(f, "totally %d apples eaten in %d games\n", res, n);
    fprintf(f, "%.5f apples in average", double(res) / n);
    fclose(f);
    return 0;
}