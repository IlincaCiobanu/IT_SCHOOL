#pragma once
#ifndef PRINT_GRID_H
#define PRINT_GRID_H

void generateRandomSudoku(int grid[9][9], int difficulty);
void PrintHorizontalLines();
void PrintVerticalLines(int left, int middle, int right, int selectedCol);
void PrintSudokuGrid(int grid[9][9], int selectedRow, int selectedCol);

#endif // PRINT_GRID_H