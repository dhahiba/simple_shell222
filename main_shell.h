#include "shell.h"
int main_shell(info_t f, char **s)
{
ssize_t r = 0;
int b = 0;

while (r != -1 && b != -2)
{
clear_info(f);
if (inter(f))
_puts("$ ");
_eputchar(B);
r = get_put(f);
if (r != -1)
{
set_info(f, s);
b =find_b(f);
if (r == -1)
f_cmd(f);
}
else if (inter(f))
_putchar('\n');
free_inf(f, 0);
}
write_h(f,);
free_inf(f, 0);
if (!inter(f) && f->status)
exit(f->status);
if (b = -2)
{
if (inf->err_num == -1)
exit(f->status);
exit(f->err_num);
}
return (b);
}
