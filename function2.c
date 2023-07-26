#include "shell.h"
/**
 * _tokenizer - ...
 *@s1: ...
 *@s2: ...
 *
 *Return: array of tokens
 */

char **_tokenizer(char *s1, char *s2)
{
int nd = 0;
char **a = NULL;
char *tn = NULL;
char *sptr = NULL;

tn = _strtok(s1, s2, &sptr);

while (tn != NULL)
{
a = _rllc(a, sizeof(*a) * nd, sizeof(*a) * (nd + 1));
a[nd] = tn;
tn = _strtok(NULL, s2, &sptr);
nd++;
}
a = _rllc(a, sizeof(*a) * nd, sizeof(*a) * (nd + 1));
a[nd] = NULL;

return (a);
}
/**
 *_print - ...
 *@s1: ...
 *@s2: ...
 *Return: ...
 */
void _print(char *s1, int s2)
{
int i = 0;

for (; s1[i] != '\0'; i++)
write(s2, &s1[i], 1);
}
/**
 *r_line - ...
 *@s1: ...
 *Return: void
 */

void r_line(char *s1)
{
int i = 0;

while (s1[i] != '\0')
{
if (s1[i] == '\n')
break;
i++;
}
s1[i] = '\0';
}
/**
 *_cpy - ...
 *@s1: ...
 *@dst: ...
 * Return: ...
 */

void _cpy(char *s1, char *dst)
{
int i = 0;

for (; s1[i] != '\0'; i++)
dst[i] = s1[i];
dst[i] = '\0';
}

/**
 *_len - ....
 *@s1: ...
 * Return: ...
 */

int _len(char *s1)
{
int ln = 0;

if (s1 == NULL)
return (ln);
for (; s1[ln] != '\0'; ln++)
	;
return (ln);
}

