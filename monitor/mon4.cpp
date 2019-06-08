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

	pthread_cond_t cond;
	pthread_mutex_t mutexMonitor;
	int size;
	
	public:
		monitor() {
			size = 1;
			pthread_cond_init(&cond, NULL);
			pthread_mutex_init(&mutexMonitor, NULL);
		}
			
		void wait() {
			pthread_mutex_lock(&mutex);
				if (size == 0) {
					pthread_mutex_unlock(&mutex);
					pthread_cond_wait(&cond, &mutexMonitor);
					pthread_mutex_lock(&mutex);
				}
				size--;
			pthread_mutex_unlock(&mutex);
		}
		
		void signal() {
			pthread_mutex_lock(&mutex);
				size++;
				pthread_cond_signal(&cond);
			pthread_mutex_unlock(&mutex);
		}
	
};

monitor m;

void *p(void *i) {
	while(1) {
		printf("\t#%ld Requests\n\n", (long)i);
		pthread_mutex_lock(&entry);
		m.wait();
		{
			printf("\t\t=====================\n");
			printf("\t\t#%ld Critical Section\n", (long)i);
			printf("\t\t=====================\n\n");
			sleep(3);
		}
		m.signal();
		printf("#%ld Releases\n\n", (long)i);
		pthread_mutex_unlock(&entry);
		sleep(3);
	}
	pthread_exit(NULL);
}

int main() {
	int i = 0;
	pthread_t thread[1001];
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_init(&entry, NULL);
	while(1) {
		i++;
		pthread_create(&thread[i], NULL, p, (void *)i);
		sleep(4);
	}
	pthread_mutex_destroy(&mutex);
	pthread_mutex_destroy(&entry);
	pthread_exit(NULL);
	return 0;
}
