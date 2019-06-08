#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

sem_t cli, det, mutex, mutex2, cli_done, det_done, sem[10001];
int ndet = 0, ncli = 0, mcli = 0, val = 0, val2 = 0;
queue <int> q;

void *detective(void *t) {
	sem_getvalue(&cli, &val);
	if (val) printf("\tDetective : %d entered\n\n", ndet);
	else printf("\tDetective : %d entered and talk to bartender\n\n", ndet);
	sem_post(&det);
	sem_wait(&mutex);
		sem_wait(&cli);
		int clie = q.front();
		q.pop();
		sem_post(&sem[clie]);
		printf("\t\t\t== Detective %d : Client %d Leave ==\n\n\n", t, clie);
	sem_post(&mutex);
}

void *client(void *t) {
	sem_getvalue(&det, &val2);
	if (val2) printf("\t\tClient : %d entered\n\n", ncli);
	else printf("\t\tClient : %d entered and take drink\n\n", ncli);
	sem_post(&cli);
	q.push(ncli);
	sem_wait(&det);
	sem_wait(&mutex2);
		int z = ncli;
		sem_init(&sem[ncli], 0, 0);
	sem_post(&mutex2);
	sem_wait(&sem[z]);
}

int main() {
	srand(rand());
	sem_init(&det, 0, 0);
	sem_init(&cli, 0, 0);
	sem_init(&mutex, 0, 1);
	sem_init(&mutex2, 0, 1);
	pthread_t pdet, pcli;
	while(1) {
		for(int i = 0; i < rand() % 3; i++) {
			ndet++;
			pthread_create(&pdet, NULL, detective, (void *)ndet);
			sleep(1);
		}
		for(int i = 0; i < rand() % 3; i++) {
			ncli++;
			pthread_create(&pcli, NULL, client, (void *)ncli);
			sleep(1);
		}
	}
	sem_destroy(&det);
	sem_destroy(&cli);
	sem_destroy(&mutex);
	sem_destroy(&mutex2);
	return 0;
}
