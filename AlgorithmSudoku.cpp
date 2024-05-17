#include "AlgorithmSudoku.h"
#include <iostream>
#include <iomanip>

bool isSafe(int grid[9][9], int row, int col, int num)
{
    for (int i = 0; i < 9; ++i) 
    {
        if (grid[row][i] == num || grid[i][col] == num || grid[row - row % 3 + i / 3][col - col % 3 + i % 3] == num)
            return false;
    }
    return true;
}

bool solveSudoku(int grid[9][9])
{
    int row, col;
    bool isEmpty = false; 
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
            break;
    }
    if (!isEmpty)
        return true;

    for (int num = 1; num <= 9; ++num) 
    {
        if (isSafe(grid, row, col, num)) 
        {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void fillDiagonal(int grid[9][9])
{
    for (int i = 0; i < 9; i += 3)
    {
        bool used[10] = { false };
        for (int row = i; row < i + 3; ++row)
        {
            for (int col = i; col < i + 3; ++col)
            {
                int num;
                do 
                {
                    num = rand() % 9 + 1;
                } while (used[num]);
                used[num] = true;
                grid[row][col] = num;
            }
        }
    }
}

bool checkSudoku(int grid[9][9])
{
    bool used[9];
    //check row
    for (int i = 0; i < 9; ++i)
    {
        std::fill(used, used + 9, false);
        for (int j = 0; j < 9; ++j)
        {
            if (grid[i][j] == 0 || used[grid[i][j] - 1])
            {
                return false;
            }
            used[grid[i][j] - 1] = true;
        }
    }
    //check column
    for (int j = 0; j < 9; ++j)
    {
        std::fill(used, used + 9, false);
        for (int i = 0; i < 9; i++)
        {
            if (grid[i][j] == 0 || used[grid[i][j] - 1])
            {
                return false;
            }
            used[grid[i][j] - 1] = true;
        }
    }
    //check subgrid
    for (int row = 0; row < 9; row += 3)
    {
        for (int col = 0; col < 9; col += 3)
        {
            std::fill(used, used + 9, false);
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    int num = grid[row + i][col + j];
                    if (num == 0 || used[num - 1])
                        return false;
                    used[num - 1] = true;
                }
            }
        }
    }
    return true;
}