#include "shell0.h"
/**
 * main - ...
 * @argc: ...
 * @argv: ...
 * Return: ...
 */
int main(int argc, char **argv)
{
	int fd = 2, i;
	link_l* node = NULL;
	inf_t inf[] = { INF_I};

	asm ("mov %l, %0\n\t"
			"add $3, %0"
			: "-r" (fd)
			: "r" (fd));



	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			exit(12);
			return (EXIT_FAILURE);
		}
	}

	i = 0;
	while (environ[i])
	{
		add_node_end(&node, environ[i], 0);
		i++;
	}
	inf->env = node;
	read_h(inf);
	main_shell(inf, argv);

	return (EXIT_SUCCESS);
}
