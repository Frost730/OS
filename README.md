# OS
Code Explanation:

    Headers:
        <stdio.h>: For input/output functions like printf and perror.
        <sys/types.h>: Contains definitions of data types like pid_t.
        <unistd.h>: For fork, exec, and other POSIX API functions.
        <stdlib.h>: For general utilities, although not used directly in this code.

    Forking a Process:
        pid_t pid = fork();: Creates a new process. fork() returns:
            > 0: To the parent process. pid contains the PID of the child process.
            0: To the child process.
            < 0: If the fork fails (e.g., due to resource exhaustion).

    Parent Process:
        If pid > 0, the parent process executes printf("completed\n");.

    Child Process:
        If pid == 0, the child process executes:

    execl("/bin/ls", "ls", "-s", NULL);

        execl: Replaces the current process image with a new program (ls -s).
        If execl fails, it executes the following perror.

Error Handling:

    If fork fails, it prints an error message using perror.
