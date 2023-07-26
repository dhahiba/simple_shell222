#include "shell.h"
/**
 *_strtok - ...
 *@ch: ...
 *@d: ...
 *@sp: ...
 *Return: ....
 */
char *_strtok(char *ch, char *d, char **sp)
{
char *f;

if (ch == NULL)
ch = *sp;
if (*ch == '\0')
{
*sp = ch;
return (NULL);
}
ch += _str_(ch, d);
if (*ch == '\0')
{
*sp = ch;
return (NULL);
}
f = ch + _str_(ch, d);
if (*f == '\0')
{
*sp = f;
return (ch);
}
*f = '\0';
*sp = f + 1;
return (ch);
}
/**
 * _atois - ...
 * @s:...
 *
 * Return: ...
 */
int _atois(char *s)
{
unsigned int n = 0;
do {
if (*s == '-')
return (-1);
else if ((*s < '0' || *s > '9') && *s != '\0')
return (-1);
else if (*s >= '0'  && *s <= '9')
n = (n * 10) + (*s - '0');
else if (n > 0)
break;
} while (*s++);
return (n);
}
/**
 * _rllc - ....
 * @p: ....
 * @sizep: ...
 * @nsize: ...
 *
 * Return: ...
 */
void *_rllc(void *p, unsigned int sizep, unsigned int nsize)
{
void *b;
unsigned int i;

if (p == NULL)
{
b = malloc(nsize);
return (b);
}
else if (nsize == sizep)
return (p);
else if (nsize == 0 && p != NULL)
{
free(p);
return (NULL);
}
else
{
b = malloc(nsize);
if (b != NULL)
{
for (i = 0; i < min(sizep, nsize); i++)
*((char *)b + i) = *((char *)p + i);
free(p);
return (b);
}
else
return (NULL);
}
}
/**
 * ctrlhandler -....
 * @snum: ...
 *
 * Return: ...
 */
void ctrlhandler(int snum)
{
if (snum == SIGINT)
_print("\n($) ", STDIN_FILENO);
}

/**
 * r_comment - ....
 * @ipt: input to be used
 *
 * Return: void
 */
void r_comment(char *ipt)
{
int i = 0;

if (ipt[i] == '#')
ipt[i] = '\0';
while (ipt[i] != '\0')
{
if (ipt[i] == '#' && ipt[i - 1] == ' ')
break;
i++;
}
ipt[i] = '\0';
}
