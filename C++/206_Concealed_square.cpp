#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> form = {9, 8, 7, 6, 5, 4, 3, 2, 1};

bool hasForm(unsigned long long num)
{
    num /= 100;
    for (int digit = 9; digit > 0; digit--)
    {
        if (num % 10 != digit)
        {
            return false;
        }
        num /= 100;
    }

    return true;
}

const int START = 1010101010; // = sqrt(1020304050607080900)
const int END = 1389026623; // = sqrt(1929394959697989990)

int main()
{
    // We know that as the last digit is a zero, the second to last must also be a zero
    // So our unsquared number is a multiple of 10
    for (int i = START; i < END; i+=10)
    {
        // i/10 must end in 3 or 7 due to position of 9 in square number
        int second_last_digit = (i / 10) % 10;
        if (second_last_digit != 3 && second_last_digit != 7)
        {
            continue;
        }

        if (hasForm((unsigned long long)i*(unsigned long long)i))
        {
            std::cout << "The number whose square has the form 1_2_3_4_5_6_7_8_9_0 is: " << i << std::endl;
            std::cout << "The square is: " << (unsigned long long)i*(unsigned long long)i << std::endl;
            break;
        }
    }
}

// 1389019170
// in ~0.091 seconds
