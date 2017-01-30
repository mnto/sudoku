#include "sudokuboard.h"
#include <iostream>

// class sudokuboard.cc implenments the methods in sudokuboard.h

sudokuboard::sudokuboard()
{
  //construct an empty board
  _size = 9;
  for (size_t i = 0; i < _size; i++){
    _board[i] = "__________";
  }
}

void sudokuboard::_init()
{
  //input and construct a board
  string row = "";
  for (size_t r = 0; r < 9; r++) {
    cin >> row;
    _board[r] = row;
  }
}
void sudokuboard::print() const
{
  for (size_t i = 0; i < _size; i++){
    std::cout << _board[i] << endl;
  }
}

void sudokuboard::place(size_t r, size_t c, char n)
{
  _board[r][c] = n; ;
}

int sudokuboard::get(size_t r, size_t c) const
{
  return _board[r][c];
}

void sudokuboard::remove(size_t r, size_t c)
{
  _board[r][c] = '_';
}

bool sudokuboard::canPlace (size_t r, size_t c, char n) const
{
  size_t top_row = r/3*3; //top left row value
  size_t top_col = c/3*3; //top left column value
  if (get(r, c) == '_') {
    for (size_t row = 0; row < _size; row++) { //check if n is in column
      if (get(row,c) == n){
	return false;
      }
    }
    for (size_t col = 0; col < _size; col++) { //check if n is in row 
      if (get(r,col) == n){
	return false;
      }
    }
    for (size_t row = top_row; row < top_row + 3; row++) { // check if n is in square
      for (size_t col = top_col; col < top_col + 3; col++) {
	if (get(row, col) == n){
	  return false;
	}
      }
    }
    return true;
  }
  else
    return false;
}

bool sudokuboard::solved() const
{
  for (size_t r = 0; r < _size; r++) {
    for (size_t c = 0; c < _size; c++) {
      if (_board[r][c] == '_')
	return false;
    }
  }
  return true;	
}

    
