
#include <iostream>
#include <vector>

int max_fix(std::vector<int> &piles)
{
    int max = 0;
    if (piles[0] > piles[piles.size() - 1])
    {
        max = piles[0];
        piles.erase(piles.begin());
    }
    else
    {
        max = piles[piles.size() - 1];
        piles.pop_back();
    }
    return max;
}

bool stoneGame(std::vector<int> &piles)
{
    bool alex(true);
    int alex_sum = 0, lee_sum = 0;
    int turn = 0;
    while (piles.size() > 0)
    {

        auto max = max_fix(piles);

        if (turn % 2 == 0)
        {
            alex_sum += max;
        }
        else
        {
            lee_sum += max;
        }

        turn++;
    }

    return alex_sum > lee_sum;
}

int main(void)
{
    std::vector<int> res{5, 3, 4, 5};

    if (stoneGame(res))
    {
        std::cout << "alex won\n";
    }
    else
    {
        std::cout << "lee won\n";
    }
    return 0;
}