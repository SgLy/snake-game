#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

#include "lib//draw.h"
#include "lib//table.h"
#include "lib//util.h"

void EndGame() {
    clear();
    move(10, 20);
    printw("Thanks for your playing!");
    refresh();
    milliSleep(1500);
    exit(0);
}

bool play() {
    int max_time = 1000;
    int min_time = 50;
    int interval = 50;

    table t(60, 20);
    snake s(5, 5, 4, SNAKE_RIGHT);

    while (true) {
        int speed = CalcTime(max_time, min_time, interval, s.body.size());
        timeout(speed);
        DrawTable(t);

        char message[100];
        sprintf(message, "%lu apples eaten.", s.body.size() - 4);
        DrawMessage(t.height + 1, message);
        sprintf(message, "Steps taken: %d step%c", s.steps, (s.steps == 1) ? ' ' : 's');
        DrawMessage(t.height + 2, message);
        sprintf(message, "Snake speed: %dms", speed);
        DrawMessage(t.height + 3, message);
        sprintf(message, "Apple position: (%d, %d)", t.apple.x, t.apple.y);
        DrawMessage(t.height + 4, message);
        DrawMessage(t.height + 6, "wasd to move, q to quit."); 
        DrawSnake(s);
        switch (getch()) {
            case 'w': s.ChangeDirection(0); break;
            case 's': s.ChangeDirection(1); break;
            case 'a': s.ChangeDirection(2); break;
            case 'd': s.ChangeDirection(3); break;
            case 'q': EndGame();
        }
        if (s.isEatApple(t)) {
            s.Forward(true);
            do {
                t.GenerateApple();
            } while (s.isCover(t.apple));
        } else {
            s.Forward(false);
        }
        if (s.isCrashTable(t)) {
            DrawMessage(t.height + 2, "You crash the board!                 ");
            milliSleep(2000);
            return false;
        }
        if (s.isCrashSnake(s)) {
            DrawMessage(t.height + 2, "You crash yourself!                  ");
            milliSleep(2000);
            return false;
        }
    }
}

int main() {
    DrawInitialization();
    atexit(DrawFinalization);
    srand(time(0));


    clear();
    move(10, 20);
    printw("Endless mode. p to play and q to quit.");
    refresh();
    while (true) {
        char ch = getch();
        if (ch == 'q') EndGame();
        if (ch == 'p') break;
    }
    play();
    EndGame();
    return 0;
}
