#include<stdio.h>
#include<stdio.h>
#include<sys/types.h>
int main(){
	int pid;
	pid=fork();
	if(pid==0){
		/*Orphan State*/
		sleep(5);
		printf("Child Process pid : %d\n",getpid());
		printf("Parent Process pid : %d\n",getppid());
	}else if(pid>1){
		wait(0);

		printf("Terminated Process pid : %d\n",getpid());
		printf("Parent Process Pid : %d\n",getppid());
	}else{
		printf("Child is not created \n");
	}
	return 0;
}

