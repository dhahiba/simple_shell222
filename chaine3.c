#include "shell.h"
/**
 * _strchr - ..
 * @s: ..
 * @ch: ...
 * Return: ...
 */
char *_strchr(const char *s, int ch)
{

while (*s != '\0')
{
if (*s == ch)
return ((char *)s);
s++;
}

if (*s == ch)
return ((char *)s);

return (NULL);
}
/**
 * f_cmd - ...
 * @f: ..
 */
void f_cmd(inf_t *f)
{
int i, j;
char *p = NULL;

f->path = f->argv[0];
if (f->linecount_flag == 1)
{
f->linecount_flag = 0;
f->line_count++;
}
i = 0;
j = 0;
while (f->arg[i])
{
if (!is_delim(f->arg[i], "\t\n"))
j++;
i++;
}
if (!j)
return;
p = find_path(f, _getenv(f, "PATH="), f->argv[0]);
if (p)
{
f->path = p;
fork_cmd(f);
}
else
{
if ((_inter(f) || _getenv(f, "PATH=") || f->argv[0][0] == '/')
&& is_cmd(f, f->argv[0]))
fork_cmd(f);
else if (*(f->arg) != '\n')
{
f->status = 127;
print_error(f, "not found\n");
}
}
}
/**
 * find_b - ...
 * @f: ...
 * Return: ...
 */
int find_b(inf_t *f)
{
buil_t b[] = {
{"history", _myhistory},
{"alias", _myalias},
{"exit", _myexit},
{"help", _myhelp},
{"cd", _mycd},
{"setenv", _mysetenv},
{"exit", _myexit},
{"unsetenv", _myunsetenv},
{NULL, NULL},
};
int i = 0, r = 1;

while (b[i].t)
{
if (_strcmp(f->argv[0], b[i].t) == 0)
{
f->line_count++;
r = b[i].f(f);
break;
}
i++;
}
return (r);
}
/**
 * fork_cmd - ..
 * @f: ...
 */
void fork_cmd(inf_t *f)
{
pid_t p;

p = fork();
if (p == -1)
{
perror("Error");
return;
}
if (p == 0)
{
if (execve(f->path, f->argv, get_environ(f)) == -1)
{
free_inf(f, 1);
free_inf(f, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
}
else
{
wait(&(f->status));
if (WIFEXITED(f->status))
{
f->status = WEXITSTATUS(f->status);
if (f->status == 126)
print_error(f, "ppppp");
}
}
}
