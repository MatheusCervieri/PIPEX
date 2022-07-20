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
# include "ft_printf.h"

typedef struct s_data
{
	char *input_path;
	char *output_path;
	char **input_program_parameters; 
	char **output_program_parameters;
	char **env_paths;
	char *program1_path;
	char *program2_path;
	
} t_data;

void 	pipe_operator(t_data *data);
void exit_program(char *error_m, t_data *data);
void 	args_check(int argc, char *argv[], char *envp[], t_data *data);
char	**ft_split(char const *s, char c);
char 	*join_bar(char *s1, char *s2);
void init_struct(t_data *data);


int		ft_strncmp(const char *s1, const char *s2, size_t n);
void memory_handle(t_data *data);



#endif