#include <stdio.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int *ticket, *choose, *cnt, *tickets;
int n, id;

int FetchAndAdd(int *ptr) {
	int OLD = *ptr;
	*ptr = *ptr + 1;
	return OLD;
}

void lock() {
	choose[id] = 1;
	ticket[id] = FetchAndAdd(tickets);
	choose[id] = 0;
	for(int i = 1; i <= n; i++) {
		while(choose[i]);
		while(ticket[i] && (ticket[i] < ticket[id] || ticket[i] == ticket[id] && i < id));
	}
}

void unlock() {
	ticket[id] = 0;
}

int main() {
	printf("Enter Number of Processes: ");
	scanf("%d", &n);
	ticket = mmap(NULL, (n + 1) * sizeof(int), PROT_READ | PROT_WRITE,
               MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    choose = mmap(NULL, (n + 1) * sizeof(int), PROT_READ | PROT_WRITE,
               MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    cnt = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
               MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    tickets = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
               MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *cnt = 0;
	*tickets = 1;
	pid_t pid;
	for(int i = 0; i < n; i++) {
		pid = fork();
		if (!pid) break;
	}
	if (!pid) {
		id = ++(*cnt);	
		while(1) {
			printf("\tNon-Critical section of Process #%d\n", id);
			sleep(1);
			lock();
			//C.S.
			printf("Critical Section Allocated to Process #%d with Ticket #%d\n", id, ticket[id]);
			sleep(rand() % 4);
			unlock();
			printf("\tOut of Critical Section Process #%d\n", id);
			sleep(1);
		}
	} else {
		wait(NULL);
		while(1);
		return 0;
	}
	return 0;
}

