#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
/*#include <bits/stdc++.h>
using namespace std;*/
int turn = 1, cnt = 0;

void *process1() {
	while(1) {
		printf("1 NON-CRITICAL SECTION\n\n");
		while(turn != 1) 
		{
			printf("1 Waiting...\n\n");
			sleep(2);
		}
		{
			printf("******************\n");
			printf("1 CRITICAL SECTION\n");
			printf("******************\n\n");
		}
		printf("1 Out of Critical Section\n\n");
		sleep(2);
		turn = 2;
	}
	pthread_exit(NULL);
}

void *process2() {
	while(1) {
		printf("\t\t\t\t\t\t\t\t\t2 NON-CRITICAL SECTION\n\n");
		while(turn != 2) {
			printf("\t\t\t\t\t\t\t\t\t2 Waiting...\n\n");
			sleep(2);
		}
		{
			printf("\t\t\t\t\t\t\t\t\t******************\n");
			printf("\t\t\t\t\t\t\t\t\t2 CRITICAL SECTION\n");
			printf("\t\t\t\t\t\t\t\t\t******************\n\n");
		}
		printf("\t\t\t\t\t\t\t\t\t2 Out of Critical Section\n\n");
		sleep(2);
		turn = 1;
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
