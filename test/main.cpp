#include <iostream>
#include <chrono>

int main(void)
{
    auto start = std::chrono::high_resolution_clock::now();

    int i = 0;
    while (i < 1000000000)
    {
        i++;
    }

    // Get the current time point after the operation
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration between the start and end time points
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Output the duration in milliseconds
    std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}