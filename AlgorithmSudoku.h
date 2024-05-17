#pragma once
#ifndef ALGORITHM_SUDOKU_H
#define ALGORITHM_SUDOKU_H

bool isSafe(int grid[9][9], int row, int col, int num);
bool solveSudoku(int grid[9][9]);
void generateRandomSudoku(int grid[9][9], int difficulty);
bool checkSudoku(int grid[9][9]);
void fillDiagonal(int grid[9][9]);

#endif // ALGORITHM_SUDOKU_H