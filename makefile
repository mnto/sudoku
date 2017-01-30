sudoku: sudoku.o sudokuboard.o stack.o
	g++ -o sudoku sudoku.o sudokuboard.o stack.o

sudoku.o: sudoku.cc 
	g++ -c sudoku.cc 

sudokuboard.o: sudokuboard.cc 
	g++ -c sudokuboard.cc 

stack.o: stack.cc stack.h
	g++ -c stack.cc 