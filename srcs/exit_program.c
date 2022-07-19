#include "pipex.h"

void exit_program(char *error_m)
{
	perror(error_m);
	exit(1);
}