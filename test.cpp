#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "draw.h"
#include "table.h"
#include "util.h"

int main() {
    DrawInitialization();
    atexit(DrawFinalization);

    table t(60, 20);
    snake s(5, 5, 3, SNAKE_RIGHT);
    while (true) {
        DrawTable(t);
        DrawMessage(t, "A dirty test.\n  wasd to move, l to grow, q to quit.\n  Crash detection not coded yet.");
        DrawSnake(s);
        bool grow = false;
        bool quit = false;
        switch (getch()) {
            case 'w': s.ChangeDirection(0); break;
            case 's': s.ChangeDirection(1); break;
            case 'a': s.ChangeDirection(2); break;
            case 'd': s.ChangeDirection(3); break;
            case 'l': grow = true; break;
            case 'q': quit = true;
        }
        if (quit) break;
        s.Forward(grow);
    }

    return 0;
}