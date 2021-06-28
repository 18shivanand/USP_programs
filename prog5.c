#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void forkexample()
{
   int child = fork();
   
   if(child == 0)
   {
     printf("Hello from the Child !");
     int p_id, p_pid;
     
     p_id=getpid();
     p_pid=getppid();
     
     printf("\t Child Process ID : %d\n", p_id);
     printf("\t Parent Process ID : %d\n", p_pid);
     
     char comm[50];
     
     printf("Enter your command: ");
     scanf("%[^\n]s" , comm);
     
     printf("\t\n Executing Command : \n");
     system(comm);
    }
    else
    {
       wait();
       printf("\n\n Hello from the parent!\n");
       printf("I created the process ID : %d\n", child);
       printf("\t My process Id : %d\n", getpid());
    }
}

int main()
{
  forkexample();
  return 0;
}  
          