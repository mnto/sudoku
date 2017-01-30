#include <cstdlib>
#include <string>

using namespace std;

// class sudokuboard provides a design for the board 9 x 9
// Each space has location (row, column), in which 0 <= row <= 8 
// and 0 <= col <= 8, and either holds a number from 1 to 9 or is empty

class sudokuboard
{

 public:
  //-sudokuboard()------------------------------------------------
  sudokuboard();
  // Constructor: constructs an empty 9x9 board of 9 string arrays

  //-void_init()--------------------------------------------------
  void _init();
  // POST: read in and construct a board of 9 string arrays
  //--------------------------------------------------------------

  //-void(place(size_t r, size_t c, char n)-----------------------
  void place(size_t r, size_t c, char n);
  // PRE: r >= 0, c >= 0, and '1' <= n <= '9'
  // POST: place character n in location (r, c)
  //--------------------------------------------------------------

  //-void print() const-------------------------------------------
  void print() const;
  // POST: print out board
  //--------------------------------------------------------------

  //-int get(size_t r, size_t c) const----------------------------
  int get(size_t r, size_t c) const;
  // PRE: r >= 0, c >= 0
  // POST: return the numeral at position (r, c)
  //--------------------------------------------------------------

  //-void remove(size_t r, size_t c)------------------------------
  void remove(size_t r, size_t c);
  // PRE: r >= 0, c >= 0
  // POST: remove the numberal at position (r, c)
  //--------------------------------------------------------------

  //-canPlace(size_t r, size_t c, char n) const-------------------
  bool canPlace(size_t r, size_t c, char n) const;
  // PRE: r >= 0, c >= 0, '1' <= n <= '9'
  // POST: true iff the board would allow placing n at (r, c)
  //--------------------------------------------------------------

  //-bool solved() const------------------------------------------
  bool solved() const;
  // POST: true iff there are no blank spots on the board
  //--------------------------------------------------------------

 private:
  sudokuboard(const sudokuboard &);
  string _board[9];
  size_t _size;
  char _data;
};