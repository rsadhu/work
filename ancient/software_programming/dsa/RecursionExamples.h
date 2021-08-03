#pragma once

bool findItem(std::vector<int> list) { return false; }

std::vector<int> addOddItems(std::vector<int> list) {
    std::vector<int> ret;
    return ret;
}

int power(int base, int exp) {
    if (exp != 0)
        return base * power(base, --exp);
    else
        return 1;
}

int factorial(int num) {
    if (num == 1 || num == 0) return 1;
    return num-- * factorial(num);
}