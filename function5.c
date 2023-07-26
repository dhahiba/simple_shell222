#include "shell.h"
/**
 * execute_command - Execute the given command.
 * @arguments: The arguments of the command.
 */
void execute_command(char **arguments)
{
pid_t pid;
int status;

pid = fork();
if (pid < 0)
{
perror(":( Fork failed");
exit(1);
}
else if (pid == 0)
{

if (execvp(arguments[0], arguments) == -1)
{
perror(":( Execution failed");
exit(1);
}
}
else
{

waitpid(pid, &status, 0);
}
}
/**
 * tokenize_command - Tokenize the input command into arguments.
 * @command: The command to tokenize.
 * @arguments: An array to store the arguments.
 *
 * Return: The number of arguments.
 */
int tokenize_command(char *command, char **arguments)
{
int arg_count = 0;
char *token;

token = strtok(command, " \t\n");
while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
{
arguments[arg_count++] = token;
token = strtok(NULL, " \t\n");
}
arguments[arg_count] = NULL;

return (arg_count);
}
