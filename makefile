snake-game: standard_game endless_game ai_game test_ai

standard_game: draw.o snake.o util.o table.o standard_game.cpp
	g++ draw.o snake.o util.o table.o standard_game.cpp \
	-o standard_game -l pdcurses

endless_game: draw.o snake.o util.o table.o endless_game.cpp
	g++ draw.o snake.o util.o table.o endless_game.cpp \
	-o endless_game -l pdcurses

ai_game: draw.o snake.o util.o table.o ai.o ai_game.cpp
	g++ draw.o snake.o util.o table.o ai.o ai_game.cpp \
	-o ai_game -l pdcurses

test_ai: draw.o snake.o util.o table.o ai.o test_ai.cpp
	g++ draw.o snake.o util.o table.o ai.o test_ai.cpp \
	-o test_ai -l pdcurses

draw.o: lib//draw.cpp lib//draw.h
	g++ -c lib//draw.cpp

snake.o: lib//snake.cpp lib//snake.h
	g++ -c lib//snake.cpp

util.o: lib//util.cpp lib//util.h
	g++ -c lib//util.cpp

table.o: lib//table.cpp lib//table.h
	g++ -c lib//table.cpp

ai.o: lib//ai.cpp lib//ai.h
	g++ -c lib//ai.cpp

clean:
	rm -f *.o *.gch standard_game endless_game ai_game test_ai