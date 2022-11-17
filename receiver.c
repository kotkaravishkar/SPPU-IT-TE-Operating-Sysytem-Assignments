#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>
void main()
{
	int shmid;
	void *sharedmemory;

	shmid=shmget((key_t)1122,1024,0666);
	printf("Key value : %d\n",shmid);
	sharedmemory=shmat(shmid,NULL,0);

	printf("Program Attached In %p\n",sharedmemory);

	printf("Shared Memory : %s\n",(char *)sharedmemory);
}

