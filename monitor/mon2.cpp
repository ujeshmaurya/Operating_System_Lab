#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <queue>

using namespace std;

pthread_mutex_t mutex, entry;

class monitor {

	pthread_cond_t OKtoEat[5];
	pthread_mutex_t mutexEat[5];
	int fork[5];
	
	public:
	monitor() {
		for(int i = 0; i < 5; i++) {
			fork[i] = 2;
			pthread_cond_init(&OKtoEat[i], NULL);
			pthread_mutex_init(&mutexEat[i], NULL);
		}
	}
		
	void takeForks(int i) {
		pthread_mutex_lock(&mutex);
			if (fork[i] != 2) {
				pthread_mutex_unlock(&mutex);
				printf("\t\t\t#%d Waiting...\n\n", i + 1);
				pthread_cond_wait(&OKtoEat[i], &mutexEat[i]);
				pthread_mutex_lock(&mutex);
			}
			fork[(i + 1) % 5] -= 1;
			fork[((i - 1) % 5 + 5) % 5] -= 1;
		pthread_mutex_unlock(&mutex);
	}
	
	void releaseForks(int i) {
		pthread_mutex_lock(&mutex);
			fork[(i + 1) % 5] += 1;
			fork[((i - 1) % 5 + 5) % 5] += 1;
			if (fork[(i + 1) % 5] == 2) {
				pthread_cond_signal(&OKtoEat[(i + 1) % 5]);
			}
			if (fork[((i - 1) % 5 + 5) % 5] == 2) {
				pthread_cond_signal(&OKtoEat[((i - 1) % 5 + 5) % 5]);
			}
		pthread_mutex_unlock(&mutex);
	}
	
};

monitor m;

void *philo_func(void *i) {
	while(1) {
		printf("\t#%ld Philospher Requests\n\n", (long)i + 1);
		pthread_mutex_lock(&entry);
		m.takeForks((long)i);
		printf("\t#%ld Philospher Uses Forks\n\n", (long)i + 1);
		sleep(3);
		printf("\t#%ld Philospher Releases Forks\n\n", (long)i + 1);
		m.releaseForks((long)i);
		pthread_mutex_unlock(&entry);
		sleep(3);
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t philo[5];
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_init(&entry, NULL);
	for(int i = 0; i < 5; i++) pthread_create(&philo[i], NULL, philo_func, (void *)i);
	pthread_mutex_destroy(&mutex);
	pthread_mutex_destroy(&entry);
	pthread_exit(NULL);
	return 0;
}
