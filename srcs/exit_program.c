#include "pipex.h"

void memory_handle(t_data *data)
{
	
	int i;
	i = 0;
	while (data->input_program_parameters[i])
	{
		free(data->input_program_parameters[i]);
		i++;
	}
	i = 0;
	while (data->output_program_parameters[i])
	{
		free(data->output_program_parameters[i]);
		i++;
	}
	free(data->input_program_parameters); 
	free(data->output_program_parameters); 
	i = 0;
	while (data->env_paths[i])
	{
		free(data->env_paths[i]);
		i++;
	}
	free(data->env_paths);
	free(data->program1_path);
	free(data->program2_path);
}

void exit_program(char *error_m)
{
	perror(error_m);
	exit(1);
}