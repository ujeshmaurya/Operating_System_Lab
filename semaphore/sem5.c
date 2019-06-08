#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

sem_t readerSem, writerSem, entry;
int delayedReaders = 0, delayedWriters = 0, readers = 0, writers = 0, flag = 0, id = 1;

void signalProcess() {
	if (writers == 0 && delayedReaders > 0) {
		delayedReaders -= 1;
		sem_post(&readerSem);
	} else if (readers == 0 && writers == 0 && delayedWriters > 0) {
		delayedWriters -= 1;
		sem_post(&writerSem);
	} else sem_post(&entry);
}

void *reader_func(void *id) {
	sem_wait(&entry);
	if (writers > 0) {
		delayedReaders += 1;
		sem_post(&entry);
		sem_wait(&readerSem);
	}
	readers += 1;
	printf("\t\t#%d Reading\n", (int *)id);
	sleep(rand() % 1 + 1);
	signalProcess();
	sleep(rand() % 5 + 1);
	printf("\t\t#%d Out\n", (int *)id);
	sem_wait(&entry);
	readers -= 1;
	signalProcess();
}

void *writer_func(void *id) {
	sem_wait(&entry);
	if (writers > 0 || readers > 0) {
		delayedWriters += 1;
		sem_post(&entry);
		sem_wait(&writerSem);
	}
	writers += 1;
	printf("\t#%d Writing\n", (int *)id);
	sleep(rand() % 2 + 1);
	signalProcess();
	sleep(rand() % 5 + 1);
	printf("\t#%d Out\n", (int *)id);
	sem_wait(&entry);
	writers -= 1;
	signalProcess();
}

int main() {
	srand(time(NULL));
	sem_init(&readerSem, 0, 0);
	sem_init(&writerSem, 0, 0);
	sem_init(&entry, 0, 1);
	pthread_t thread[1001];
	while(1) {
		flag = rand() % 2;
		if (flag) pthread_create(&thread[id], NULL, reader_func, id), id++;
		else pthread_create(&thread[id], NULL, writer_func, id), id++;
		sleep(2);
	}
	sem_destroy(&readerSem);
	sem_destroy(&writerSem);
	sem_destroy(&entry);
	pthread_exit(NULL);
	return 0;
}
