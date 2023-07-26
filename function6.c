#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * _exite - ...
 * @arg: ....
 * @argv: ....
 * Return: ...
 *
 */
int _exite(int arg, char *argv[])
{
int i = 0;
char *argument[10];
int j;
char command[100];

if (arg <= 1)
{
printf("No command provided.\n");
return (1);
}
if (strcmp(argv[1], "exit") == 0)
{
if (arg == 2)
{
exit(0);
}
else
{
printf("Invalid usage of 'exit' command.\n");
return (1);
}}
while (argv[i] != NULL)
{
strcpy(command, argv[i]);
if (strcmp(command, "exit") == 0)
{
i++;
continue;
}
printf("Argument[%d] = %s\n", i, command);
for (j = 0; j < arg - i; j++)
argument[j] = argv[i + j];
argument[j] = NULL;
execvp(command, argument);
perror("execvp");
i++;
}
return (0);
}

