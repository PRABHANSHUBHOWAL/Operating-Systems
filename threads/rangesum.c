#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Ques-2
int a[25000][25000];
struct thread_arg_t {
    pthread_t th_id;
    int th_num;
    int sum;
};
void* thread_code(void* arg) {
    struct thread_arg_t* th_arg_p = (struct thread_arg_t *) arg;
    int s=0;
    int x=th_arg_p->th_num;
    for(int i=x*1000;i<(x+1)*1000;i+=10){
        for (int j=0;j<25000;j++)
        {
            s+=a[i][j];
        }
    }
    th_arg_p->sum=s;
    printf("This is thread# %d (ID=%X). Sum : %d\n",th_arg_p->th_num,(unsigned int) th_arg_p->th_id,th_arg_p->sum);
    return NULL;
}
int main() {
    for(int i=0;i<25000;i++)for(int j=0;j<25000;j++)a[i][j]=rand()%2;
    struct thread_arg_t thread_args[25];
    int i;
    //create the threads
    for (i=0; i<25; i++){
        thread_args[i].th_num=i;    
        if (pthread_create(&thread_args[i].th_id, NULL, &thread_code, &thread_args[i])!=0) {
            perror("Thread #%d creation failed!\n");
            exit(1);
        }
    } 
    //join the threads (i.e., wait for the threads to end)
    for (i=0; i<25; i++)
        if (pthread_join(thread_args[i].th_id, NULL) != 0) {
        perror("pthread_join failed");
    }
    return 0;
}