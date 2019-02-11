// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>		// std::vector

void print_v(std::vector<int> v)
{
	for(int num : v)
	{
		std::cout << num;
	}
	std::cout << "\n";
}

int main () {
	std::vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::sort(digits.begin(),digits.end());

	for(int i = 1; i < 1000000; i++)
	{
		std::next_permutation(digits.begin(),digits.end());
	}

	print_v(digits);
}

