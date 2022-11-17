#include<stdio.h>
#include<pthread.h>
#include<sys/syscall.h>
#include<semaphore.h>
#include<unistd.h>

void *reader();
void *writer();
int buff;
int flag=0;
int getbuff()
{
	int temp;
	printf("Enter an item into buffer : ");
	scanf("%d",&temp);
	return temp;
}

void readbuff()
{
	printf("read item from buffer : %d\n",buff);
}
	pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_t wrt=PTHREAD_MUTEX_INITIALIZER;
	int read_count=0;
int main()
{
	pthread_t tid1,tid2,tid3;

	pthread_create(&tid1,NULL,writer,NULL);
	pthread_create(&tid2,NULL,reader,NULL);
	pthread_create(&tid3,NULL,reader,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);

	return 0;
}

void *writer()
{
	int count=0;
	while(count<6)
	{
		pthread_mutex_lock(&wrt);
		if(flag==0)
		{
			buff=getbuff();
			flag=1;
			count++;
		}
	pthread_mutex_unlock(&wrt);
	}

}

void *reader()
{
	while(1)
	{
		pthread_mutex_lock(&mutex1);
		read_count++;
		if(read_count==1)
		{
			pthread_mutex_lock(&wrt);
		}
		pthread_mutex_unlock(&mutex1);
		if(flag==1)
		{
			readbuff(buff);
			sleep(2);
			flag=0;
		}
		pthread_mutex_lock(&mutex1);
		read_count--;

		if(read_count==0)
		{
			pthread_mutex_unlock(&wrt);
		}
		pthread_mutex_unlock(&mutex1);
	}
}
