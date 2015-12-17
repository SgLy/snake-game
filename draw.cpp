#include <curses.h>

#include "draw.h"
#include "util.h"

void DrawInitialization() {
    initscr();
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
    for (int i = 0; i < t.height; ++i) {
        move(i, 0);
        for (int j = 0; j < t.width; ++j) {
            if (!t.map[HashXY(t.width, i, j)])
                addch(' ' | A_REVERSE);
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
        if (s.body[i + 1] - s.body[i] != s.body[i] - s.body[i - 1]) {
            addch('+' | A_BOLD);
            continue;
        }
        if (s.body[i] - s.body[i - 1] == SNAKE_GO[SNAKE_LEFT] || 
            s.body[i] - s.body[i - 1] == SNAKE_GO[SNAKE_RIGHT])
            addch('-' | A_BOLD);
        else
            addch('|' | A_BOLD);
    }

    // Draw tail
    move(s.body[s.body.size() - 1].x, s.body[s.body.size() - 1].y);
    if (s.body[s.body.size() - 1] - s.body[s.body.size() - 2] == SNAKE_GO[SNAKE_LEFT] || 
        s.body[s.body.size() - 1] - s.body[s.body.size() - 2] == SNAKE_GO[SNAKE_RIGHT])
        addch('-' | A_BOLD);
    else
        addch('|' | A_BOLD);
    refresh();
}

void DrawMessage(table t, char * a) {
    move(t.height, 2);
    printw(a);
    refresh();
}