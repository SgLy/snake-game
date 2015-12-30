#include <curses.h>
#include <time.h>
#include <stdlib.h>

#include "draw.h"
#include "snake.h"
#include "util.h"

#if defined linux
#define LLCORNER ACS_LLCORNER
#define ULCORNER ACS_ULCORNER
#define LRCORNER ACS_LRCORNER
#define URCORNER ACS_URCORNER
#define HLINE ACS_HLINE
#define VLINE ACS_VLINE
#endif

#if defined WIN32
#define LLCORNER '+'
#define ULCORNER '+'
#define LRCORNER '+'
#define URCORNER '+'
#define HLINE '-'
#define VLINE '|'
#endif

void DrawInitialization() {
    initscr();
    noecho();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();
    cbreak();
    curs_set(0);
    intrflush(stdscr, FALSE);
    keypad(stdscr, FALSE);
}

void DrawFinalization() {
    endwin();
}

void DrawTable(table t) {
    clear();
    for (int i = 0; i < t.height; ++i) {
        move(i, 0);
        for (int j = 0; j < t.width; ++j) {
            if (!t.map[HashXY(t.width, i, j)]) {
                addch(' ' | A_REVERSE);
            } else 
            if (i == t.apple.x && j == t.apple.y)
                addch('*' | A_BOLD);
            else
                addch(' ');
        }
    }
    refresh();
}

void DrawSnake(snake s) {
    // Draw head
    move(s.body[0].x, s.body[0].y);
    addch('o' | A_BOLD);

    // Draw other body
    for (int i = 1; i < s.body.size() - 1; ++i) {
        move(s.body[i].x, s.body[i].y);
        int a = findDirection(s.body[i] - s.body[i - 1]);
        int b = findDirection(s.body[i + 1] - s.body[i]);
        if (a != b) {
            if (a == 0) {
                if (b == 2)
                    addch(URCORNER | A_BOLD);
                if (b == 3)
                    addch(ULCORNER | A_BOLD);
            }
            if (a == 1) {
                if (b == 2)
                    addch(LRCORNER | A_BOLD);
                if (b == 3)
                    addch(LLCORNER | A_BOLD);
            }
            if (a == 2) {
                if (b == 0)
                    addch(LLCORNER | A_BOLD);
                if (b == 1)
                    addch(ULCORNER | A_BOLD);
            }
            if (a == 3) {
                if (b == 0)
                    addch(LRCORNER | A_BOLD);
                if (b == 1)
                    addch(URCORNER | A_BOLD);
            }
            continue;
        }
        if (a == SNAKE_LEFT || a == SNAKE_RIGHT)
            addch(HLINE | A_BOLD);
        if (a == SNAKE_UP || a == SNAKE_DOWN)
            addch(VLINE | A_BOLD);
    }

    // Draw tail
    move(s.body[s.body.size() - 1].x, s.body[s.body.size() - 1].y);
    if (s.body[s.body.size() - 1] - s.body[s.body.size() - 2] == SNAKE_GO[SNAKE_LEFT] || 
        s.body[s.body.size() - 1] - s.body[s.body.size() - 2] == SNAKE_GO[SNAKE_RIGHT])
        addch(HLINE | A_BOLD);
    else
        addch(VLINE | A_BOLD);
    refresh();
}

void DrawMessage(int line, const char a[]) {
    move(line, 2);
    printw(a);
    refresh();
}