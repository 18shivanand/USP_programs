#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    FILE *fp= NULL;
    pid_t process_id = 0;
    pid_t sid = 0;
    // Create child process
    process_id = fork();
    // Indication of fork() failure
    if (process_id < 0)
    {
        printf("fork failed!\n");
        // Return failure in exit status
        exit(1);
    }
    // PARENT PROCESS. Need to kill it.
    if (process_id > 0)
    {
        printf("process_id of child process %d \n", process_id);
        // return success in exit status
        exit(0);
    }
    //unmask the file mode
    umask(0);
    //set new session
    sid = setsid();
    if(sid < 0)
    {
        // Return failure
        exit(1);
    }
    // Change the current working directory.
    chdir("/home/ubuntu/environment/USP");
    // Close stdin. stdout and stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    // Open a log file in write mode.
    fp = fopen ("DaemonLog.txt", "w+");
    
    // while (1)
    // {
    //     sleep(1);
    //     fprintf(fp, "Logging info...\n");
    //     fflush(fp);
    //     printf("Task Task\n");
    // }
    
    while (1)
    {
        sleep(1);
        char *str = getlogin();
        fprintf(fp, str);
        fprintf(fp, "\n");
        fflush(fp);
        printf("Task Task\n");
    }
    
    fclose(fp);
    return (0);
}