#include <iostream>
#include <vector>
#include <numeric>

const int MAX_SEARCH = 1000000;

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

int main()
{
    std::vector<bool> isPrime(MAX_SEARCH, true);
    primeSieve(isPrime);

    std::vector<int> primes;

    int longest_sum_prime = 0;
    int longest_sum_size = 0;
    int start_prime = 0;

    for (int p = 2; p < MAX_SEARCH; ++p)
    {
        if (isPrime[p])
        {
            primes.push_back(p);
        }
    }

    // Could probably speed this up by pre-accumuilating the sum and doing somthing like sum[j] - sum[i]

    
    for (auto i_it = primes.begin(); i_it != primes.end()-1; ++i_it)
    {
        int sum = *i_it;
        for (auto j_it = i_it+1; j_it != primes.end(); ++j_it)
        {
            sum += *j_it;

            if (sum > MAX_SEARCH)
            {
                break;
            }

            if (isPrime[sum])
            {
                // Longest sum?
                int dist = std::distance(i_it, j_it);
                if (dist > longest_sum_size)
                {
                    // Store the result
                    longest_sum_size = dist;
                    longest_sum_prime = sum;
                    start_prime = *i_it;
                }
            }
        }
    }

    std::cout << "Longest sum is of size: " << longest_sum_size << std::endl << "And results in the prime: " << longest_sum_prime << std::endl;
    std::cout << "Start of sum is: " << start_prime << std::endl;
}

// 997651
