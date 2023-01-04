#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

std::vector<int> primeFactors(int n)
{
    std::vector<int> factors;

    // Check 2
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }
 
    // Check odd numbers
    for (int i = 3; i*i <= n; i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
    {
        factors.push_back(n);
    }

    for (int p : factors)
    {
        int count = std::count(factors.begin(), factors.end(), p);
        if (count > 1)
        {
            // Remove all instances of p
            auto pos = std::find(factors.begin(), factors.end(), p);
            while (pos != factors.end())
            {
                factors.erase(pos);
                pos = std::find(factors.begin(), factors.end(), p);
            }
            
            // Add p^count
            factors.push_back(pow(p, count));
        }
    }

    return factors;
}

const int MAX_SEARCH = 10000000;

int main()
{
    // A sieve method of sorts that constructs the product of primes would probably be a faster method, then check for four consecutive numbers, unclear when/if you check for distinctness
    std::vector<std::vector<int>> factors(MAX_SEARCH);
    factors[5] = primeFactors(5);
    factors[6] = primeFactors(6);
    factors[7] = primeFactors(7);

    for (int i = 5; i < MAX_SEARCH; ++i)
    {
        factors[i+3] = primeFactors(i+3);

        std::set<int> distinct_factors;

        for (int j = 0; j < 4; j++)
        {
            std::copy(factors[i+j].begin(), factors[i+j].end(), std::inserter(distinct_factors, distinct_factors.end()));
        }

        if (distinct_factors.size() >= 16)
        {
            std::cout << i << std::endl;
            break;
        }
    }
}

// 134043
