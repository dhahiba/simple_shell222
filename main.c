#include "shell.h"
char **cmd = NULL;
char *l = NULL;
char *sn = NULL;
int s = 0;
/**
 * main - ...
 * @argc: ...
 * @argv: ....
 * Return: ...
 */


int main(int argc __attribute__((unused)), char **argv)
{
char **c = NULL;
int i, tc = 0;
size_t n = 0;

signal(SIGINT, ctrlhandler);
sn = argv[0];
while (1)
{

handle_mode();
_print(" ($) ", STDOUT_FILENO);
if (argv[0][0] == 'e' && argv[0][1] == 'x')
if (argv[0][2] == 'i' && argv[0][3] == 't')
_exite(argc, argv);
if (getline(&l, &n, stdin) == -1)
{
free(l);
exit(s);
}
r_line(l);
r_comment(l);
cmd = _tokenizer(l, ";");
for (i = 0; cmd[i] != NULL; i++)
{
c = _tokenizer(cmd[i], " ");
if (c[0] == NULL)
{
free(c);
break;
}
tc = p_command(c[0]);
start(c, tc);
free(c);
}
free(cmd);
}
free(l);
return (s);
}
