#include "shell.h"
/**
 * _perror - prints an error message
 * @stringg: Error message
 * Return: nothing
 */
void _perror(const char *stringg)
{
	perror(stringg);
	exit(EXIT_FAILURE);
}

/**
 * _execute_cmd - executes the command
 * @stringg: commad to execute
 * Return: returns 0
 */
size_t _execute_cmd(char *separated[])
{
	if (_acc_exe(separated[0]) == 0)
	{
		pid_t newpid = fork();

		if (newpid == -1)
			_perror("Fork has failed");
		else if (newpid == 0)
		{
			int retyp = execvp(separated[0], separated);

			if (retyp == -1)
				_perror("Execution error");
		}
		else
			wait(NULL);
	}
	else
	{
		_echostr("bash: ");
		_echostr(separated[0]);
		_echostr(": Command not found\n");
	}
//	for (int i = 0; separated[i] != NULL; i++)
//		free(separated[i]);
	return (0);
}
