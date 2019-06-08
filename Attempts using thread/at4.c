#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

bool wantp = false, wantq = false;
int waitcount=0;
void *process1() 
{
	while(1) 
	{
		printf("1 NON-CRITICAL SECTION\n\n");
		wantp = true;
		while(wantq != false) 
		{
			wantp = false;
			printf("1 Waiting...\n\n");
			wantp = true;
			waitcount++;
			if(waitcount > 4)
				printf("Process is waiting indefinitely\n\n");
			sleep(2);
		}
		{
			waitcount=0;
			printf("******************\n");
			printf("1 CRITICAL SECTION\n");
			printf("******************\n\n");
			sleep(1);
		}
		printf("1 Out of Critical Section\n\n");
		wantp = false;
	}
	pthread_exit(NULL);
}

void *process2() 
{
	while(1) 
	{
		printf("\t\t\t\t\t\t\t\t\t2 NON-CRITICAL SECTION\n\n");
		wantq = true;
		while(wantp != false) 
		{
			wantq = false;
			printf("\t\t\t\t\t\t\t\t\t2 Waiting...\n\n");
			wantq = true;
			if(waitcount > 4)
				printf("\t\t\t\t\t\t\t\t\tProcess is waiting indefinitely\n\n");
			sleep(2);
		}
		{
			waitcount=0;
			printf("\t\t\t\t\t\t\t\t\t******************\n");
			printf("\t\t\t\t\t\t\t\t\t2 CRITICAL SECTION\n");
			printf("\t\t\t\t\t\t\t\t\t******************\n\n");
			sleep(1);
		}
		printf("\t\t\t\t\t\t\t\t\t2 Out of Critical Section\n\n");
		wantq = false;
	}
	pthread_exit(NULL);
}

int main() 
{
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, process1, NULL);
	pthread_create(&thread2, NULL, process2, NULL);
	pthread_exit(NULL);
	return 0;
}
