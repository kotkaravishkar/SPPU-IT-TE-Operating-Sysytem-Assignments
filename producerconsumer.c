#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<semaphore.h>
#include <unistd.h>
#include <stdlib.h>


void *producer();
void *consumer();
int in=0,out=0,item;
sem_t mutex;

struct Shared {
	int buff[20];
	sem_t full,empty;
};

struct Shared sh;
int main()
{

	pthread_t ptid1,ptid2,ctid;

	/*Intialize Semaphore) */
	sem_init(&sh.empty,0,20);
	sem_init(&sh.full,0,0);
	sem_init(&mutex,0,1);

	//Thread creation
	pthread_create(&ptid1,NULL,producer,NULL);
	pthread_create(&ptid2,NULL,producer,NULL);
	pthread_create(&ctid,NULL,consumer,NULL);
	
	//Thread join
	pthread_join(ptid1,NULL);
	pthread_join(ctid,NULL);
	pthread_join(ptid2,NULL);
	
	
	
	return 0;
	}
	
	void *producer()
	{
	long int ptid;
	while(1)
	{
	       item=in;
	           sem_wait(&sh.empty);
	               sem_wait(&mutex); //Enter critical section
	
	                   sh.buff[in++]=item;
	                       printf("Producer ID and produced value:%ld \t %d\n",syscall(SYS_gettid,ptid),item);
	
	                           sem_post(&mutex); //Exit critical section
	                               sem_post(&sh.full);
	                                   sleep(2);
	                                     }
	
	                                     }
	
	                                     void *consumer()
	                                     {
	                                     long int ctid;
	                                     while(1)
	                                        {
	                                         	while(out<=in)
	                                         	 	{
	                                         	 	  	//item=in;
	                                         	 	  	  	sem_wait(&sh.full);
	                                         	 	  	  	  	sem_wait(&mutex); //Enter critical section
	                                         	 	  	  	  	  	item=sh.buff[out++];
	                                	 	  	  	  	  	  	printf("Consumer ID and consumed value:%ld \t %d \n",syscall(SYS_gettid,ctid),item);
	
	                                         	 	  	  	  	  	  	   	sem_post(&mutex);//Exit critical section
	                                         	 	  	  	  	  	  	   	  	sem_post(&sh.empty);
	                                         	 	  	  	  	  	  	   	  	  	sleep(2);   
	                                         	 	  	  	  	  	  	   	  	  	       }
	                                         	 	  	  	  	  	  	   	  	  	          }
	
	                                         	 	  	  	  	  	  	   	  	  	          }
