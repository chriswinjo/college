#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int fd1[2],fd2[2],n;
	char buffer[100],as[100];
	pid_t p;
	pipe(fd1);
	pipe(fd2);
	p=fork();
	if(p>0){
		printf("Parent pass value to child \n");
		printf("Enter data: ");
		fgets(as,100,stdin);
		write(fd1[1],as,100);
		wait(NULL);
	}
	if(p==0){
		read(fd1[0],buffer,100);
		printf("Child receives data");
		printf("\nBuffer:%s",buffer);
		printf("Child pass value to parent\n");
		printf("Enter Data:");
		fgets(as,100,stdin);
		write(fd2[1],as,100);
		exit(EXIT_SUCCESS);
	}
	if(p>0){
		read(fd2[0],buffer,100);
		printf("Parent receives data");
		printf("\nBuffer:%s",buffer);
	}
}

