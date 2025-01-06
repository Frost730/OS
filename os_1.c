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

