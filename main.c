#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main ()
{
//entender como executar um comando bash usando funções de C
//execve - essa função abre o programa que queremos executar, mas ela tem um problema, ela abre o programa 
//no mesmo processo que queremos.  

//if we try to use execve function we will subscribe the current process. That's why we need to use fork function.
//This way we can have a child process that will run the progran that we open with exect function and 
//after that we are coming back to the parent process. 

//The fork function breaks the execution process into two process. There is a parent process and a child process;




char *cmd = "/usr/bin/ls";  //PATH of the comand! 
char *argVec[] = {"ls", "-a" , NULL};
char *envVec[] = {NULL};

//The next step is to learn about pipe. Pipe is a buffer that saves memory. That you can write and get data from.
//It saves a array of fds with two values. The first fd is de read buffer file and the second is the write file.
//Both projects has their own fds, so, we have two close 4 fds during the process. 
//We will use write and read functions to read the fds. 
int fd[2];
if(pipe(fd) == -1)
{
	printf("Error \n");
	return (1);
}

int pid = fork(); //process id = fork.  So, when i use fork, everything is executing twice. 
//The child and the parent will execute the same code. 
if (pid == -1) // since it replaces the process value, the return value is always -1. 
	return (1); 

if (pid == 0) //id zero meaning that we are in the child process. 
{
	int baleia = 42; 
	close(fd[0]); //here we close de read fd, because in this process we will wirte.
	write(fd[1], &baleia, sizeof(int)); //We are writing in the child process in a way we can read in the parent process.
	/*if(execve(cmd, argVec, envVec) == -1) 
		perror("Culd not execute execve"); 
	*/
	printf("This is the child process \n"); //so it is not going to execute, because execve subscribe the process
	//so, we are subscribing the child process with the process of a new progran. In this case, LS.
	//Child process. 
	close(fd[1]);
}
else
{
	//Parent process. 
	wait(NULL);
	int readfromchild;
	read(fd[0], &readfromchild, sizeof(int)); //we are reading what we write in the child process. 
	printf("Uhull this is the parent process working!! - We read the VALUE: %i from the child process\n", readfromchild);
}

}