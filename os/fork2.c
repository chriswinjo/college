#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
pid_t pid = fork();
if(pid==0)
{
  //printf("hello world");
  printf("child =>%d, ppid,pid%d",getppid(),getpid());
  exit(EXIT_SUCCESS);
}

else if(pid>0)
{
 printf("main task");
}


else
{ 
  printf("unable to create");
}

return EXIT_SUCCESS;
}

