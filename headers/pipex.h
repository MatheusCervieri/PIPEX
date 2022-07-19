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

} t_data;

void pipe_operator(void);
void exit_program(char *error_m);
void args_check (int argc, char *argv[], t_data *data);

#endif