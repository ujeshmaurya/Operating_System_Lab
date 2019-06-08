#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

bool wantp = false, wantq = false;
int count = 0;

void *process1() 
{
	while(1) 
	{
		printf("1 NON-CRITICAL SECTION\n\n");
		while(wantq != false) 
		{
			printf("1 Waiting...\n\n");
			sleep(1);
		}
		if (count >= 4) sleep(1);
		wantp = true;
		{
			printf("******************\n");
			printf("1 CRITICAL SECTION\n");
			printf("******************\n\n");
			sleep(1);
			if (wantq) 
			{
				printf("1 and 2 processes are in Critical Section\n");
				pthread_exit(NULL);
			}
		}
		printf("1 Out of Critical Section\n\n");
		wantp = false;
		sleep(1);
		count++;
	}
	pthread_exit(NULL);
}

void *process2() 
{
	while(1) 
	{
		printf("\t\t\t\t\t\t\t\t\t2 NON-CRITICAL SECTION\n\n");
		while(wantp != false) 
		{
			printf("\t\t\t\t\t\t\t\t\t2 Waiting...\n\n");
			sleep(1);
		}
		if (count >= 4) sleep(1);
		wantq = true;
		{
			printf("\t\t\t\t\t\t\t\t\t******************\n");
			printf("\t\t\t\t\t\t\t\t\t2 CRITICAL SECTION\n");
			printf("\t\t\t\t\t\t\t\t\t******************\n\n");
			sleep(1);
			if (wantp) 
			{
				pthread_exit(NULL);
			}
		}
		printf("\t\t\t\t\t\t\t\t\t2 Out of Critical Section\n\n");
		wantq = false;
		sleep(1);
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, process1, NULL);
	pthread_create(&thread2, NULL, process2, NULL);
	pthread_exit(NULL);
	return 0;
}
