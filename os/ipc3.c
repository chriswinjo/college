
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
void main()
{
int i;
void * shared_memory;
char buffer[100];
int shnid;
key_t key =fork("shmfile",65);
shmid =shmget(key,1024,0666);
printf("key of shared m/m is:%d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("process attachd at % \n",shared_memory);
printf("data rec  fom shae sared memoy is :%s",(char.*) shared_memory);
}
