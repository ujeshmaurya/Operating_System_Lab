#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

bool wantp = false, wantq = false;
int c = 0;

void *p() {
	while(1) {
		printf("\t\tp NON-CRITICAL SECTION\n\n");
		while(wantq != false) {
			printf("\t\tp Waiting...\n\n");
			sleep(1);
		}
		if (c >= 4) sleep(1);
		wantp = true;
		{
			printf("\t\t==================\n");
			printf("\t\tp CRITICAL SECTION\n");
			printf("\t\t==================\n\n");
			sleep(1);
			if (wantq) {
				printf("Mututal Exclusion not satisfied, both processes are in Critical Section\n");
				pthread_exit(NULL);
			}
		}
		printf("\t\tp Out of Critical Section\n\n");
		wantp = false;
		sleep(1);
		c++;
	}
	pthread_exit(NULL);
}

void *q() {
	while(1) {
		printf("\tq NON-CRITICAL SECTION\n\n");
		while(wantp != false) {
			printf("\tq Waiting...\n\n");
			sleep(1);
		}
		if (c >= 4) sleep(1);
		wantq = true;
		{
			printf("\t==================\n");
			printf("\tq CRITICAL SECTION\n");
			printf("\t==================\n\n");
			sleep(1);
			if (wantp) {
				pthread_exit(NULL);
			}
		}
		printf("\tq Out of Critical Section\n\n");
		wantq = false;
		sleep(1);
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
