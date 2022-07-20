#include "pipex.h"

void memory_handle(t_data *data)
{
	int i;
	i = 0;
	if(data->input_program_parameters != NULL)
	{
		while (data->input_program_parameters[i])
		{
			free(data->input_program_parameters[i]);
			i++;
		}
		free(data->input_program_parameters); 
	}
	i = 0;
	if(data->output_program_parameters != NULL)
	{
		while (data->output_program_parameters[i])
		{
			free(data->output_program_parameters[i]);
			i++;
		}
		free(data->output_program_parameters); 
	}
	i = 0;
	if (data->env_paths[i] != NULL)
	{
		while (data->env_paths[i])
		{
			free(data->env_paths[i]);
			i++;
		}
		free(data->env_paths);
	}
	if(data->program1_path != NULL)
		free(data->program1_path);
	if(data->program2_path != NULL)
		free(data->program2_path);
}

void exit_program(char *error_m, t_data *data)
{
	memory_handle(data);
	perror(error_m);
	exit(1);
}