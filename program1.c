#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
  pid_t pid;
int status;
int n=20;

pid=fork();
if(pid==-1)
{
return (1);
}
printf("\n Fork successful!\n");
if(pid==0)
{
n=n*10;
printf("Child:I'm child , my process id is %d:\n",getpid());
printf("Child:My psrent process id is:%d\n",getppid());
printf("Child: Value of n=%d\n",n);
execl("/bin/ls","ls","-ls","/home/student/OS",(char*)0);
return (0);
}
else if(pid>0)
{
printf("Parent:I'm parent, my process id is %d\n",getpid());
printf("Parent:My parent is %d\n",getppid());
n=n*2;
printf("Parent: Vlaue of n=%d\n",n);
pid=wait(&status);
printf("Parent: My child process with id %d terminated\n",pid);
if(WIFEXITED(status))
{
printf("Parent: Child process exited with %d\n",WEXITSTATUS(status));
}
}
return (0);
}
