#include <stdio.h>
#include <signal.h>

int flag = 1;

void catch(int signo) {
	printf("\t\tSIGNAL MESSAGE :: %d\n", signo);
	flag = 0;
}

int main() {
	int pid = getpid(), tm = 0;
	signal(SIGINT, catch);
	while(flag) {
		fork();
		pid = getpid();
		sleep(1);
		tm += 1;
		printf("Sleep time:: %d seconds\nProcess Id :: %d\n", tm, pid);
	}
	return 0;
}
