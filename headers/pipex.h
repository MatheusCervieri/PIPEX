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

void pipe_operator(void);
void exit_program(char *error_m);

#endif