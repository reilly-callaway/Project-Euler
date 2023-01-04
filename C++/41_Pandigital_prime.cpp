#include <iostream>
#include <vector>
#include <set>
#include <utility>

const int N = 7654321;

void primeSieve(std::vector<bool>& primes)
{
    for (int p = 2; p*p <= N; p++)
    {
        if (primes[p])
        {
            for (int i = p*p; i <= N; i += p)
            {
                primes[i] = false;
            }
        }
    }
}

bool isPandigital(int num)
{
    // We only care about 9 digit panditials
    std::set<int> digits;

    while (num > 0)
    {
        int digit = num % 10;
        if (digit == 0 || digit == 8 || digit == 9) return false;

        auto res = digits.insert(digit);
        if (!res.second) return false;

        num /= 10;
    }
    return true;
}


int main()
{
    // It's probably quicker to iterate the permutations of 7654321, and then manually check if they're prime, as you'll probably find the answer within < 10 permutations
    std::vector<bool> primes(N+1, true);

    primeSieve(primes);

    for (int i = N; i > 1000000; i-=2)
    {
        if (primes[i] && isPandigital(i))
        {
            std::cout << "Largest n-digit pandigital prime is: " << i << std::endl;
            return 0;
        }
    }
}

// 7652413
