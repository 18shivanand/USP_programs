#include <stdio.h> //Standard I/O 
#include <unistd.h> // fork() and sleep()
#include <signal.h> //Signal ofc
#include <sys/types.h> // Process ID
#include <sys/wait.h>  //wait()

/*
 SIGINT 2 //interrupt a program
 SIGQUIT 3 //interrupt a program
 SIGFPE 8 //floating point arithmetic exception (or) fatal arithmetic exception -> /0, %0, integer overflow
 SIGSEGV 11 //segmentation violation
 SIGCHLD 17 //child status has changed
 SIGILL 4 //illegal instruction
*/

void signal_handler(int signum)
{
	switch(signum)
	{
		case 2: printf("Caught an interrupt signal, signum= %d\n\n", signum);
				break;
		case 3: printf("Caught a dump core signal, signum= %d\n\n", signum);
				break;
		case 4: printf("Caught an illegal instruction, signum= %d\n\n", signum);
				break;
		case 8: printf("Caught a floating point exception, signum= %d\n\n",signum);  
				break;
		case 11: printf("Caught a segmentation violation, signum= %d\n\n", signum);
				break;
		case 17: printf("Child status has changed, signum= %d\n\n", signum);
				 wait(NULL);
				 break;
		default: printf("Caught a signal, signum= %d\n\n", signum);
	}
}

int main()
{
	 
	//registering signals
	signal(SIGINT, signal_handler);
	signal(SIGSEGV, signal_handler);
	signal(SIGILL, signal_handler);
	signal(SIGFPE, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGCHLD, signal_handler);
	int i, x, pid1;
	for(i=0; i<5; i++)
	{
		printf("Program running.. Press CTRL+C or CTRL+\\ \n");
		sleep(1);
	}
	printf("Enter the divisor: ");
	scanf("%d",&x);
	if(x==0)
		raise(SIGFPE);
	else
		printf("Division: %.3f\n", (float)(1/x) );
	
	int arr[3];
	printf("\nEnter more than 3 elements:\n");
	for(i=0;i<5;i++)
	{
		if(i>3)
			raise(SIGSEGV);
		else
			scanf("%d",&arr[i]);
	}
	pid1=fork();
	if(pid1<0)
		printf("Error forking the child\n");
	else if(pid1==0)
	{
		printf("In child process\n");
	}
	else
	{
		signal(SIGCHLD, signal_handler);
		printf("In the parent process\n");
		sleep(5);
	}
	raise(SIGILL);
	return 0;
}
