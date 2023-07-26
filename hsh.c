#include "shell.h"

/**
 * hhandle_mode - ...
 * Return: void
 */

void hhandle_mode(void)
{
char **c = NULL;
int i, tc = 0;
size_t n = 0;

if (!(isatty(STDIN_FILENO)))
{
while (getline(&lk, &n, stdin) != -1)
{
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
start(c, tc);
free(c);
}
free(cmds);
}
free(lk);
exit(ss);
}
}
