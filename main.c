#include "shell.h"
char **envi= NULL;
char **cmds = NULL;
char *lk = NULL;
char *sns = NULL;
int ss = 0;
/**
 * main - ...
 * @argc: ...
 * @argv: ....
 * Return: ...
 */
int main(int argc __attribute__((unused)), char **argv)
{
char **c = NULL;
int i, arg_count, st, tc = 0;
size_t n = 0;
pid_t pid;
char command[MAX_COMMAND_LENGTH];
char *args[MAX_ARGUMENTS];

signal(SIGINT, cctrlhandler);
sns = argv[0];
while (1)
{
hhandle_mode();
_pprint(" ($) ", STDOUT_FILENO);
fgets(command, sizeof(command), stdin);
arg_count = parse_input(command, args);
if (arg_count > 0)
execute_command(args);
}
while (1)
{
hhandle_mode();
_pprint(" ($) ", STDOUT_FILENO);
if (getline(&lk, &n, stdin) == -1)
free(lk), exit(ss);
printf("11");
if (strcmp(argv[0], "cd") == 0)
change_directory(argv);
else if (strcmp(argv[0], "exit") == 0)
printf("Exiting shell...\n"), exit(0);
else
{
pid = fork();
if (pid < 0)
perror("fork");
else if (pid == 0)
{
execvp(argv[0], argv), perror("execvp"), exit(1); }
else
wait(&st); }
rr_line(lk);
rr_comment(lk), cmds = _ttokenizer(lk, ";");
for (i = 0; cmds[i] != NULL; i++)
{
c = _ttokenizer(cmds[i], " ");
if (c[0] == NULL)
{ free(c);
break; }
tc = pp_command(c[0]);
sstart(c, tc);
free(c); }
free(cmds); }
free(lk);
return (0); }
