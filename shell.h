#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

ssize_t mygetline(char **myline, size_t *n, FILE *mystream);
int _acc_exe(const char *command);
size_t _strllen(const char *stringg);
size_t _echostr(const char *stringg);
size_t _execute_cmd(char *separated[]);
void _perror(const char *stringg);
char *_mystrcpy(char *mystr1, const char *oringstr);
int _mystrcmp(const char *mystr1,const char *mystr2, int numbb);
int _mystrcmp1(const char *mystr1,const char *mystr2);


#endif
