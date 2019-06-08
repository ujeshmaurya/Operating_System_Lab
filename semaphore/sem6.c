#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

int common = 0;
pthread_mutex_t mutex;

int compare_and_swap(int *common, int OLD, int NEW) {
	int temp = *common;
	if (*common == OLD) *common = NEW;
	return temp;
}

void *p_func() {
	int localp = 0;
	while(1) {
		printf("\tp Non-Critical Section\n\n");
		while(localp == 0) {
			pthread_mutex_lock(&mutex);
			localp = 1 - compare_and_swap(&common, localp, 1);
			pthread_mutex_unlock(&mutex);
		}
		{
			printf("\t==================\n");
			printf("\tp Critical Section\n");
			printf("\t==================\n\n");
			sleep(3);
		}
		printf("\tp Out of Critical Section\n\n");
		pthread_mutex_lock(&mutex);
		localp = 1 - compare_and_swap(&common, localp, 0);
		pthread_mutex_unlock(&mutex);
		sleep(2);
	}
}

void *q_func() {
	int localq = 0;
	while(1) {
		printf("\t\tq Non-Critical Section\n\n");
		while(localq == 0) {
			pthread_mutex_lock(&mutex);
			localq = 1 - compare_and_swap(&common, localq, 1);
			pthread_mutex_unlock(&mutex);
		}
		{
			printf("\t\t==================\n");
			printf("\t\tq Critical Section\n");
			printf("\t\t==================\n\n");
			sleep(3);
		}
		printf("\t\tq Out of Critical Section\n\n");
		pthread_mutex_lock(&mutex);
		localq = 1 - compare_and_swap(&common, localq, 0);
		pthread_mutex_unlock(&mutex);
		sleep(2);
	}
}

int main() {
	pthread_mutex_init(&mutex, NULL);
	pthread_t p, q;
	pthread_create(&p, NULL, p_func, NULL);
	pthread_create(&q, NULL, q_func, NULL);
	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);
	return 0;
}
