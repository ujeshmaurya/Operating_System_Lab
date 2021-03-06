#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

bool wantp = false, wantq = false;
int c = 0;

void *p() {
	while(1) {
		printf("\t\tp NON-CRITICAL SECTION\n\n");
		wantp = true;
		while(wantq != false) {
			if (c == 6) {
				pthread_exit(NULL);
			}
			printf("\t\tp Waiting...\n\n");
			sleep(1);
		}
		c = 0;
		{
			printf("\t\t==================\n");
			printf("\t\tp CRITICAL SECTION\n");
			printf("\t\t==================\n\n");
			sleep(1);
		}
		printf("\t\tp Out of Critical Section\n\n");
		wantp = false;
	}
	pthread_exit(NULL);
}

void *q() {
	while(1) {
		printf("\tq NON-CRITICAL SECTION\n\n");
		wantq = true;
		while(wantp != false) {
			c++;
			printf("\tq Waiting...\n\n");
			if (c == 6) {
				printf("Deadlock, both processes are waiting for each other\n");
				pthread_exit(NULL);
			}
			sleep(1);
		}
		c = 0;
		{
			printf("\t==================\n");
			printf("\tq CRITICAL SECTION\n");
			printf("\t==================\n\n");
			sleep(1);
		}
		printf("\tq Out of Critical Section\n\n");
		wantq = false;
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, p, NULL);
	pthread_create(&thread2, NULL, q, NULL);
	pthread_exit(NULL);
	return 0;
}
