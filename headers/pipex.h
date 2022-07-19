#ifndef PIPEX_H
# define PIPEX_H

// perror()
# include <stdio.h>
# include <errno.h>
// strerror()
# include <string.h>
// exit()
# include <stdlib.h>
// access()
# include <unistd.h>
// open()
# include <fcntl.h>
// wait()
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	char *input_path;
	char *output_path;
	char *input_program_full;
	char **input_program_parameters; 
	char *input_program_name; 
	char *output_program_full; 
	
} t_data;

void pipe_operator(t_data *data);
void exit_program(char *error_m);
void args_check (int argc, char *argv[], t_data *data);
char	**ft_split(char const *s, char c);

#endif