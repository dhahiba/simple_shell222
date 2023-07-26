#include "shell.h"
/**
 *cmp - ...
 *@s1: ...
 *@s2: ....
 *
 * Return: ...
 */
int cmp(char *s1, char *s2)
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
 *cat - ...
 *@s1: ...
 *@s2:  ...
 * Return: ...
 */

char *cat(char *s1, char *s2)
{
char *ch =  NULL;
int ls1 = _len(s1);
int ls2 = _len(s2);

ch = malloc(sizeof(*ch) * (ls1 + ls2 + 1));
_cpy(s1, ch);
_cpy(s2, ch + ls1);
ch[ls1 + ls2] = '\0';
return (ch);
}
/**
 *_str - ...
 *@s1: ...
 *@s2: ...
 *Return: ...
 */
int _str(char *s1, char *s2)
{
int i = 0;
int m = 0;
while (s1[i] != '\0')
{
if (strc(s2, s1[i]) == NULL)
break;
m++;
i++;
}
return (m);
}
/**
 *strcs - ...
 *@s1: ...
 *@s2: ...
 *Return: ....
 */


int strcs(char *s1, char *s2)
{
int ln = 0, i;

for (i = 0; s1[i] != '\0'; i++)
{
if (strc(s2, s1[i]) != NULL)
break;
ln++;
}
return (ln);
}
/**
 *strc - ...
 *@s1: ...
 *@c: ...
 *Return: ...
 */
char *strc(char *s1, char c)
{
int i = 0;

for (; s1[i] != c && s1[i] != '\0'; i++)
;
if (s1[i] == c)
return (s1 + i);
else
return (NULL);
}

