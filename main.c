#include "shell.h"
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
