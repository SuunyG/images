#include "shell.h"

int main(int argc, char **listargs)
{

	char *buf = NULL;
	for (;;)
	{
		write (1, "simple_shell# ", 14);

		size_t len;
		ssize_t numread;

		/*ssize_t getline(char **buf, size_t *len, stdin);*/
		numread = getline(&buf, &len, stdin);
		if (numread > 0)
			buf[numread - 1] = '\0';

		for (int i = 0; buf[i] != '\0'; i++)
		{
			if (strcmp(buf, "exit") == 0)
			{
				write (1, "Closing simple_shell...", 24);
				//exit(0);
				return (0);
			}
			if (buf == NULL)
				break;
		//	printf("%c", buf[i]);
		}
		
		char *separated[numread];
		char *args = strtok(buf, " ");
		int ind = 0;

		while (args != NULL && ind < numread)
		{
			separated[ind] = args;
			args = strtok(NULL, " ");
			ind++;
		}
		separated[ind] = NULL;
		
		int acce = acc_exe(separated[0]);
		if (acce == 0)
		{
			if (ind > 0)
			{
				pid_t newpid = fork();
				
				if (newpid <= -1)
				{
					perror("Fork has failed");
					exit(EXIT_FAILURE);
				}
				else if (newpid == 0)
				{
					int retyp = execvp(separated[0], separated);
					
					if (retyp == -1)
					{
						/* perror("./shell");*/
						char error_message[] = "bash: ";
						
						strcat(error_message, separated[0]);
						strcat(error_message, ": command not found\n");
						write(2, error_message, strlen(error_message));
					}
					exit(EXIT_FAILURE);
				}
				else
					wait(NULL); 
			}
		}
		else
		{
			/* perror("./shell");*/
			char error_message[] = "bash: ";
			
			strcat(error_message, separated[0]);
			strcat(error_message, ": ccccccccccccccommand not found\n");
			write(2, error_message, strlen(error_message));	
		}
	}
	free(buf);
	return (0);
}
