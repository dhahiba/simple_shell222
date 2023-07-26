#include "shell.h"

/**
 * handle_mode - ...
 *
 * Return: void
 */

void handle_mode(void)
{
char **c = NULL;
int i, tc = 0;
size_t n = 0;

if (!(isatty(STDIN_FILENO)))
{
while (getline(&l, &n, stdin) != -1)
{
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
exit(s);
}
}
/**
 * start - ...
 * @c: ...
 * @tc: ...
 *
 * Return: ...
 */

void start(char **c, int tc)
{
pid_t PID;

if (tc == 1 || tc == 3)
{
PID = fork();
if (PID == 0)
execute(c, tc);
else
{
waitpid(PID, &s, 0);
s >>= 8;
}
}
else
execute(c, tc);
}
