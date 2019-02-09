#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define LEGNTH 6

bool is_palindrome(int n)
{
	char s[LEGNTH];
	sprintf(s, "%d", n);
	int leng = strlen(s)-1;
	for (int i = 0; i <= leng/2; i++)
	{
		if(s[i] != s[leng-i])
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	for (int i = 999; i > 948; i--)
	{
		for (int j = i; j > 900; j--)
		{
			if(is_palindrome(i*j))
			{
				printf("\t%3d * %3d = %6d\n", i, j, i*j);
			}
		}
	}
}