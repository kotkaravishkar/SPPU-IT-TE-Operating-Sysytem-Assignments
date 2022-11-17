#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{

printf("Main Process\n");
int i,pid;
pid=fork();
if(pid>0)
{
i=wait(0);
sleep(5);

printf("Terminated child PID:%d\n",i);
printf("Parent Process PID:%d\n",getpid());
printf("Grandparent Process PID:%d\n",getppid());
}

else if(pid==0)
{
printf("Child Process PID:%d\n",getpid());
printf("Child Parent PID:%d\n",getppid());
}

else
printf("Error on work");

return 0;

}
