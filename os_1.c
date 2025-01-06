#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void main(){
pid_t pid=fork();
if(pid>0){
printf("completed\n");
}
else if(pid==0){
 execl("/bin/ls","ls","-s",NULL);
 perror("\n execl failf \n");
}
else
perror("\n fork faild\n");
}

// updated code for more info
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {  // Parent process
        wait(NULL); // Wait for the child process to finish
        printf("completed\n");
    } 
    else if (pid == 0) {  // Child process
        execl("/bin/ls", "ls", "-s", NULL);
        perror("\nexecl failed\n");
        exit(EXIT_FAILURE); // Exit child process if execl fails
    } 
    else {  // Fork failed
        perror("\nfork failed\n");
        exit(EXIT_FAILURE);
    }

    return 0; // Indicate successful completion of the program
}


