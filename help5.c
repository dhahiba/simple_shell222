#include "shell.h"

/**
 * pp_command - ...
 * @cm: ...
 * Return: ...
 */

int pp_command(char *cm)
{
int i;
char *ic[] = {"env", "exit", NULL};
char *p = NULL;

for (i = 0; cm[i] != '\0'; i++)
{
if (cm[i] == '/')
return (1);
}
for (i = 0; ic[i] != NULL; i++)
{
if (cmp(cm, ic[i]) == 0)
return (2);
}
p = ccheck_p(cm);
if (p != NULL)
{
free(p);
return (3);
}
return (-1);
}

/**
 * eexecute - ....
 * @tkn_cmd: ...
 * @tcmd: type of the command
 * Return: void
 */
void eexecute(char **tkn_cmd, int tcmd)
{
void (*func)(char **command);

if (tcmd == 1)
{
if (execve(tkn_cmd[0], tkn_cmd, NULL) == -1)
{
perror(gget_env("PWD"));
exit(2);
}
}
if (tcmd == 3)
{
if (execve(ccheck_p(tkn_cmd[0]), tkn_cmd, NULL) == -1)
{
perror(gget_env("PWD"));
exit(2);
}
}
if (tcmd == 2)
{
func = _ggetfunc(tkn_cmd[0]);
func(tkn_cmd);
}
if (tcmd == -1)
{
_pprint(sns, STDERR_FILENO);
_pprint(": 1: ", STDERR_FILENO);
_pprint(tkn_cmd[0], STDERR_FILENO);
_pprint(": not found\n", STDERR_FILENO);
ss = 127;
}
}

/**
 * ccheck_p - ...
 * @cm: ...
 * Return: ...
 */
char *ccheck_p(char *cm)
{
char **array = NULL;
char *t1, *t2, *pc;
char *p = gget_env("PATH");
int i;

if (p == NULL || _llen(p) == 0)
return (NULL);
pc = malloc(sizeof(*pc) * (_llen(p) + 1));
_ccpy(p, pc);
array = _ttokenizer(pc, ":");
for (i = 0; array[i] != NULL; i++)
{
t2 = ccat(array[i], "/");
t1 = ccat(t2, cm);
if (access(t1, F_OK) == 0)
{
free(t2);
free(array);
free(pc);
return (t1);
}
free(t1);
free(t2);
}
free(pc);
free(array);
return (NULL);
}

/**
 * _ggetfunc - ...
 * @cm: ...
 * Return: ...
 */
void (*_ggetfunc(char *cm))(char **)
{
int i;
func m[] = {
{"env", eenv}, {"exit", eexite}
};

for (i = 0; i < 2; i++)
{
if (ccmp(cm, m[i].ccname) == 0)
return (m[i].ff);
}
return (NULL);
}

/**
 * gget_env - ....
 * @n: ....
 * Return: the value of the variable as a string
 */
char *gget_env(char *n)
{
char **my_env;
char *pp;
char *nc;

for (my_env = envi; *my_env != NULL; my_env++)
{
for (pp = *my_env, nc = n;
*pp == *nc; pp++, nc++)
{
if (*pp == '=')
break;
}
if ((*pp == '=') && (*nc == '\0'))
return (pp + 1);
}
return (NULL);
}
