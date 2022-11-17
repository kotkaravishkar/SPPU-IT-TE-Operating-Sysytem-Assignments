#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct process{
	int BT,AT,TAT,WT,PNO,PID;
	char name[10];
}process;
void get_PCB(process p[],int *n)
{
	int i;
	printf("\n Enter The Total No Of Processes\n");
	scanf("%d",n);
	for(i=0;i<*n;i++)
	{
		printf("\n Enter Following details for Process %d",i+1);
		printf("\n Name :\t");
		scanf("%s",p[i].name);
		printf("\n Arrival Time :\t");
		scanf("%d",&p[i].AT);
		printf("\n Burst Time :\t");
		scanf("%d",&p[i].BT);
		printf("\n Priority :\t");
		scanf("%d",&p[i].PNO);
		p[i].PID=i;
	}
}
void FCFS(process p[],int n)
{
	int i,j,sum=0;
	p[0].TAT=p[0].BT;
	p[0].WT=0;
	sum=p[0].BT;
	for(i=1;i<=n;i++)
	{
		p[i].WT=sum-p[i].AT;
		p[i].TAT=p[i].WT+p[i].BT;
		sum=sum+p[i].BT;
	}
}
void disp_table(process p[],int n)
{
	int i;
	printf("\n P_NAME \t AT \t BT \t WT \t TAT \t PNO");
	for(i=0;i<n;i++)
	{
		printf("\n %-10s \t %d \t %d \t %d \t %d \t %d",p[i].name,p[i].AT,p[i].BT,p[i].WT,p[i].TAT,p[i].PNO);
	}
}
void sort_AT(process p[],int n)
{
	int i,j;
	process temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[j].AT<p[i].AT)
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
		}
	}
}
float cal_avgwt(process p[],int n)
{
	float avg=0;
	int i;
	for(i=0;i<n;i++)
	{
		avg+=p[i].WT;
	}
	avg=avg/n;
	return avg;
}
float cal_avgtat(process p[],int n)
{
	float avg=0;
	int i;
	for(i=0;i<n;i++)
	{
		avg+=p[i].TAT;
	}
	avg=avg/n;
	return avg;
}



void main(){
	int n;
	process P[MAX];
	system("clear");
	float avg_WT,avg_TAT;
	get_PCB(P,&n);

	sort_AT(P,n);
	FCFS(P,n);
	disp_table(P,n);
	avg_WT=cal_avgwt(P,n);
	avg_TAT=cal_avgtat(P,n);
	printf("\nAVERAGE WT  : %f",avg_WT);
	printf("\nAVERAGE TAT : %f",avg_TAT);
	printf("\n");
}

