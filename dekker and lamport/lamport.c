#include <stdio.h>
#include <pthread.h>

int ticketp = 0, ticketq = 0;

void *p() {
	while(1) {
		printf("\t\tp NON-CRITICAL SECTION\n\n");
		ticketp = ticketq + 1;
		while(ticketq && ticketp >= ticketq) ;
		{
			printf("\t\t==================\n");
			printf("\t\tp CRITICAL SECTION with Ticket Number :: %d\n", ticketp);
			printf("\t\t==================\n\n");
			sleep(1);
		}
		printf("\t\tp Out of Critical Section\n\n");
		ticketp = 0;
	}
	pthread_exit(NULL);
}

void *q() {
	while(1) {
		printf("\tq NON-CRITICAL SECTION\n\n");
		ticketq = ticketp + 1;
		while(ticketp && ticketq >= ticketp) ;
		{
			printf("\t==================\n");
			printf("\tq CRITICAL SECTION with Ticket Number :: %d\n", ticketq);
			printf("\t==================\n\n");
			sleep(1);
		}
		printf("\tq Out of Critical Section\n\n");
		ticketq = 0;
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, p, NULL);
	pthread_create(&t2, NULL, q, NULL);
	pthread_exit(NULL);
	return 0;
}
