# sudokusolver

Quick project that correctly solves a 9x9 sudoku puzzle. Explores all possible grids and narrows the search space using a simple heurstic. Although, it still is kind of fast. With g++/gcc-7.2.0 and the -O3 flag it takes 37.457 seconds to run "hard.txt" (a board with 21 known elements out of 81) 1000 times averaging 0.0375 seconds per run. Since our search space is so large any puzzles with less elements will take quite a long time. For a 17 element puzzle (hard2.txt - which I found on the wikipedia entry for sudoku solving) it takes approximately 54.931 seconds to run 1 time (~1460 times longer than our 21 element puzzle). 


Currently supports 9x9 grid in text format.

