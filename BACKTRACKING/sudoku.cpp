#include<iostream>
using namespace std;

// Forward declaration of the print function
void printSudoku(int sudoku[][9]);

// Function to check if placing a digit is safe
bool isSafe(int sudoku[][9], int row, int col, int digit) {
    // 1. Check Row
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == digit) {
            return false;
        }
    }

    // 2. Check Column
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == digit) {
            return false;
        }
    }

    // 3. Check 3x3 Grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[i + startRow][j + startCol] == digit) {
                return false;
            }
        }
    }

    return true; // It's safe to place the digit
}

// Solves the Sudoku puzzle using backtracking
bool sudokuSolver(int sudoku[][9], int row, int col) {
    // Base Case: If we have reached the end of the board (row 9), we are done.
    if (row == 9) {
        return true;
    }

    // Calculate the next cell to visit
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    // If the current cell is already filled, move to the next one
    if (sudoku[row][col] != 0) {
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    // Try placing digits 1 through 9
    for (int digit = 1; digit <= 9; digit++) {
        if (isSafe(sudoku, row, col, digit)) {
            // Place the digit
            sudoku[row][col] = digit;

            // Recur to solve the rest of the puzzle
            if (sudokuSolver(sudoku, nextRow, nextCol)) {
                return true; // If the rest was solved, we are done
            }

            // --- BACKTRACKING STEP ---
            // If the recursive call failed, undo the choice and try the next digit
            sudoku[row][col] = 0;
        }
    }

    // If no digit can be placed in this cell, return false
    return false;
}

// Prints the Sudoku grid
void printSudoku(int sudoku[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

// Main driver function
int main() {
    int sudoku[9][9] = {
        {0, 0, 8, 0, 0, 0, 0, 0, 0},
        {4, 9, 0, 1, 5, 7, 0, 0, 2},
        {0, 0, 3, 0, 0, 4, 1, 9, 0},
        {1, 8, 5, 0, 6, 0, 0, 2, 0},
        {0, 0, 0, 0, 2, 0, 0, 6, 0},
        {9, 6, 0, 4, 0, 5, 3, 0, 0},
        {0, 3, 0, 0, 7, 2, 0, 0, 4},
        {0, 4, 9, 0, 3, 0, 0, 5, 7},
        {8, 2, 7, 0, 0, 9, 0, 1, 3}
    };

    if (sudokuSolver(sudoku, 0, 0)) {
        cout << "Sudoku solved successfully:" << endl;
        printSudoku(sudoku);
    } else {
        cout << "No solution exists for this Sudoku." << endl;
    }

    return 0;
}