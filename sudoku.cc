/****************************************************
 *                                                  *
 * File name: sudoku.cc                             *
 * Name: Minh To                                    *
 * Assignment: sudoku                               *
 * Date: 09/30/15                                   *
 *                                                  *
 * This program reads in a board and solves the     *
 * puzzle. The solution gets printed.               *
 *                                                  *
 ***************************************************/

#include "sudokuboard.h"
#include <iostream>
#include "stack.h"

using namespace std;

//-bool mostConstrained (sudokuboard & board, size_t  & row, size_t & col)
// PRE:  row >= 0 and col >= 0, board has been initialized
// POST: The function returns true if there exists a most constrained space.
//       It checks every space if a number from 1 to 9 can be 
//       placed there and finds the location with the fewest options. The 
//       location is then changed and passed through the parameter. The 
//       function returns false when there is a no number can be placed in 
//       an empty space.
bool mostConstrained (sudokuboard & board, size_t  & row, size_t & col)
{
  size_t count = 0; //count of possible solutions at a location
  size_t constraint = 9; //number of solutions in the most constrained space
  //loop through board
  for (size_t r = 0; r < 9; r++) {
    for (size_t c = 0; c < 9; c++) {
      if (board.get(r, c) == '_') {
	for (char choice = '1'; choice <= '9'; choice++) {
	  if (board.canPlace(r, c, choice)) {
	    count++;
	  }
	}
	if (count < constraint) {
	  constraint = count; //set constraint to the fewest options
	  row = r;
	  col = c;
	}
	count = 0;
      } 
    }  
  }
  return (constraint > 0);
}

//-bool find_first(sudokuboard & board, size_t row, size_t col, char & num)
// PRE: row >= 0 and col >= 0, board has been initialized
// POST: This function finds the first number that can be placed in a 
//       given space and stores in variable num. It returns true when 
//       it can find a first number to place, false otherwise.
bool find_first(sudokuboard & board, size_t row, size_t col, char & num)
{
  for (char i = '1'; i <= '9'; i++) {
    if (board.canPlace(row, col, i)){
      num = i;
      return true;
    }
  }
  return false;
}

//-bool find_next(sudokuboard & board, size_t row, size_t col, char & num)
// PRE: row >= 0 and col >= 0, board has been initialized
// POST: This function finds the next number between the last acceptable 
//       number and 9 that can be placed in a space, given a location
//       and stores the value in num. It returns true when it can find the
//       next number, false otherwise.
bool find_next(sudokuboard & board, size_t row, size_t col, char & num)
{
  for (char i = num + 1; i <= '9'; i++) {
    if (board.canPlace(row, col, i)){
      num = i;
      return true;
    }
  }
  return false;
}

//-void backtrack(sudokuboard & board, stack & s) 
// PRE: board and s have been declared.
// POST: This function traces back the steps that lead to a wrong solution.
//       It keeps backtracking until the first step or until it finds a space
//       where the wrong solution starts and places it with a different possible
//       option.
void backtrack(sudokuboard & board, stack & s) 
{
  if (s.empty()){
    return;
  }
  size_t col;
  size_t row;
  char num;
  while (not s.empty()) {
    col = s.top(); //column value of the last position
    s.pop();
    row = s.top(); //row value of the last position
    s.pop();
    num = board.get(row, col);//value in the last position
    board.remove(row, col);
    if (find_next(board, row, col, num)) {
      board.place(row, col, num);
      s.push(row);
      s.push(col);
      return;
    }
  }
}

//-void solve_sudoku(sudokuboard & board, stack & s)
// PRE: board and stack have been declared.
// POST: This function solves the sudokuboard by repeatedly determining if the
//       most constrained space exists in the board. Starting from that 
//       location, it places a the first option possible at each position and 
//       remembers the locations. If the current solution does not work, it 
//       traces back the steps until the board is solved.
void solve_sudoku(sudokuboard & board, stack & s)
{
  while (not board.solved()) {
    size_t row = 0;
    size_t col = 0;
    char num ='1';
    //place number in a location
    if (mostConstrained(board, row, col)) {
      if (find_first(board, row, col, num)) {
	board.place(row, col, num);
	s.push(row);
	s.push(col);
      }
    }
    //BACKTRACK
    else 
      backtrack(board, s);
  }
}

int main()
{
  stack s; //s stores rows and columns for backtracking
  sudokuboard board;
  board._init(); //input a board
  solve_sudoku(board, s); //solve sudoku
  if (board.solved())
    board.print();
}