#include <iostream>
#include <cstdlib>
#include <ctime>

const int ARRAY_SIZE = 1000000;

void difficultBranchPrediction() {
    // Initialize an array with random values
    int* arr = new int[ARRAY_SIZE];

    // Fill array with random values (0 or 1)
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = rand() % 2; // Random 0 or 1
    }

    // Variable to store a simple result
    int sum = 0;

    // Branching based on random array values
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] == 1) { // Unpredictable branching
            sum += arr[i];
        } else {
            sum -= arr[i];
        }
    }

    // Output the result to prevent compiler optimizations
    std::cout << "Sum: " << sum << std::endl;

    // Cleanup
    delete[] arr;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Run the branch-prediction-difficult code
    difficultBranchPrediction();

    return 0;
}
