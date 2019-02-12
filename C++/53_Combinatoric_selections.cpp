#include <iostream>

int nChoosek(int n, int k)
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main()
{
	int num_large_values = 0;
	unsigned long combo;
	for(int n = 23; n <= 100; n++)
	{
		for(int r = 2; r < n; r++)
		{
			if (nChoosek(n, r) > 1000000)
			{
				num_large_values += n-2*r+1;
				break;
			}
		}
	}
	std::cout << num_large_values << "\n";
}