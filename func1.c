#include "shell0.h"
/**
 * input_buf - ...
 * @f: ...
 * @b: ...
 * @l: ..
 * Return: ...
 */
ssize_t input_buf(inf_t *f, char **b, size_t *l)
{
size_t p = 0;
ssize_t r = 0;

if (!*l)
{
free(*b);
*b =  NULL;
signal(SIGINT, _sigintHandler);
#if USE_GETLINE
r = _getline(b, &p, stdin);
#else
r = _getline(f, b, &p);
#endif
if (r > 0)
{
if ((*b)[r - 1] == '\n')
{
(*b)[r - 1] = '\0';
r--;
}
f->linecount_flag = 1;
remove_comments(*b);
b_history(f, *b, f->histcount++);
if (_strchr(*b, ';'))
{
*l = r;
f->cmd_buf = b;
}
}
}
return (r);
}
/**
 * get_input - ...
 * @f: ..
 * Return: ..
 */
ssize_t get_input(inf_t *f)
{
char **bp = &(f->arg), *p;
ssize_t r;
static char *b;
static size_t l, i, j;

_putchar(B);
r = input_buf(f, &b, &l);
if (r == -1)
return (-1);
if (l)
{
j = i;
p = b + i;
check_chain(f, b, &j, i, l);
for (; j < l; j++)
{
if (is_chain(f, b, &j))
break;
j++;
}
i = j + 1;
if (i >= l)
{
i = 0;
l = 0;
f->cmd_buf_type = CMD_NORM;
}
*bp = p;
return (_strlen(p));
}
*bp = b;
return (r);
}
/**
 * _putsfd - ...
 * @s: ..
 * @f: ...
 * Return: ...
 */
int _putsfd(char *s, int f)
{
int i;
if (!s)
return (0);
i = 0;
while (*s)
i = i + _putfd(*s++, f);
return (i);
}
/**
 * _putfd - ...
 * @c: ..
 * @f: ..
 * Return: ...
 */
int _putfd(char c, int f)
{
static char b[W];
static int i;

if (c == B || i >= W)
{
write(f, b, i);
i = 0;
}
if (c != B)
b[i++] = c;
return (1);
}
/**
 * _eputchar - ...
 * @c: ...
 * Return: ..
 */
int _eputchar(char c)
{
static char b[W];
static int i;

if (c == B || i >= W)
{
write(2, b, i);
i = 0;
}
if (c != B)
b[i++] = c;
return (1);
}
