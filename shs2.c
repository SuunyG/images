#include "shell.h"



int main(void)
{
	char *bbuf = NULL;
	size_t llen = 0;
	ssize_t numread;

	for (;;)
	{
		_echostr("My Shell: ");
		numread = getline(&bbuf, &llen, stdin);
		if (numread <= 0)
		{
			break; /* Exit on EOF or error*/
		}
		bbuf[numread - 1] = '\0';

		/* Tokenize the input*/ 

		char *separated[numread];
		char *args = strtok(bbuf, " ");
		int ind = 0;

		while (args != NULL && ind < numread)
		{
			separated[ind] = args;
			args = strtok(NULL, " ");
			ind++;
		}
		separated[ind] = NULL;
		if (_mystrcmp1(separated[0], "exit") == 0)
		{
			_echostr("Closing My Shell ...\n");
			break;
		}
		if (ind > 0)
		{
			_execute_cmd(separated);
		}
	}
	free(bbuf);
	return (0);
}
