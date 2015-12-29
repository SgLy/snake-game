#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

#include "draw.h"
#include "table.h"
#include "util.h"
#include "ai.h"

void EndGame() {
    clear();
    move(10, 20);
    printw("Thanks for your playing!");
    refresh();
    milliSleep(1500);
    exit(0);
}
 bool play() {
    int speed = 50;

    table t(60, 20);
    snake s(5, 5, 4, SNAKE_RIGHT);

    while (true) {
        DrawTable(t);

        char message[100];
        sprintf(message, "%d apples eaten.", s.body.size() - 4);
        DrawMessage(t.height + 1, message);
        sprintf(message, "Steps taken: %d step%c", s.steps, (s.steps == 1) ? ' ' : 's');
        DrawMessage(t.height + 2, message);
        sprintf(message, "Snake speed: %dms", speed);
        DrawMessage(t.height + 3, message);
        sprintf(message, "Apple position: (%d, %d)", t.apple.x, t.apple.y);
        DrawMessage(t.height + 4, message);
        DrawMessage(t.height + 6, "Auto playing, ws to adjust snake speed, d for default speed 50ms. q to quit."); 
        DrawSnake(s);
        timeout(speed);
        switch (getch()) {
            case 'w': {
                speed += 5;
                break;
            }
            case 's': {
                if (speed > 5)
                    speed -= 5;
                break;
            }
            case 'd': {
                speed = 50;
                break;
            }
            case 'q': EndGame();
        }
        timeout(1000);
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
    printw("AI mode. p to play and q to quit.");
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