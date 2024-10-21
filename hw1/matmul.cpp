#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
// #include <omp.h>

#define TILE_SIZE 32

// Initialize matrices with random values
void initializeMatrix(std::vector<std::vector<double>>& matrix, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = static_cast<double>(rand()) / RAND_MAX;
        }
    }
}

// Tiled matrix multiplication (C = A * B)
void matrixMultiplyTiled(const std::vector<std::vector<double>>& A,
                         const std::vector<std::vector<double>>& B,
                         std::vector<std::vector<double>>& C, int N) {
    for (int i = 0; i < N; i += TILE_SIZE) {
        for (int j = 0; j < N; j += TILE_SIZE) {
            for (int k = 0; k < N; k += TILE_SIZE) {
                // Multiply tiles
                for (int ii = i; ii < std::min(i + TILE_SIZE, N); ++ii) {
                    for (int jj = j; jj < std::min(j + TILE_SIZE, N); ++jj) {
                        double sum = 0;
                        for (int kk = k; kk < std::min(k + TILE_SIZE, N); ++kk) {
                            sum += A[ii][kk] * B[kk][jj];
                        }
                        C[ii][jj] += sum;
                    }
                }
            }
        }
    }
}

int main() {
    int N = 1024; // Matrix size (NxN)
    
    // Initialize matrices
    std::vector<std::vector<double>> A(N, std::vector<double>(N));
    std::vector<std::vector<double>> B(N, std::vector<double>(N));
    std::vector<std::vector<double>> C(N, std::vector<double>(N, 0));
    
    initializeMatrix(A, N);
    initializeMatrix(B, N);
    
    // Start benchmarking
    clock_t start = clock();
    
    // Perform tiled matrix multiplication
    matrixMultiplyTiled(A, B, C, N);
    
    // End benchmarking
    clock_t end = clock();
    
    double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    
    std::cout << "Tiled matrix multiplication completed in " << elapsed_time << " seconds." << std::endl;
    
    return 0;
}
