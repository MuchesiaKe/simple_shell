#include "shell.h"

/**
*tokenizer -  splits a string into words
*@str: string to split into words
*Return: an array of each word of the string
**/

char **tokenizer(char *str)
{
	int nw, i;
	char **token_arr, *token;

	i = 0;
	nw = word_counter(str);
	nw++;

	token_arr = malloc(nw * sizeof(*token_arr));
	if (token_arr == NULL)
	{
		perror("token_arr malloc failed\n");
		exit(1);
	}

	i = 0;
	token = strtok(str, " ");
	while (i < nw && token)
	{
		token_arr[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	token_arr[i] = NULL;
	return (token_arr);
}
