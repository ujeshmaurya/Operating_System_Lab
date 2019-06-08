#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

sem_t eDir, wDir, mutex, eMutex, wMutex;

typedef enum {EAST, WEST} Destination;

pthread_t monkey[100001];

int eCount = 0, wCount = 0, i = 1;

void *WaitUntilSafeToCross(pair <int id, Destination d> p) {
	if (p.second == EAST) {
		sem_wait(&eMutex);
			eCount++;
			if (eCount == 1) {
				sem_wait(&eDir);
			}
		sem_post(&eMutex);
	}
	if (p.second == WEST) {
		sem_wait(&wMutex);
		wCount++;
		if (wCount == 1) { 
			sem_wait(&wDir);
		}
		sem_post(&wMutex);
	}
}

void *DoneWithCrossing(pair <int id, Destination d> p) {
	if (p.second == EAST) {
		sem_wait(&eDir);
		sem_wait(&mutex);
			if (eCount > 5) {
				printf("Goint to East : %d\n", max(eCount - 5, 0));
			
				eCount = max(eCount - 5, 0);
			}
		sem_post(&mutex);
		if (eCount == 0) sem_post(wDir);
	}
	if (p.second == WEST) {
		sem_wait(&wDir);
		sem_wait(&mutex);
		if (wCount > 5) {
			printf("Goint to West : %d\n", max(wCount - 5, 0));
			wCount = max(wCount - 5, 0);
		}
		sem_post(&mutex);
		if (wCount == 0) sem_post(eDir);
	}
}

void *mon(Destination d) {
		i++;
		pthread_create(&monkey[i], NULL, WaitUntilSafeToCross, make_pair(i, d));
		printf("Monkey : %d Cross Ravine\n", i);
		sleep(2);
		pthread_create(&monkey[i], NULL, DoneWithCrossing, make_pair(i, d));
}

int main() {
	srand(rand());
	sem_init(&mutex, 0, 1);
	sem_init(&eMutex, 0, 1);
	sem_init(&wMutex, 0, 1);
	sem_init(&eDir, 0, 1);
	sem_init(&wDir, 0, 1);
	while(1) {
		int dir = rand() % 2 + 1;
		pthread_create(&monkey[i], NULL, mon, dir);
		sleep(1);
	}
	sem_destroy(&mutex);
	sem_destroy(&eMutex);
	sem_destroy(&wMutex);
	sem_destroy(&eDir);
	sem_destroy(&wDir);
	return 0;
}
