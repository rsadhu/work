#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>

using namespace std;

int randomNumGenerator(int n)
{
    std::random_device rd;                         // Seed for the random number generator
    std::mt19937 gen(rd());                        // Mersenne Twister random number engine
    std::uniform_int_distribution<> distrib(1, n); // Range from 1 to 31

    return distrib(gen); // Generate a random number
}