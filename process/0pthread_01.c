/* _Problem_: Write a C program where you will store an array of 10
   strings. Then create pthreads that will print all of those
   strings. More precisely, create 10 pthreads in total so that they will
   end up printing all the strings. Note the order in which the
   strings are printed. Is the order the same as the order in which
   the strings appear in the array of strings?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

char* str_array[]={	"String 0",	"String 1",	"String 2",	"String 3",	"String 4",	
					"String 5", "String 6",	"String 7",	"String 8",	"String 9"};

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

	return 0;
}

