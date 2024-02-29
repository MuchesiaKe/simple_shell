#include <stdio.h>
#define IN 1
#define OUT 0

/**
*word_counter - counter the number of words in a string
*@str: string to count words
*Return: number of words in given string
**/

int word_counter(char *str)
{
	int state, nw;

	nw = 0;
	state = OUT;

	while (*str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			nw++;
		}
		str++;
	}
	return (nw);
}
