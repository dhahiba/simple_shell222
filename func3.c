#include "shell0.h"
/**
 * _atoi - ...
 * @s: ...
 * Return: ...
 */
int _atoi(char *s)
{
unsigned int r;
int i, n, f = 0, p;

n = 1;
i = 0;
while (s[i] != '\0' && f != 2)
{
if (s[i] == '-')
n = n *  -1;
if (s[i] >= '0' && s[i] <= '9')
{
f  =  1;
r = r * 10;
r = r + (s[i] - '0');
}
else if (f == 1)
f = 2;
i++;
}
if (n == -1)
p = -r;
else
p = r;
return (p);
}
/**
 * replace_string - ...
 * @ch: ...
 * @n: ...
 * Return: ...
 */
int replace_string(char **ch, char *n)
{
free(*ch);
*ch = n;
return (1);
}
/**
 * replace_vars - ...
 * @f: ....
 * Return: ..
 */
int replace_vars(inf_t *f)
{
link_l *n;
int i;

i = 0;
while (f->argv[i])
{
if (f->argv[i][0] != '$' || !f->argv[i][1])
{
i++;
continue;
}
if (!_strcmp(f->argv[i],  "$?"))
{
replace_string(&(f->argv[i]), _strdup(convert_number(f->status, 10, 0)));
i++;
continue;
}
if (!_strcmp(f->argv[i], "$$"))
{
replace_string(&(f->argv[i]), _strdup(convert_number(getpid(), 10, 0)));
i++;
continue;
}
n = node_starts_with(f->env, &f->argv[i][1], '=');
if (n)
{
replace_string(&(f->argv[i]), _strdup(_strchr(n->s, '=') + 1));
i++;
continue;
}
replace_string(&(f->argv[i]), _strdup(""));
i++;
}
return (0);
}
/**
 * replace_alias - ...
 * @f: ...
 * Return: ...
 */
int replace_alias(inf_t *f)
{
link_l *n;
char *p;
int i = 0;

while (i < 10)
{
n = node_starts_with(f->alias, f->argv[0], '=');
if (!n)
return (0);
free(f->argv[0]);
p = _strchr(n->s, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
f->argv[0] = p;
i++;
}
return (1);
}
/**
 * check_chain - ...
 * @f: ...
 * @b: ..
 * @i: ..
 * @l: ...
 */
void check_chain(inf_t *f, char *b,size_t *p, size_t i, size_t l)
{
size_t k;

k = *p;
if (f->cmd_buf_type == CMD_AND)
{
if (f->status)
{
b[i] = 0;
k = l;
}
}
if (f->cmd_buf_type == CMD_OR)
{
if (!f->status)
{
b[i] = 0;
k = l;
}
}
*p = k;
}
