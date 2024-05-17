#include "PrintGrid.h"
#include "AlgorithmSudoku.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <conio.h>


void PrintHorizontalLines()
{
    std::cout << " ##############################" << std::endl;
}

void PrintVerticalLines(int left, int middle, int right, int selectedCol)
{
    std::cout << "| ";
    if (selectedCol == 0)
        std::cout << ">";
    std::cout << std::setw(2) << left;
    if (selectedCol == 0)
        std::cout << "<";
    std::cout << " | ";

    if (selectedCol == 1)
        std::cout << ">";
    std::cout << std::setw(2) << middle;
    if (selectedCol == 1)
        std::cout << "<";
    std::cout << " | ";

    if (selectedCol == 2)
        std::cout << ">";
    std::cout << std::setw(2) << right;
    if (selectedCol == 2)
        std::cout << "<";
    std::cout << " ## ";
}


void PrintSudokuGrid(int grid[9][9], int selectedRow, int selectedCol) 
{
    for (int i = 0; i < 9; ++i) 
    {
        if (i % 3 == 0)
            PrintHorizontalLines();
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0)
                std::cout << "|";
            if (selectedRow == i && selectedCol == j)
                std::cout << "[" << grid[i][j] << "]";
            else if (grid[i][j] == 0)
                std::cout << "   ";
            else
                std::cout << " " << grid[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }
    PrintHorizontalLines();
}

void generateRandomSudoku(int grid[9][9], int difficulty)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            grid[i][j] = 0;
        }
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    fillDiagonal(grid);
    solveSudoku(grid);

    int emptyCells = 81 - difficulty;
    while (emptyCells > 0)
    {
        int row = rand() % 9;
        int col = rand() % 9;
        if (grid[row][col] != 0)
        {
            grid[row][col] = 0;
            --emptyCells;
        }
    }
}
