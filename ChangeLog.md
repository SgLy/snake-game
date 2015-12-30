#### version 0.2.2
###### 2015-12-30

fixed a bug: when generating apple, apple will no longer appear under the snake.
allow compiling under windows:
1. get pdcurses;
2. modify all `-l curses` in `makefile` to `-l pdcurses`
3. `make` under cygwin.

<br\>
#### version 0.2.1
###### 2015-12-29

put all libraries in /lib

<br\>
#### version 0.2.0
###### 2015-12-29

add an simple AI, which can eat 89 apples in a 60 * 20 map in average.
`ai_game` to watch AI move, and `test_ai` to test the strength of the AI.
`make ai_game` and `make test_ai` to compile them respectively

<br\>
#### version 0.1.0
###### 2015-12-20

makefile done. Now you can use `make` to compile.
`make standard_game` and `make endless_game` can compile the 2 mode respectively.

<br\>
#### version 0.0.1
###### 2015-12-18
`g++ *.cpp -o normal_game -l curses` to compile

`./normal_game` to run

Now it contains a normal mode. Use WASD to control the snake. More details please follow the instructions in the game.

<br\>
#### version 0.0.0
###### 2015-12-18
`g++ *.cpp -o test -l curses` to compile

`./test` to run