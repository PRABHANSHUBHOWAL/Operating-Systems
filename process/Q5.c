#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>


int main(){  
    pid_t p;  
    p = fork();
    if(p ==  0){
        printf("child id is : %d\n", getpid());
        exit(0);
    }
    else{
        printf("child id is: %d\n",p);
        sleep(2);
        printf("child id is : %d\n", p);
    }
    printf("\n");
  
}
