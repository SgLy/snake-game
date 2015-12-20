#ifndef DRAW_INCLUDED
#define DRAW_INCLUDED

#include "table.h"
#include "snake.h"

void DrawInitialization();
void DrawFinalization();
void DrawTable(table t);
void DrawSnake(snake s);
void DrawMessage(int line, const char a[]);

#endif