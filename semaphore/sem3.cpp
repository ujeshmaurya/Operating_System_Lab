#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <queue>

using namespace std;

sem_t notEmpty, notFull;
queue <int> q;
int data = 0, n = 0, flag = 0;

void *pro(void *) {
	while(1) {
		sem_wait(&notFull);
		data++;
		{
			printf("\t\t==================\n");
			printf("\t\tProduced Data :: %d\n", data);
			q.push(data);
			printf("\t\t==================\n\n");
			if(q.size() == n) {
				printf("\t\t\tProducer Alert :: Buffer Full\n\n");
				flag = 1;
			}
			if (flag) sleep(2);
			sleep(1);
		}
		sem_post(&notEmpty);
		if (flag) sleep(2);
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
			if (q.empty()) {
				printf("\t\t\tConsumer Alert :: Buffer Empty\n");
				flag = 0;
			}
			sleep(2);
		}
		sem_post(&notFull);
		sleep(2);
	}
	pthread_exit(NULL);
}

int main() {
	printf("Enter Size of Buffer :: ");
	scanf("%d", &n);
	sem_init(&notEmpty, 0, 0);
	sem_init(&notFull, 0, n);
	pthread_t producer, consumer;
	pthread_create(&producer, NULL, pro, NULL);
	pthread_create(&consumer, NULL, con, NULL);
	sem_destroy(&notEmpty);
	pthread_exit(NULL);
	return 0;
}
