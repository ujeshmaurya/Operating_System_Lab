#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>


sem_t diningSem[5];
sem_t room;
int cnt = 0;

void *diningFunc(void *id) {
	int *i = (int *)id;
	int k = *i;
	while(1) {
		//sleep(rand() % 3);
		sleep(1);
		sem_wait(&room);
		printf("\nPhilosopher %d thinking\n", k + 1);
		sem_wait(&diningSem[k % 5]);
		printf("\n\t\tPhilosopher %d acquired fork %d\n", k + 1, k % 5);
		if(cnt > 10) sleep(3);
		else sleep(1);
		sem_wait(&diningSem[(k + 1) % 5]);
		printf("\n\t\tPhilosopher %d acquired fork %d\n", k + 1, (k + 1)% 5);
		printf("\n\tPhilosopher %d eating\n", k + 1);
		cnt++;
		sem_post(&diningSem[k % 5]);
		printf("\n\t\tPhilosopher %d released fork %d\n", k+1, k % 5);
		sem_post(&diningSem[(k + 1) % 5]);
		printf("\n\t\tPhilosopher %d released fork %d\n", k + 1, (k + 1)% 5);
		printf("\nPhilosopher %d completed\n", k + 1);
		sem_post(&room);
	}
}

int main(){
	pthread_t tid[5];
	sem_init(&room, 0, 4);
	srand(time(NULL));
	int i;
	for(i = 0; i < 5; i++){
		sem_init(&diningSem[i], 0, 1);
	}
	for(i = 0; i < 5; i++) {
		pthread_create(&tid[i], NULL, diningFunc, &i);
		sleep(1);
	}
	for(i = 0; i < 5; i++) {
		pthread_join(tid[i], NULL);
	}
	pthread_exit(NULL);
	return 0;
}
