LIB = draw.o snake.o util.o table.o
FLAG = -O2 -lcurses -Wall

snake-game: standard_game endless_game ai_game test_ai

standard_game: draw.o snake.o util.o table.o standard_game.cpp
	g++ $(LIB) standard_game.cpp -o standard_game $(FLAG)

endless_game: $(LIB) endless_game.cpp
	g++ $(LIB) endless_game.cpp -o endless_game $(FLAG)

ai_game: $(LIB) ai.o ai_game.cpp
	g++ $(LIB) ai.o ai_game.cpp -o ai_game $(FLAG)

test_ai: $(LIB) ai.o test_ai.cpp
	g++ $(LIB) ai.o test_ai.cpp -o test_ai $(FLAG)

draw.o: lib/draw.cpp lib/draw.h
	g++ -c lib/draw.cpp

snake.o: lib/snake.cpp lib/snake.h
	g++ -c lib/snake.cpp

util.o: lib/util.cpp lib/util.h
	g++ -c lib/util.cpp

table.o: lib/table.cpp lib/table.h
	g++ -c lib/table.cpp

ai.o: lib/ai.cpp lib/ai.h
	g++ -c lib/ai.cpp

clean:
	rm -f *.o *.gch standard_game endless_game ai_game test_ai
