#include "shell.h"
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

/**
 * change_directory - ...
 * @args: ...
 */

void change_directory(char *args[])
{
if (args[1] == NULL)
{
fprintf(stderr, "cd: missing argument\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("cd");
}
}
}
/**
 * parse_input - ...
 * @input: ...
 * @args: ....
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
 * exit_shell: ...
 * Return: ....
 */
void exit_shell(void)
{
printf("Exiting shell...\n");
exit(0);
}
/**
 * main - ...
 * @argc: ...
 * @argv: ....
 * Return: ...
 */


int main(void)
{

char command[MAX_COMMAND_LENGTH];
char *args[MAX_ARGUMENTS];
int status;
int arg_count;

while (1)
{
printf("#cisfun$ ");
fgets(command, sizeof(command), stdin);

arg_count = parse_input(command, args);

if (arg_count > 0)
{
if (strcmp(args[0], "cd") == 0)
{
change_directory(args);
}
else if (strcmp(args[0], "exit") == 0)
{
exit_shell();
}
else
{
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
wait(&status);
}
}
}
}
signal(SIGINT, cctrlhandler);

return (0);
}
/**
while (1)
{
hhandle_mode();
_pprint(" ($) ", STDOUT_FILENO);
if (getline(&lk, &n, stdin) == -1)
{
free(lk);
exit(ss);
}
rr_line(lk);
rr_comment(lk);
cmds = _ttokenizer(lk, ";");
for (i = 0; cmds[i] != NULL; i++)
{
c = _ttokenizer(cmds[i], " ");
if (c[0] == NULL)
{
free(c);
break;
}
tc = pp_command(c[0]);
sstart(c, tc);
free(c);
}
free(cmds);
}
free(lk);
return (0);
}*/
