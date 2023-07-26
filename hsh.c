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
sstart(c, tc);
free(c);
}
free(cmds);
}
free(lk);
exit(ss);
}
}
/**
 * sstart - ...
 * @c: ...
 * @tc: ...
 */
void sstart(char **c, int tc)
{
pid_t PID;

if (tc == 1 || tc == 3)
{
PID = fork();
if (PID == 0)
eexecute(c, tc);
else
{
waitpid(PID, &ss, 0);
ss >>= 8;
}
}
else
eexecute(c, tc);
}
