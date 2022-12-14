// Parallel Matrix Arithmetic

// Kuira Edwards @02942519

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Reference: https://stackoverflow.com/questions/33224832/matrix-multiplication-with-multiple-threads-in-c

int* matA; 
int* matB; 

int* matSumResult;
int* matDiffResult; 
int* matProductResult; 

int MAX;
int turn0 = 0; turn1 = 0; turn2 = 0;

void fillMatrix(int* matrix) {
    for(int i = 0; i<MAX; i++) {
        for(int j = 0; j<MAX; j++) {
            matrix[i][j] = rand()%10+1;
        }
    }
}

void printMatrix(int matrix[MAX][MAX]) {
    for(int i = 0; i<MAX; i++) {
        for(int j = 0; j<MAX; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Fetches the appropriate coordinates from the argument, and sets
// the cell of matSumResult at the coordinates to the sum of the
// values at the coordinates of matA and matB.
void* computeSum(void* args) { // pass in the number of the ith thread
    int i, j;
    int k = turn0++;
    for(i = k; i < (k + 1); i++) {
      for(j = 0; j < MAX; j++) {
        *((int*)matSumResult + i*MAX + j) = *(matA + i*MAX + j) + *(matB + i*MAX + j);
      }
    }
}

// Fetches the appropriate coordinates from the argument, and sets
// the cell of matSumResult at the coordinates to the inner product
// of matA and matB.
void* computeProduct(void* args) { // pass in the number of the ith thread
    int i, j, m;
    int k = turn2++;
    for(i = k; i < (k + 1); i++) {
      for(j = 0; j < MAX; j++) {
        for(m = 0; m < MAX; m++) {
          *((int*)matProductResult + i*MAX + j) += *(matA + i*MAX + m) * *(matB + m*MAX + j);
        }
      }
    }
}

// Fetches the appropriate coordinates from the argument, and sets
// the cell of matSumResult at the coordinates to the difference of the
// values at the coordinates of matA and matB.
void* computeDiff(void* args) { // pass in the number of the ith thread
    int i, j;
    int k = turn1++;
    for(i = k; i < (k + 1); i++) {
      for(j = 0; j < MAX; j++) {
        *((int*)matDiffResult + i*MAX + j) = *(matA + i*MAX + j) - *(matB + i*MAX + j);
      }
    }
}

// Spawn a thread to fill each cell in each result matrix.
// How many threads will you spawn?
int main() {
    srand(time(0));  // Do Not Remove. Just ignore and continue below.
    
    // 0. Get the matrix size from the command line and assign it to MAX
    printf("Choose the dimensions for your NxN matrix: ");
    scanf("%d", &MAX);

    // 1. Dynamically allocate matrices
    matA = (int *)malloc(MAX * MAX * sizeof(int));
    matB = (int *)malloc(MAX * MAX * sizeof(int));
    matSumResult = (int *)malloc(MAX * MAX * sizeof(int));
    matDiffResult = (int *)malloc(MAX * MAX * sizeof(int));
    matProductResult = (int *)malloc(MAX * MAX * sizeof(int));
    
    // 2. Fill the matrices (matA and matB) with random values.
    // 3. Print the initial matrices.
    printf("Matrix A:\n");
    printMatrix(matA);
    printf("Matrix B:\n");
    printMatrix(matB);
    
    // 4. Create pthread_t objects for our threads.
    pthread_t threads[MAX];

    // 5. Create a thread for each cell of each matrix operation.
    int i;
    for(i=0; i < MAX; i++) {
      int* arg;
      pthread_create(&threads[i], NULL, computeSum, (void*)(arg));
      pthread_create(&threads[i], NULL, computeDiff, (void*)(arg));
      pthread_create(&threads[i], NULL, computeProduct, (void*)(arg));
    }

    // 6. Wait for all threads to finish.
    for(i = 0l i < MAX; i++) {
      pthread_joing(threads[i], NULL);
    }

    // 7. Print the results.
    printf("Results:\n");
    printf("Sum:\n");
    printMatrix(matSumResult);
    printf("Difference:\n");
    printMatrix(matDiffResult);
    printf("Product:\n");
    printMatrix(matProductResult);
    return 0;
}