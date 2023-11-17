#include <iostream>
using namespace std;

int fibo_rec(int n)
{
    if (n < 0)
        return -1;
    if (n == 0 || n == 1)
        return n;

    return fibo_rec(n - 1) + fibo_rec(n - 2);
}

int fibo_iter(int n)
{
    int c, a = 0, b = 1;

    if (n < 0)
        return -1;
    if (n == 0 || n == 1)
        return n;

    for (int i = 1; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int fibo_dyn(int n, int *arr, int sz)
{
    if (n < 0)
        return -1;
    if (n == 0 || n == 1)
    {
        return n;
    }

    for (int i = 2; i <= n && i < sz; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

int main(void)
{
    std::cout << fibo_rec(6) << "\n";
    std::cout << fibo_iter(6) << "\n";
    int arr[100] = {0};
    arr[0] = 0;
    arr[1] = 1;
    std::cout << fibo_dyn(6, arr, 100) << "\n";
    return 0;
}
