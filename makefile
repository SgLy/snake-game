snake-game: standard_game endless_game ai_game test_ai

standard_game: draw.o snake.o util.o table.o standard_game.cpp
	g++ draw.o snake.o util.o table.o standard_game.cpp \
	-o standard_game -l curses

endless_game: draw.o snake.o util.o table.o endless_game.cpp
	g++ draw.o snake.o util.o table.o endless_game.cpp \
	-o endless_game -l curses

ai_game: draw.o snake.o util.o table.o ai.o ai_game.cpp
	g++ draw.o snake.o util.o table.o ai.o ai_game.cpp \
	-o ai_game -l curses

test_ai: draw.o snake.o util.o table.o ai.o test_ai.cpp
	g++ draw.o snake.o util.o table.o ai.o test_ai.cpp \
	-o test_ai -l curses

clean:
	rm -f *.o *.gch standard_game endless_game ai_game test_ai