#include "shell.h"
/**
 * _mystrcmp - compares two strings
 * @mystr1: first string
 * @mystr2: second string
 * @numbb: total number of characters to be compared if provided
 * Return: - 0 if both are same and -1 if both are not
 */
int _mystrcmp(const char *mystr1, const char *mystr2, int numbb)
{
	if (numbb == 0)
		return (0);
	while (numbb > 0 && *mystr1 && *mystr2)
	{
		if (*mystr1 != *mystr2)
			return ((*mystr1 < *mystr2) ? -1 : 1);
		++mystr1;
		++mystr2;
		numbb--;
	}
	return (0);
}
/**
 * _mystrcpy - Copy string from one container to another
 * @mystr1: new container to hold the copied string
 * @oringstr: string to be copied
 *
 * Return: - return copied string
 */
char *_mystrcpy(char *mystr1, const char *oringstr)
{
	for (; (*mystr1 = *oringstr) != '\0'; mystr1++, oringstr++)
		;
	return (mystr1);
}

/**
 *_acc_exe - checks if the command line argument is executable
 *@command: command line argument
 *
 * Return: 0 on success and -1 if it fails
 */
int _acc_exe(const char *command)
{
	if (command == NULL)
		return (-1);

	size_t cmd_llen = _strllen(command);
	char *pat1 = (char *)malloc(cmd_llen + 10);

	if (pat1 == NULL)
		return (-1); /*Memory allocation failed*/
	if (_mystrcmp(command, "/bin/", 5) == 0)
		_mystrcpy(pat1, command);
	else
	{
		_mystrcpy(pat1, "/bin/");
		strcat(pat1, command);
	}

	if (access(pat1, X_OK) == 0)
	{
		free(pat1);
		return (0);
	}
	else
	{
		free(pat1);
		return (-1);
	}

}

/**
 * _strllen - gets the length of a string
 * @stringg: the string whos length is to be determined
 *
 * Return: i (length of string)
 */

size_t _strllen(const char *stringg)
{
	int i = 0;

	while (*stringg)
	{
		stringg++;
		i++;
	}
	return (i);
}

/**
 * _echostr - echo back a string passed to it
 * @stringg: string to be printed to STDOUT_FILENO
 *
 * Return: nothing is returned
 */

size_t _echostr(const char *stringg)
{
	if (stringg == NULL)
		return (-1);
	write(1, stringg, _strllen(stringg));
}
