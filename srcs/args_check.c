#include "pipex.h"


void args_check(int argc, char *argv[], t_data *data)
{
	if (argc != 5)
	{
		perror("invalid number of arguments");
		exit(2);
	}
	if (access(argv[1], F_OK) != 0) //F_OK check the existence. 
	{
		exit_program("Cannot access the file ");
	}
	if (access(argv[4], F_OK) != 0) //F_OK check the existence. 
	{
		exit_program("Cannot access the file ");
	}
	data->input_path = argv[1];
	data->output_path = argv[4];
	data->input_program_full = argv[2];
	data->input_program_parameters = ft_split(argv[2] , ' ');
}
