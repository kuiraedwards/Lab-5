// Worked with Keerthana Pullela and Jamarri White
// Kuira Edwards @02942519
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 9

// Sudoku board. Modify this to test your checker!
// 0 == empty cell; 1-9 is the filled in digit.
int board[SIZE][SIZE] = {
    {1,0,0,0,0,0,0,0,0},
    {0,4,0,0,0,0,0,0,0},
    {0,0,3,0,0,0,15,0,0},
    {0,0,0,8,0,0,0,0,0},
    {0,0,0,0,5,0,0,0,0},
    {0,1,0,0,0,2,0,0,0},
    {0,0,0,0,0,0,7,0,0},
    {0,0,0,2,0,0,0,8,0},
    {0,0,3,0,0,0,0,0,9},
};

bool row_check[SIZE];
bool col_check[SIZE];
bool box_check[SIZE];

void printBoard(int board[SIZE][SIZE]) {
    for(int i = 0; i<SIZE; i++) {
        for(int j = 0; j<SIZE; j++) {
            printf("%5d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Checks the given row for duplicate numbers, and updates the row_check
// value for that row appropriately. If no number is repeated in that row,
// row_check[row] will be set to true; otherwise, it will be false.
void* checkRow(void* args) {
    return NULL;
}

// Checks the given col for duplicate numbers, and updates the col_check
// value for that col appropriately. If no number is repeated in that col,
// col_check[col] will be set to true; otherwise, it will be false.
void* checkCol(void* args) {
    return NULL;
}

// Checks the given 3x3 box for duplicate numbers, and updates the box_check
// value for that box appropriately. If no number is repeated in that box,
// box_check[box] will be set to true; otherwise, it will be false.
void* checkBox(void* args) {
    return NULL;
}

// Spawn a thread to fill each cell in each result matrix.
// How many threads will you spawn?
int main() { 
    // 1. Print the board.
    printf("Board:\n");
    printBoard(board);
    
    // 2. Create pthread_t objects for our threads.
    
    // 3. Create a thread for each cell of each matrix operation.
    
    // 4. Wait for all threads to finish.
    
    // 5. Print the results.
    printf("Results:\n");
    bool passed1 = true;
    printf("Rows:\n");
    for (int i = 0; i < SIZE; i++) {
        if (!row_check[i]) {
            printf("Row %i did not pass\n", i);
            passed1 = false;
        }
    }
    if (passed1) {
        printf("All rows passed!\n");
    }
    
    bool passed2 = true;
    printf("Cols:\n");
    for (int i = 0; i < SIZE; i++) {
        if (!col_check[i]) {
            printf("Col %i did not pass\n", i);
            passed2 = false;
        }
    }
    if (passed2) {
        printf("All cols passed!\n");
    }
    
    bool passed3 = true;
    printf("Boxes:\n");
    for (int i = 0; i < SIZE; i++) {
        if (!box_check[i]) {
            printf("Box %i did not pass\n", i);
            passed3 = false;
        }
    }
    if (passed3) {
        printf("All boxes passed!\n");
    }
    return 0;
}