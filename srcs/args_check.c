#include "pipex.h"

void find_program(t_data *data, char *program_name, int program)
{
	int i;
	char *path;

	i = 0;
	while (data->env_paths[i])
	{
		path = join_bar(data->env_paths[i], program_name);
		if (access(path, F_OK) == 0)
		{
			if(program == 0)
				data->program1_path = path;
			else
				data->program2_path = path; 
		}
		//free(join_bar);
		i++;
	}
}

void find_path_env(t_data *data, char *envp[])
{
	char	*paths;

	paths = NULL;
	int i = 0;
	while(envp[i])
	{
		if(ft_strncmp("PATH", envp[i], 4) == 0)
			paths = ft_strdup(envp[i] + 5);
	i++;
	}
	if (paths == NULL)
		exit_program("PATH variable not found");
	data->env_paths = ft_split(paths, ':');
	find_program(data, data->input_program_parameters[0], 0);
	find_program(data, data->output_program_parameters[0], 1);
}



void args_check(int argc, char *argv[], char *envp[], t_data *data)
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
	
	data->input_program_parameters = ft_split(argv[2] , ' ');
	data->output_program_parameters = ft_split(argv[3] , ' ');
	find_path_env(data, envp);
}
