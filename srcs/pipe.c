#include "pipex.h"

void open_cmd()
{
	char *cmd = "/usr/bin/ls";  
	char *argVec[] = {"ls", "-a" , NULL};
	char *envVec[] = {NULL};
	if(execve(cmd, argVec, envVec) == -1) 
		exit_program("Couldn't open the program");
}

void pipe_operator()
{
	int fd[2];
	int pid1;

	if(pipe(fd) == -1)
		exit_program("Pipe function error");
	pid1 = fork();
	if(pid1 < 0)
		exit_program("Fork function error");
	if(pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		open_cmd();
		//child process. 
	}
	waitpid(pid1, NULL, 0);
}