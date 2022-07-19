#include "pipex.h"

void args_check (int argc, char *argv[], )
{
	if (argc != 5)
	{
		perror("invalid number of arguments");
		exit(2);
	}
}