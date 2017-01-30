# sudoku
This C++ program uses the stack data structure to solve any given soduku puzzle
- This program attempts to find the most restricted square on the board (one with fewest options that could go in it).
- It then tries on each option on the square and pushes the value, the row number, and column number on the stack
- If a particular option does not work, it pops out the value associating with its location on the board then tries on different values. This process is the backtracking process. 
