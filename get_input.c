#include "shell.h"

/**
*get_input - get user input
*Return: pointer to user input
**/

char *get_input(void)
{
	char *input, *temp;
	size_t size;

	input = malloc(sizeof(char *));
	printf("$ ");
	getline(&input, &size, stdin);
	temp = input;
	while (*temp)
	{
		if (*temp == '\n')
			*temp = '\0';
		temp++;
	}
	return (input);
}
