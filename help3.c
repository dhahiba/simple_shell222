#include "shell.h"
/**
 * _sstrtok - ...
 * @ch: ...
 * @d: ...
 * @sp: ...
 * Return: ....
 */
char *_sstrtok(char *ch, char *d, char **sp)
{
char *f;

if (ch == NULL)
ch = *sp;
if (*ch == '\0')
{
*sp = ch;
return (NULL);
}
ch += _sstr(ch, d);
if (*ch == '\0')
{
*sp = ch;
return (NULL);
}
f = ch + _sstr(ch, d);
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
 * _aatois - ...
 * @s:...
 * Return: ...
 */
int _aatois(char *s)
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
 * _rrllc - ....
 * @p: ....
 * @sizep: ...
 * @nsize: ...
 * Return: ...
 */
void *_rrllc(void *p, unsigned int sizep, unsigned int nsize)
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
 * cctrlhandler - ...
 * @snum: ...
 * Return: ...
 */
void cctrlhandler(int snum)
{
if (snum == SIGINT)
_pprint("\n($) ", STDIN_FILENO);
}

/**
 * rr_comment - ....
 * @ipt: input to be used
 * Return: void
 */
void rr_comment(char *ipt)
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
