
#include "PrintGrid.h"
#include "AlgorithmSudoku.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>

int main()
{
    int difficulty;

    std::cout << "**Chose the difficulty level:" << std::endl;
    std::cout << "  '1' for EASY" << std::endl;
    std::cout << "  '2' for MEDIUM" << std::endl;
    std::cout << "  '3' for HARD" << std::endl;

    std::cin >> difficulty;

    switch (difficulty)
    {
    case 1: difficulty = 38;
        break;
    case 2: difficulty = 30;
        break;
    case 3: difficulty = 28;
        break;
    default: 
        std::cerr << "Invalid choice. Exiting program." << std::endl;
        return 1;
    }

    int sudokuGrid[9][9] = { 0 };
    generateRandomSudoku(sudokuGrid, difficulty);
    int selectedRow = 0, selectedCol = 0;
    char userInput;

    do {
        system("cls");
        PrintSudokuGrid(sudokuGrid, selectedRow, selectedCol);
        std::cout << "**Use arrow keys (or WASD) to navigate." << std::endl;
        std::cout << "**Press a number key to fill the selected cell." << std::endl;
        std::cout << "**Press 'q' to quit." << std::endl;
        std::cout << "**Press 'c' to check if the sudoku is solved." << std::endl;

        userInput = _getch();

        switch (userInput)
        {
        case 'q': return 0; // Quit the program
        case 72:
        case 'w': if (selectedRow > 0)  // Up 
            selectedRow--;
            break;
        case 80:
        case 's': if (selectedRow < 8) // Down 
            selectedRow++;
            break;
        case 75:
        case 'a': if (selectedCol > 0)  // Left 
            selectedCol--;
            break;
        case 77:
        case 'd': if (selectedCol < 8)  // Right
            selectedCol++;
            break;
        default:
            if (userInput >= '1' && userInput <= '9' && sudokuGrid[selectedRow][selectedCol] == 0) 
            {
                sudokuGrid[selectedRow][selectedCol] = userInput - '0';
            }
            break;
        case 'c': if (checkSudoku(sudokuGrid))
                { 
                    std::cout << "Congratulations! You solved the sudoku!" << std::endl;
                    return 0;
                } else 
                    {
                        std::cout << "The sudoku is not correctly solved yet." << std::endl;
                        _getch();
                    }
                    break;
        }
    } while (userInput != 'q');
    return 0;
}


