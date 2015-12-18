#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

#include "draw.h"
#include "table.h"
#include "util.h"

void EndGame() {
    clear();
    move(10, 20);
    printw("Thanks for your playing!");
    refresh();
    milliSleep(2000);
    exit(0);
}

int main() {
    DrawInitialization();
    atexit(DrawFinalization);
    srand(time(0));

    table t(80, 25);
    snake s(5, 5, 4, SNAKE_RIGHT);
    DrawMessage(t, "Normal Mode.\n  p to play, q to quit.");
    while (true) {
        char ch = getch();
        if (ch == 'q') EndGame();
        if (ch == 'p') break;
    }
    while (true) {
        timeout(CalcTime(500, 100, 50, s.body.size()));
        DrawTable(t);
        char message[100];
        sprintf(message, "%d apples eaten. Snake speed: %dms\n    wasd to move, q to quit.", s.body.size() - 4, CalcTime(500, 100, 50, s.body.size()));
        DrawMessage(t, message);
        DrawSnake(s);
        switch (getch()) {
            case 'w': s.ChangeDirection(0); break;
            case 's': s.ChangeDirection(1); break;
            case 'a': s.ChangeDirection(2); break;
            case 'd': s.ChangeDirection(3); break;
            case 'q': EndGame();
        }
        s.Forward(s.isEatApple(t));
        if (s.isCrashTable(t)) {
            DrawMessage(t, "You crash the board!");
            milliSleep(2000);
            EndGame();
        }
        if (s.isCrashSnake(s)) {
            DrawMessage(t, "You crash yourself!");
            milliSleep(2000);
            EndGame();
        }
    }
    return 0;
}