#include "shell.h"
/**
 * ccmp - ...
 * @s1: ...
 * @s2: ...
 * Return: ...
 */
int ccmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] != '\0')
{
if (s1[i] != s2[i])
break;
i++;
}
return (s1[i] - s2[i]);
}
/**
 * ccat - ...
 * @s1: ...
 * @s2:  ...
 * Return: ...
 */
char *ccat(char *s1, char *s2)
{
char *ch =  NULL;
int ls1 = _llen(s1);
int ls2 = _llen(s2);

ch = malloc(sizeof(*ch) * (ls1 + ls2 + 1));
_ccpy(s1, ch);
_ccpy(s2, ch + ls1);
ch[ls1 + ls2] = '\0';
return (ch);
}
/**
 * _sstr - ...
 * @s1: ..
 * @s2: ...
 * Return: ...
 */
int _sstr(char *s1, char *s2)
{
int i = 0;
int m = 0;
while (s1[i] != '\0')
{
if (sstrc(s2, s1[i]) == NULL)
break;
m++;
i++;
}
return (m);
}
/**
 * sstrcs - ...
 * @s1: ...
 * @s2: ...
 * Return: ....
 */


int sstrcs(char *s1, char *s2)
{
int ln = 0, i;

for (i = 0; s1[i] != '\0'; i++)
{
if (sstrc(s2, s1[i]) != NULL)
break;
ln++;
}
return (ln);
}
/**
 * sstrc - ...
 * @s1: ...
 * @c: ...
 * Return: ...
 */
char *sstrc(char *s1, char c)
{
int i = 0;

for (; s1[i] != c && s1[i] != '\0'; i++)
;
if (s1[i] == c)
return (s1 + i);
else
return (NULL);
}
