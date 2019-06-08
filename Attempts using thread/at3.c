#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

bool wantp = false, wantq = false;
int c = 0;

void *process1() 
{
	while(1) 
	{
		printf("1 NON-CRITICAL SECTION\n\n");
		wantp = true;
		while(wantq != false) 
		{
			if (c == 10)
			{
				pthread_exit(NULL);
			}
			printf("1 Waiting...\n\n");
			sleep(1);
		}
		c = 0;
		{
			printf("******************\n");
			printf("1 CRITICAL SECTION\n");
			printf("******************\n\n");
			sleep(1);
		}
		printf("1 Out of Critical Section\n\n");
		wantp = false;
		sleep(1);
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
			c++;
			printf("\t\t\t\t\t\t\t\t\t2 Waiting...\n\n");
			if (c == 10) 
			{
				printf("\t\t\t\t\t\t\t\t\tDeadlock, 1 and 2 are just waiting\n");
				pthread_exit(NULL);
			}
			sleep(1);
		}
		c = 0;
		{
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
