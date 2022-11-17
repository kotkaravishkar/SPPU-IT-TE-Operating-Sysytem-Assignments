#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
void main()
{
	int shmid;
	void *sharedmemory;
	char buff[100];

	shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);

	printf("Key Of Shared Memory is : %d\n",shmid);

	sharedmemory=shmat(shmid,NULL,0);

	printf("Process attaches at : %p\n",sharedmemory);

	printf("Enter The value in sharedmemory\n");
	read(0,buff,100);

	strcpy(sharedmemory,buff);

	printf("You Have Entered : %s\n",(char *)sharedmemory);
}	
