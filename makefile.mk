a.exe: sudoku.o sudokuserv.o
	gcc sudoku.o sudokuserv.o
sudoku.o: sudoku.c sheader.h
	gcc -c sudoku.c
sudokuserv.o: sudokuserv.c sheader.h
	gcc -c sudokuserv.c