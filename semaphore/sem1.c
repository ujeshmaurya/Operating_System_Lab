#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void *p(int index) {
	while(1) {
		printf("\t\t%d Non-Critical Section\n\n", index);
		printf("\t\t%d Waiting...\n\n", index);
		sem_wait(&sem);
		{
			printf("\t\t==================\n");
			printf("\t\t%d Critical Section\n", index);
			printf("\t\t==================\n\n");
			sleep(1);
		}
		printf("\t\t%d Out of Critical Section\n\n", index);
		sem_post(&sem);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main() {
	int n = 0, i = 0;
	sem_init(&sem, 0, 1);
	printf("Enter Number of processes :: ");
	scanf("%d", &n);
	pthread_t thread[n + 1];
	for(i = 1; i <= n; i++) pthread_create(&thread[i], NULL, p, i);
	sem_destroy(&sem);
	pthread_exit(NULL);
	return 0;
}
