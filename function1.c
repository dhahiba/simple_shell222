#include "shell.h"

/**
 * p_command - ...
 * @cm: ...
 * Return: ....
 */

int p_command(char *cm)
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
p = check_p(cm);
if (p != NULL)
{
free(p);
return (3);
}
return (-1);
}

/**
 * execute - ....
 * @tkn_cmd: ...
 * @tcmd: type of the command
 *
 * Return: void
 */
void execute(char **tkn_cmd, int tcmd)
{
void (*func)(char **command);

if (tcmd == 1)
{
if (execve(tkn_cmd[0], tkn_cmd, NULL) == -1)
{
perror(getenv("PWD"));
exit(2);
}
if (tcmd == 3)
{
if (execve(check_p(tkn_cmd[0]), tkn_cmd, NULL) == -1)
{
perror(get_env("PWD"));
exit(2);
}
}
if (tcmd == 2)
{
func = _getfunc(tkn_cmd[0]);
func(tkn_cmd);
}
if (tcmd == -1)
{
_print(sn, STDERR_FILENO);
_print(": 1: ", STDERR_FILENO);
_print(tkn_cmd[0], STDERR_FILENO);
_print(": not found\n", STDERR_FILENO);
s = 127;
}
}
}
/**
 * check_p - ...
 * @cm: ...
 * Return: ...
 */
char *check_p(char *cm)
{
char **array = NULL;
char *t1, *t2, *pc;
char *p = get_env("PATH");
int i;

if (p == NULL || _len(p) == 0)
return (NULL);
pc = malloc(sizeof(*pc) * (_len(p) + 1));
_cpy(p, pc);
array = _tokenizer(pc, ":");
for (i = 0; array[i] != NULL; i++)
{
t2 = cat(array[i], "/");
t1 = cat(t2, cm);
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
 * _getfunc - ...
 * @cm: ...
 * Return: ...
 */
void (*_getfunc(char *cm))(char **)
{
int i;
f_map m[] = {
{"env", env}, {"exit", exite}
};

for (i = 0; i < 2; i++)
{
if (cmp(cm, m[i].cname) == 0)
return (m[i].f);
}
return (NULL);
}

/**
 * get_env - ...
 * @n: ...
 *
 * Return: ...
 */
char *get_env(char *n)
{
char **my_env;
char *pp;
char *nc;

for (my_env = environ; *my_env != NULL; my_env++)
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
