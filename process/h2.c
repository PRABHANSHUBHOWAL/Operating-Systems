#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>


int main(){

    int stat;
    pid_t p, w;
 
    p = fork();
    if(p ==  0){
      printf("(parent id) = %d\n", getppid());
      sleep(20);
      printf("(parent id) = %d\n", getppid());
      exit(1);     
    }
    else{
      printf("id is :%d ", getpid());
      exit(0);
    }

    printf("\n");
  
}
