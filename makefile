allmode: standard_game endless_game

standard_game: draw.o snake.o util.o table.o standard_game.cpp
	g++ draw.o snake.o util.o table.o standard_game.cpp \
	-o standard_game -l curses

endless_game: draw.o snake.o util.o table.o endless_game.cpp
	g++ draw.o snake.o util.o table.o endless_game.cpp \
	-o endless_game -l curses

draw.o: draw.cpp draw.h
	g++ -c draw.cpp draw.h

snake.o: snake.cpp snake.h
	g++ -c snake.cpp snake.h

util.o: util.cpp util.h
	g++ -c util.cpp util.h

table.o: table.cpp table.h
	g++ -c table.cpp table.h

clean:
	rm -f *.o *.gch standard_game endless_game