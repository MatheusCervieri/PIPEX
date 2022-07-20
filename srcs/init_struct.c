#include "pipex.h"

void init_struct(t_data *data)
{
	//double pointer. 
	data->input_program_parameters = NULL;
	data->output_program_parameters = NULL;
	data->env_paths = NULL;
	data->program1_path = NULL;
	data->program2_path = NULL;
}