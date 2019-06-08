#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <queue>

using namespace std;

sem_t notEmpty;
queue <int> q;
int data = 0;

void *pro(void *) {
	while(1) {
		data++;
		{
			printf("\t\t==================\n");
			printf("\t\tProduced Data :: %d\n", data);
			q.push(data);
			printf("\t\t==================\n\n");
			sleep(1);
		}
		sem_post(&notEmpty);
		sleep(1);
	}
	pthread_exit(NULL);
}

void *con(void *) {
	while(1) {
		sem_wait(&notEmpty);
		{
			printf("\t==================\n");
			int cdata = q.front();
			printf("\tConsumed Data :: %d\n", cdata);
			q.pop();
			printf("\t==================\n\n");
			sleep(2);
		}
		sleep(2);
	}
	pthread_exit(NULL);
}

int main() {
	sem_init(&notEmpty, 0, 0);
	pthread_t producer, consumer;
	pthread_create(&producer, NULL, pro, NULL);
	pthread_create(&consumer, NULL, con, NULL);
	sem_destroy(&notEmpty);
	pthread_exit(NULL);
	return 0;
}
