#include <iostream>

int main(void)
{
    int n_candies = 10, n_chdilren = 3;
    int res[100] = {0};
    int candy = 0;
    int i = 0;
    while (true)
    {
        if (n_candies <= 0)
            break;
        if (candy < n_candies)
            res[i++] += ++candy;
        else
            res[i++] += n_candies;
        n_candies -= candy;
        if (i % n_chdilren == 0)
        {
            i = 0;
        }
    }
    return 0;
}