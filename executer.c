#include "shell.h"

/**
*executer - executes the command with execve
*@input_arr : an array with pathname and arguments
*Return: void
**/

void executer(char **input_arr)
{
	pid_t my_pid;
	int status;

	my_pid = fork();
	if (my_pid == -1)
	{
		perror("Error forking!\n");
		exit(1);
	}
	else if (my_pid == 0)
	{
		if (execve(input_arr[0], input_arr, NULL) == -1)
		{
			perror("execve failed");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}
