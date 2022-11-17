#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main()
{
	int x,c,i,pid;
	printf("Enter no. of integers(Max limit 25): ");
	scanf("%d",&x);
	
	int a[x];
	for (int i=0; i<x; i++)
	{
		printf("Enter integer: ");
		scanf("%d",&a[i]);
	}
	
	//printf("Enter choice: \n 1.Zombie Mode \n 2.Orphan Mode\n");
	//scanf("%d",&c);
	
	
	pid=fork();
	
	if(pid>0)
	{
	//	if(c==1)
		//{
		/*system("ps -el |grep Z");
			i=wait(0);
			printf("Terminated Child's pid %d",i);*/
			printf("Parent Process PID:%d\n",getpid());
			printf("Grandparent Process PID:%d\n",getppid());
	//	}
		sort(1,a,x);
		display(a,x,c);

		//printf("Terminated child PID:%d\n",i);
		
	}

	else if(pid==0)
	{	
		//if(c==2)
		sleep(5);
			printf("Child Process PID:%d\n",getpid());
		printf("Child Parent PID:%d\n",getppid());
		
		sort(2,a,x);
		display(a,x,c);
		
		
		system("ps -el |grep init");	
	}

}

void sort(int z,int a[25],int x)
{
	int t=0;
	switch(z)
	{
		case 1: //Des
		for(int i = 0; i<x; i++)
		{
			for(int j =i+1; j<x; j++)
			{
				if(a[i]<a[j])
				{
					t = a[j];
					a[j] = a[i];
					a[i] = t;
				}
			}
		}
		break;
		case 2: //Asc
		for(int i = 0; i<x; i++)
		{
			for(int j =i+1; j<x; j++)
			{
				if(a[i]>a[j])
				{
					t = a[j];
					a[j] = a[i];
					a[i] = t;
				}
			}
		}
		break;
		default:
		printf("Invalid choice");
		break;
	}		
}

void display(int a[25],int x,int c)
{
	printf("Sorted Sequense:\n");
	for (int i=0; i<x; i++)
	{
		printf("%d ",a[i]);		
	}
}
