#include "shell.h"

/**
 * mystrtok - splits strings into their substring
 * @str: Array of string to be splited
 * @delimm: the delimeter
 * Return: returns the splited substring
 */
char *mystrtok(char *str, const char *delimm)
{
	static char *current;
	char *token_start;
	int is_deli;

	if (str != NULL)
		current = str;
	if (current == NULL || *current == '\0')
		return (NULL);

	token_start = current;
	while (*current != '\0')
	{
		is_deli = 0;
		for (size_t i = 0; delimm[i] != '\0'; i++)
		{
			if (*current == delimm[i])
			{
				is_deli = 1;
				break;
			}
		}
		if (is_deli)
		{
			*current = '\0'; /* Null-terminate the token*/
			current++;
			break;
		}
		current++;
	}
	return (token_start);
}
