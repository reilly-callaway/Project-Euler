#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <cmath>

const int MAX_SEARCH = 10000;

bool addDigits(int num, std::set<int>& digits)
{
    // Return false if a digit is already present, or if digit is zero
    while (num > 0)
    {
        int digit = num % 10;
        if (digit == 0) return false;

        auto res = digits.insert(digit);
        if (!res.second) return false;

        num /= 10;
    }
    return true;
}

int numLen(int num)
{
    int i = 0;
    for (; num > 0; i++)
    {
        num /= 10;
    }

    return i;
}

int makePandigital(int source, int n)
{
    int nDigits = 0;
    int res = 0;
    for (int multiplier = n; multiplier > 0; multiplier--)
    {
        res += source * multiplier * pow(10, nDigits);
        nDigits += numLen(source * multiplier);
    }

    return res;
}

int main()
{
    std::vector<std::pair<int, int>> max_pandigital;
    // Came to the conclusion we're looking for a four digit number
    for (int i = MAX_SEARCH-1; i >= 1000; i--)
    {
        bool isMaxDigits = false;
        int maxNumMultipliers = 9 / numLen(i);

        for (int nMultipliers = 2; nMultipliers <= maxNumMultipliers; nMultipliers++)
        {
            std::set<int> digits;
            for (int multiplier = nMultipliers; multiplier > 0; multiplier--)
            {
                int term = multiplier * i;
                if (!addDigits(term, digits))
                {
                    break;
                }
            }

            if (digits.size() == 9)
            {
                // Pandigital!
                // We're searching from biggest to smallest to this must be the biggest!
                std::cout << i << " Has pandigital that can be formed as the concatenated product of an integer with (1, ..., " << nMultipliers << ") = " << makePandigital(i, nMultipliers) << std::endl;
                
                return 0;
            }
        }
    }
}

// 9327 * (1, 2) = 9327 18654
