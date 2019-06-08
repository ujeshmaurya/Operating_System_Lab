#include <stdio.h>
#include <pthread.h>

int sum = 0;
pthread_attr_t attr;

void *series(int i) {
	printf("In Thread :: %d\n", i);
	int ret = 0;
	sum += i * i;
	pthread_t thread;
	if (i > 1) ret = pthread_create(&thread, &attr, series, i - 1);
	if (ret) {
		printf("Error in creating thread :: %d\n", (int)thread);
		exit(-1);
	}
	pthread_join(thread, NULL);
	pthread_exit(NULL);
}

int main() {
	int i = 0, ret = 0, n = 0;
	
	printf("Enter a Number :: ");
	scanf("%d", &n);
	
	pthread_t thread;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	ret = pthread_create(&thread, &attr, series, n);
	if (ret) {
		printf("Error in creating thread :: %d\n", (int)thread);
		exit(-1);
	}
	pthread_join(thread, NULL);
	pthread_attr_destroy(&attr);
	
	printf("Sum of Square of First %d Numbers\n", n);
	for(i = 0; i < n; i++) { printf("%d ", (i + 1) * (i + 1)); if (i != n - 1) printf("+ "); }
	printf("= %d\n", sum);
	pthread_exit(NULL);
	
	return 0;
}
