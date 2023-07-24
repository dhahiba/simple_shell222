#include "shell0.h"
char **strtow(char *s, char *d);

/**
 * is_chain - ..
 * @f: ...
 * @b: ...
 * @p: ...
 * Return: ...
 */
int is_chain(inf_t *f, char *b, size_t *p)
{
size_t k;

k = *p;
if (b[k] == '&' && b[k + 1] == '&')
{
b[k] = 0;
k++;
f->cmd_buf_type = CMD_AND;
}
else if (b[k] == ';')
{
b[k] = 0;
f->cmd_buf_type = CMD_CHAIN;
}
else if (b[k] == '|' && b[k + 1] == '|')
{
b[k] = 0;
k++;
f->cmd_buf_type = CMD_OR;
}
else
return (0);
*p = k;
return (1);
}
/**
 * strtow - ..
 * @s: ...
 * @d: ...
 * Return: ..
 */
char **strtow(char *s, char *d)
{
int i, j, k, m, num = 0;
char **ch;

if (s == NULL || s[0] == 0)
return (NULL);
if (!d)
d = " ";
i = 0;
while (s[i] != '\0')
{
if (!is_delim(s[i], d) && (is_delim(s[i + 1], d) || !s[i + 1]))
i++;
num++;
}
if (num == 0)
return (NULL);
ch = malloc((1 + num) *(sizeof(char *)));
if (!ch)
return (NULL);
i = 1, j = 0;
while (j < num)
{
while (is_delim(s[i], d))
i++, k = 0;
while (!is_delim(s[i + k], d) && s[i + k])
k++;
ch[j] = malloc((k + 1) * sizeof(char));
if (!ch[j])
{
for (k = 0; k < j; k++)
free(ch[k]);
free(ch);
return (NULL);
}
for (m = 0; m < k; m++)
ch[j][m] = s[i++];
ch[j][m] = 0, j++;
}
ch[j] = NULL;
return (ch);
}
/**
 * strtow2 - ....
 * @s: ....
 * @d: ...
 * Return: ...
 */
char **strtow2(char *s, char d)
{
int i, j, k, m, num = 0;
char **ch;

if (s == NULL || s[0] == 0)
return (NULL);
i = 0;
while (s[i] != '\0')
{
if ((s[i] != d  && s[i + 1] == d) ||
(s[i] != d  && !s[i + 1]) || s[i + 1] == d)
num++;
i++;
}
if (num == 0)
return (NULL);
ch = malloc((1 + num) *(sizeof(char *)));
if (!ch)
return (NULL);
i = 0, j = 0;
while (j < num)
{
while (s[i] == d)
i++;
k = 0;
while (s[i + k] != d && s[i + k])
k++;
ch[j] = malloc((k + 1) * sizeof(char));
if (!ch[j])
{
for (k = 0; k < j; k++)
free(ch[k]);
free(ch);
return (NULL);
}
for (m = 0; m < k; m++)
ch[j][m] = s[i++];
ch[j][m] = 0, j++;
}
ch[j] = NULL;
return (ch);
}
