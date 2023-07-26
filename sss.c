#include "shell.h"
/**
 * parse_input - ..
 * @input: ...
 * @args: ...
 * Return: ...
 */
int parse_input(char *input, char *args[])
{
int arg_count = 0;
char *token = strtok(input, " \t\n");

while (token != NULL)
{
args[arg_count++] = token;
token = strtok(NULL, " \t\n");
}
args[arg_count] = NULL;
return (arg_count);
}
/**
 * execute_command - ...
 * @args: ...
 */

void execute_command(char *args[])
{
int status;
pid_t pid = fork();
if (pid < 0)
{
perror("fork");
}
else if (pid == 0)
{

execvp(args[0], args);
perror("execvp");
exit(1);
}
else
{
waitpid(pid, &status, 0);
}
}
