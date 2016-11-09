tictactoe : main.o gamestate.o
	g++ -o tictactoe main.o gamestate.o
main.o : main.cpp
	g++ -c main.cpp
gamestate.o : gamestate.cpp gamestate.h
	g++ -c gamestate.cpp
clean : 
	rm *.o
realclean :
	rm *.o tictactoe results
