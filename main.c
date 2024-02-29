#include "shell.h"

/**
*main - control program execution
*Return: Always 0
**/

int main(void)
{
	char *input, **input_arr, *full_path;
	int i;

	i = 0;
	while (strcmp(input, "exit"))
	{
	input = get_input();
	input_arr = tokenizer(input);
	full_path = checker(input_arr);
	if (full_path)
	{
		strcpy(input_arr[0], full_path);
		executer(input_arr);
	}
	else
	{

		printf("Invalid command\n");
	}
	while (input_arr[i])
	{
		free(input_arr[i]);
		i++;
	}
	free(full_path);
	free(input_arr);
	free(input);
	}
	return (0);
}
