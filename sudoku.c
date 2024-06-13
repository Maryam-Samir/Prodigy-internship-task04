#include <stdbool.h>
#include <stdio.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE];

bool is_safe(int row, int col, int num) {
    // Check row
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

void print_grid() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}


bool solve_sudoku() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= GRID_SIZE; num++) {
                    if (is_safe(row, col, num)) {
                        printf("Trying to place %d at (%d, %d)\n", num, row, col);
                        print_grid();
                        grid[row][col] = num;
                        if (solve_sudoku()) {
                            return true;
                        }
                        grid[row][col] = 0;
                    }
                }
                printf("No valid placement found at (%d, %d)\n", row, col);
                print_grid();
                return false;
            }
        }
    }
    printf("Sudoku puzzle solved!\n");
    print_grid();
    return true;
}



int main() {
    printf("Enter the Sudoku grid to be equal columns and rows(0 for empty cells):\n");
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            scanf("%d", &grid[row][col]);
        }
    }

    if (!solve_sudoku()) {
        printf("Unable to solve the Sudoku puzzle.\n");
    }
    return 0;
}



