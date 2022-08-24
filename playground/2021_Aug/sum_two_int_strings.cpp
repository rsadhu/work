#include <iostream>

using namespace std;
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int c = 0;
        int sum = 0;
        for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 && j >= 0; i--, j--)
        {
            int tmp = c + (num1[i] - '0') + (num2[j] - '0');

            if (tmp / 10)
            {

                c = 1;
            }
            else
            {
                c = 0;
            }

            sum += tmp % 10;

            std::cout << sum << "\n";
        }

        for (int i = num1.size(); i >= 0; i--)
        {
            int tmp = c + (num1[i] - '0');

            if (tmp / 10)
            {
                c = 1;
            }
            else
            {
                c = 0;
            }

            sum += tmp % 10;
            std::cout << sum << "\n";
        }

        for (int j = num2.size(); j >= 0; j--)
        {
            int tmp = c + (num2[j] - '0');
            if (tmp / 10)
            {

                c = 1;
            }
            else
            {
                c = 0;
            }

            sum += tmp % 10;
            std::cout << sum << "\n";
        }

        std::cout << sum;
        return std::to_string(sum);
    }
};

int main()
{
    Solution s;
    std::cout << s.addStrings("11", "123");
    return 0;
}