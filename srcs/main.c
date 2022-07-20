#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	args_check(argc, argv, envp, &data);
	pipe_operator(&data);
	memory_handle(&data);
	return (0);
}