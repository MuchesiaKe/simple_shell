#include "shell.h"

/**
*checker - checks if command is present in PATH
*@input_arr: array of command and arguements
*Return: full path of command
**/

char  *checker(char **input_arr)
{
	char *path, *comm_path, *full_path, *copy;
	struct stat st;

	path = getenv("PATH");
	if (path == NULL)
	{
		perror("Error getting PATH");
		exit (1);
	}
	copy = strdup(path);
	if (copy == NULL)
	{
		perror("Error allocating memory for copy");
		exit (1);
	}
	comm_path = strtok(copy, ":");
	while (comm_path != NULL)
	{
		full_path = strdup(comm_path);
		full_path = strcat(full_path, "/");
		full_path = strcat(full_path, input_arr[0]);
		if (stat(full_path, &st) == 0)
		{
			free(copy);
			return (full_path);
		}
		comm_path = strtok(NULL, ":");
	}
	free(full_path);
	return (NULL);
}
