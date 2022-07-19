#include "pipex.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	args_check(argc, argv, &data);
	pipe_operator(&data);
	return (0);
}