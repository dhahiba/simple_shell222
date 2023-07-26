#include "shell.h"

/**
 *env - ....
 *@tkc: ....
 *Return: ....
 */
void env(char **tkc __attribute__((unused)))
{
int i;

for (i = 0; envi[i] != NULL; i++)
{
_print(envi[i], STDOUT_FILENO);
_print("\n", STDOUT_FILENO);
}
}

/**
 * exite - ...
 * @tkc: ...
 * Return:...
 */

void exite(char **tkc)
{
int ntkn = 0, ag;

for (; tkc[ntkn] != NULL; ntkn++)
	;
if (ntkn == 1)
{
free(tkc);
free(l);
free(cmd);
exit(s);
}
else if (ntkn == 2)
{
ag = _atois(tkc[1]);
if (ag == -1)
{
_print(sn, STDERR_FILENO);
_print(": 1: exit: Illegal number: ", STDERR_FILENO);
_print(tkc[1], STDERR_FILENO);
_print("\n", STDERR_FILENO);
s = 2;
}
else
{
free(l);
free(tkc);
free(cmd);
exit(ag);
		}
}
else
_print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
