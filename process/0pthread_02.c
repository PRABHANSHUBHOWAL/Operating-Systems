/* _Problem_: Write a C program where you will store an array of 10
   strings. Then create pthreads that will print all of those
   strings. More precisely, create 10 pthreads in total so that they will
   end up printing all the strings. 
   Find the time taken by the entire thread operation. This will show you
   how to time any function in your C program
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

char* str_array[]={
	"String 0",
	"String 1",
	"String 2",
	"String 3",
	"String 4",
	"String 5",
	"String 6",
	"String 7",
	"String 8",
	"String 9"
};

struct thread_arg_t {
	pthread_t th_id;
	int th_num;
	char *str;
};


void* thread_code(void* arg) {
	struct thread_arg_t* th_arg_p = (struct thread_arg_t *) arg;
	printf("This is thread#%d (ID=%X). Message: %s\n",
	       th_arg_p->th_num,
	       (unsigned int) th_arg_p->th_id,
	       th_arg_p->str);
	return NULL;
}

int main() {
	struct thread_arg_t thread_args[10];
	int i;

	clock_t t_begin, t_end, t_total;
	//This is wehre the action starts. This is t_begin
	t_begin=clock();

	//create the threads
	for (i=0; i<10; i++){
		thread_args[i].th_num=i;
		thread_args[i].str=str_array[i];
		if (pthread_create(&thread_args[i].th_id,
				   NULL,
				   &thread_code,
				   &thread_args[i])!=0) {
			perror("Thread #%d creation failed!\n");
			exit(1);
		}
	}
	
	//join the threads (i.e., wait for the threads to end)
	for (i=0; i<10; i++)
		if (pthread_join(thread_args[i].th_id, NULL) != 0) {
			perror("pthread_join failed");
		}
	//End of action. This is t_end
	t_end=clock();
	
	t_total = t_end - t_begin;
	printf("Time units spent in thread related actions: %lu\n", 
		(unsigned long) t_total);
	printf("Time in seconds: %lf\n",
		((double) t_total)/CLOCKS_PER_SEC);
	return 0;
}

