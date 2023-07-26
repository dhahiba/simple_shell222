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

signal(SIGINT, cctrlhandler);
sns = argv[0];
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
return (ss);
}
