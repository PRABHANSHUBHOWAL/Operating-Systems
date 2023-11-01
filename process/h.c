#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int a= 0;
int b = 10;
int c = 12;
int main(){
  for(int i =0; i< 5; i++){
    pid_t p;
    p = fork();
    if(p  == 0){
      a = a+1;
      b = b+1;
      c = c+1;
      printf("(child) = %d and (parent) = %d and gv-In-Child = %d %d %d\n", getpid(), getppid(), a, b, c);
      exit(0);
    }
    else{
    
      printf("(parent) = %d and (child) = %d and gv-In-parent = %d %d %d\n", getpid(), p, a, b, c);
    }
   
  }
}
