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

int pid = fork(); //process id = fork. 
if (pid == -1)
	return (1); 

if (pid == 0)
{
	printf("This is the child process \n");
	//Child process. 
}
else
{
	//Parent process. 
	wait(NULL);
	printf("Uhull this is the parent process working!! \n");
}

}