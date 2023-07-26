#include "shell.h"

/**
 * eenv - ....
 * @tkc: ...
 * Return: ....
 */
void eenv(char **tkc __attribute__((unused)))
{
int i;

for (i = 0; envi[i] != NULL; i++)
{
_pprint(envi[i], STDOUT_FILENO);
_pprint("\n", STDOUT_FILENO);
}
}

/**
 * eexite - ...
 * @tkc: ...
 * Return:...
 */

void eexite(char **tkc)
{
int ntkn = 0, ag;

for (; tkc[ntkn] != NULL; ntkn++)
	;
if (ntkn == 1)
{
free(tkc);
free(ls);
free(cmds);
exit(ss);
}
else if (ntkn == 2)
{
ag = _aatois(tkc[1]);
if (ag == -1)
{
_pprint(sns, STDERR_FILENO);
_pprint(": 1: exit: Illegal number: ", STDERR_FILENO);
_pprint(tkc[1], STDERR_FILENO);
_pprint("\n", STDERR_FILENO);
ss = 2;
}
else
{
free(lk);
free(tkc);
free(cmds);
exit(ag);
		}
}
else
_pprint("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
