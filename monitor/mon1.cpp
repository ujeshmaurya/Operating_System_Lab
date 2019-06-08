#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <queue>

using namespace std;

pthread_mutex_t mutex, entry;
int flag = 0;

class monitor {

	queue <int> q;
	int BUFFER_SIZE;
	pthread_cond_t notFull, notEmpty;
	pthread_mutex_t mutexFull, mutexEmpty;
	
	public:
	monitor() {
		pthread_cond_init(&notFull, NULL);
		pthread_cond_init(&notEmpty, NULL);
		pthread_mutex_init(&mutexFull, NULL);
		pthread_mutex_init(&mutexEmpty, NULL);
	}
	
	void setSize(int n) {
		BUFFER_SIZE = n;
	}
	
	void append(int data) {
		pthread_mutex_lock(&mutex);
		if (q.size() == BUFFER_SIZE) {
			flag = 1;
			pthread_mutex_unlock(&mutex);
			printf("\t\t\tProducer Waiting...\n\n");
			pthread_cond_wait(&notFull, &mutexFull);
			pthread_mutex_lock(&mutex);
		}
		q.push(data);
		pthread_cond_signal(&notEmpty);
		pthread_mutex_unlock(&mutex);
	}
	
	int take() {
		int data = 0;
		pthread_mutex_lock(&mutex);
		if (q.size() == 0) {
			printf("\t\t\tConsumer Waiting...\n\n");
			flag = 0;
			pthread_mutex_unlock(&mutex);
			pthread_cond_wait(&notEmpty, &mutexEmpty);
			pthread_mutex_lock(&mutex);
		}
		data = q.front();
		q.pop();
		pthread_cond_signal(&notFull);
		pthread_mutex_unlock(&mutex);
		return data;
	}
	
};

monitor m;
int id = 1;

void *producer(void *) {
	while(1) {
		pthread_mutex_lock(&entry);
		printf("\t\tProducer Requests\n\n");
		int data = id++;
		m.append(data);
		printf("\t\tProduced Data :: %d\n\n", data);
		sleep(1);
		if (flag) sleep(2);
		pthread_mutex_unlock(&entry);
	}
}

void *consumer(void *) {
	while(1) {
		pthread_mutex_lock(&entry);
		printf("\tConsumer Requests\n\n");
		int data = m.take();
		printf("\tComsumed Data :: %d\n\n", data);
		sleep(2);
		pthread_mutex_unlock(&entry);
	}
}

int main() {
	printf("Enter Size of Buffer :: ");
	int n;
	scanf("%d", &n);
	m.setSize(n);
	pthread_t pro, con;
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_init(&entry, NULL);
	pthread_create(&pro, NULL, producer, NULL);
	pthread_create(&con, NULL, consumer, NULL);
	pthread_mutex_destroy(&mutex);
	pthread_mutex_destroy(&entry);
	pthread_exit(NULL);
	return 0;
}
