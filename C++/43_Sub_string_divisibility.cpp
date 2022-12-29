#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int vec2int(std::vector<int> digits)
{
    int num = 0;
    int multiplier = 1;
    for (auto digi = digits.rbegin(); digi < digits.rend(); digi++)
    {
        num += *digi * multiplier;
        multiplier *= 10;
    }

    return num;
}

int vec2int(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    int num = 0;
    int multiplier = 1;
    for (auto digi = std::make_reverse_iterator(end); digi < std::make_reverse_iterator(start); digi++)
    {
        num += *digi * multiplier;
        multiplier *= 10;
    }

    return num;
}

std::vector<int> generateSpecialPandigitals()
{
    std::vector<int> pandigitals;

    std::vector<std::vector<int>> numbers(1, std::vector<int>(10, 0));
    
    // Iterate over each digit, and then applying a specific divisibility rule
    std::vector<int> divisibility_check = {1, 1, 1, 2, 3, 5, 7, 11, 13, 17};

    // Don't pick the first digit, it will always be whatever digit is leftover and passes all the tests
    for (int digit_index = 1; digit_index < 10; digit_index++)
    {
        std::vector<std::vector<int>> new_numbers;
        for (int digit = 0; digit < 10; digit++)
        {
            /*
            Givin the divisibility requirements, some digits have particular restrictions:

            d4 = {0, 2, 4, 6, 8}
            d6 = {0, 5}
            */
            if (digit_index == 5 && (digit != 0 && digit != 5))
            {
                continue;
            }
            else if (digit_index == 3 && (digit != 0 && digit != 2 && digit != 4 && digit != 6 && digit != 8))
            {
                continue;
            }

            for (auto number = numbers.begin(); number < numbers.end(); number++)
            {
                // No duplicates!
                if (std::find(number->begin()+1, number->begin()+digit_index, digit) == number->begin()+digit_index)
                {
                    std::vector<int> test_copy(*number);
                    test_copy[digit_index] = digit;

                    // Test condition
                    if (digit_index < 3 || vec2int(test_copy.begin()+digit_index-2, test_copy.begin()+digit_index+1) % divisibility_check[digit_index] == 0)
                    {
                        // Pass! This copy gets added to the list of possible candidates
                        new_numbers.push_back(test_copy);
                    }
                }
            }
        }
        numbers = new_numbers;
    }

    for (auto num : numbers)
    {
        // Calculate the first digit for each pandigital number
        for (int i = 0; i < 10; i++)
        {
            if (std::find(num.begin()+1, num.end(), i) == num.end())
            {
                num[0] = i;
                break;
            }
        }
    }
    
    std::cout << "Pandigitals with special property: " << std::endl;
    for (auto number : numbers)
    {
        pandigitals.push_back(vec2int(number.begin(), number.end()));
        std::cout << pandigitals.back() << std::endl;
    }

    return pandigitals;
}

int main(int argc, char *argv[])
{
    auto panDigitals = generateSpecialPandigitals();

    int result = std::reduce(panDigitals.begin(), panDigitals.end());

    std::cout << "The sum of all 0 to 9 pandigital numbers with this property:\n" << result << std::endl;
}

// 1695334890
