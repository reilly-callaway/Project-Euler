#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

std::vector<int> coins = {200, 100, 50, 20, 10, 5, 2, 1};

const int TARGET = 200;

int nCombinations(int target, std::vector<int>::iterator coinStart, std::vector<int>::iterator coinEnd)
{
    int combos = 0;

    for (auto coin = coinStart; coin < coinEnd; coin++)
    {
        if (target == *coin)
        {
            combos++;
        }
        else if (target - *coin > 0)
        {
            combos += nCombinations(target - *coin, coin, coinEnd);
        }
        // Else this coin is too big
    }

    return combos;
}


int main()
{
    int ans = nCombinations(TARGET, coins.begin(), coins.end());
    std::cout << "£2 be made using this many ways: " << ans << std::endl;
}

// 73682
