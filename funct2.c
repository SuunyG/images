#include "shell.h"

/**
 * _mystrcmp1 - compares two strings
 * @mystr1: first string
 * @mystr2: second string
 * Return: 0 on sucess and -1 on failure
 */
int _mystrcmp1(const char *mystr1, const char *mystr2)
{
	while (*mystr1 && *mystr2)
	{
		if (*mystr1 != *mystr2)
			return ((*mystr1 < *mystr2) ? -1 : 1);
		++mystr1;
		++mystr2;
	}
	return (0);
}
