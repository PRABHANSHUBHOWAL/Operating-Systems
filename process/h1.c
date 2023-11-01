#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int a= 0;
int b = 10;
int c = 12;
int main(){
    for(int i =0; i< 5; i++){
        int stat;
        pid_t p, w;

        p = fork();
        if(p ==  0){
            printf("child PID = %d\n", getpid());
            exit(1);
        }
        else{
            w = wait(&stat);
            if(WIFEXITED(stat)){
              printf("exited, status=%d\n", WEXITSTATUS(stat));
            }
        }
        printf("\n");
    }
}
