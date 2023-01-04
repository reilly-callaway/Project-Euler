#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

void primeSieve(std::vector<bool>& primes)
{
    for (int p = 2; p*p < primes.size(); p++)
    {
        if (primes[p])
        {
            for (int i = p*p; i < primes.size(); i += p)
            {
                primes[i] = false;
            }
        }
    }
}

// Given the four digit number n, return the (up to) 24 permutations
std::vector<int> prime_permutations(int n, std::set<int>& primes)
{
    std::vector<int> digits(4);
    std::vector<int> permutations;

    for (int i = 0; i < 4; i++)
    {
        digits[i] = n % 10;
        n /= 10;
    }

    std::sort(digits.begin(), digits.end());

    do
    {
        int num = 0;
        for (int i = 0; i < 4; i++)
        {
            num += digits[i] * pow(10, i);
        }

        if (num > 1000 && primes.find(num) != primes.end())
        {
            permutations.push_back(num);
        }
        
    } while (std::next_permutation(digits.begin(), digits.end()));

    std::sort(permutations.begin(), permutations.end());

    return permutations;    
}

std::pair<int, int> hasArithmeticSequence(std::vector<int> nums)
{
    for (auto i_it = nums.begin(); i_it != nums.end()-2; ++i_it)
    {
        for (auto j_it = i_it+1; j_it != nums.end()-1; ++j_it)
        {
            int diff = *j_it - *i_it;

            if (std::find(j_it+1, nums.end(), *j_it + diff) != nums.end())
            {
                return std::make_pair(*i_it, *j_it);
            }
        }
    }
    return std::make_pair(0, 0);
}


int main()
{
    // auto perms = permutations(1487);
    // for (int num : perms)
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    // auto res = hasArithmeticSequence(perms);

    // std::cout << res.first << ", " << res.second << ", " << 2*res.second - res.first << std::endl;


    // return 0;

    std::vector<bool> isPrime(10000, true);
    primeSieve(isPrime);

    std::set<int> primesToCheck;

    int nFound = 0;
    int firstFound = 0;

    for (int i = 2; i < 10000; i++)
    {
        if (isPrime[i]) primesToCheck.insert(i);
    }

    for (int prime : primesToCheck)
    {
        if (prime < 1000) continue;

        auto perms = prime_permutations(prime, primesToCheck);
        if (perms.size() < 3) continue;

        auto res = hasArithmeticSequence(perms);
        if (res.first != 0)
        {
            // We found it!
            std::cout << "Sequence is: " << res.first << ", " << res.second << ", " << 2*res.second - res.first << std::endl;
            if (nFound == 0)
            {
                firstFound = res.first;
                nFound++;
            }
            else if (res.first != firstFound)
            {
                break;
            }
        }
    }
}

// 2969, 6299, 9629
