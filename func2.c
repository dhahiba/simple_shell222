#include "shell.h"
/**
 * eputs - ...
 * @s: ...
 */
void eputs(char *s)
{
int i;

if (!s)
return;
i = 0;
while (s[i] != '\0')
{
_eputchar(s[i]);
i++;
}
}
/**
 * remove_comments - ...
 * @b: ...
 */
void remove_comments(char *b)
{
int i;

for (i = 0; b[i] != '\0'; i++)
{
if (b[i] == '&' && (!i || b[i - 1] == ' '))
{
b[i] = '\0';
break;
}
}
}
/**
 * convert_number - ...
 * @n: ..
 * @b: ...
 * @f: ..
 * Return: ...
 */
char *convert_number(long int n, int b, int f)
{
char *p;
char s = 0;
static char bf[100];
static char *a;
unsigned long m;

m = n;
if (n < 0 && !(f & CONVERT_UNSIGNED))
{
m = -n;
s = '-';
}
a = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
p = &bf[49];
*p = '\0';
do {
*--p = a[n % 10];
n = n / b;
} while (n != 0);
if (s)
*--p = s;
return (p);
}
/**
 * print_d - ...
 * @n: ...
 * @f: ...
 * Return: ..
 */
int print_d(int n, int f)
{
unsigned int abc, c;
int i, cn;
int (*__putchar)(char) = _putchar;

if (f == STDERR_FILENO)
__putchar = _eputchar;
cn = 0;
if (n < 0)
{
abc = -n;
__putchar('-');
cn++;
}
else
abc = n;
c = abc;
for (i = 1000000000; i > 1; i /= 10)
{
if (abc / i)
{
__putchar('0' + c / i);
cn++;
}
c = c % i;
}
__putchar('0' + c);
cn++;
return (cn);
}
/**
* _erratoi - ...
* @s: ...
* Return: ...
*/
int _erratoi(char *s)
{
unsigned long int r;
int i;

if (*s == '+')
s++;
i = 0;
r = 0;
while (s[i] != '\0')
{
if (s[i] >= '0' && s[i] <= '9')
{
r = r * 10;
r = r + (s[i] - '0');
if (r > INT_MAX)
return (-1);
}
else
return (-1);
i++;
}
return (r);
}
