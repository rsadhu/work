#include <iostream>
#include <thread>
#include <atomic>
#include <map>
#include <chrono>

long int fib(long int n)
{
    if (n <= 2)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

long int fib_memo(long int n, std::map<long int, long int> &memo)
{
    if (memo[n] != 0)
        return memo[n];

    if (n <= 2)
        return 1;

    memo[n] = fib_memo(n - 2, memo) + fib_memo(n - 1, memo);
    return memo[n];
}

int main(void)
{
    long int n = 50;

    auto start = std::chrono::system_clock::now();

    std::map<long int, long int> memo;

    std::cout << "fibo_memo :: " << fib_memo(n, memo) << "\n";

    auto end = std::chrono::system_clock::now();

    std::cout << "\n time diff : " << (end - start).count() << "\n";

    return 0;
}