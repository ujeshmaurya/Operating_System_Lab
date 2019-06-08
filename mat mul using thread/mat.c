#include <stdio.h>
#include <pthread.h>

int n1, m1, n2, m2, a1[100][100], a2[100][100], mat[100][100];

void *mul() {
	int i = 0, j = 0, k = 0;
	for(i = 0; i < n1; i++) {
		for(j = 0; j < m2; j++) {
			mat[i][j] = 0;
			for(k = 0; k < n2; k++) mat[i][j] += a1[i][k] * a2[k][j];
		}
	}
	pthread_exit(NULL);
}

int main() {
	int i = 0, j = 0, ret = 0;
	
	printf("Enter Size of 1st Matrix :: ");
	scanf("%d%d", &n1, &m1);
	printf("Enter 1st Matrix\n");
	for(i = 0; i < n1; i++) for(j = 0; j < m1; j++) scanf("%d", &a1[i][j]);
	
	printf("Enter Size of 2nd Matrix :: ");
	scanf("%d%d", &n2, &m2);
	if (m1 != n2) {
		printf("\n\n\t\tHeHe Matrices are not Compatible for Multiplication\n\n\n");
		return 1;
	}
	printf("Enter 2nd Matrix\n");
	for(i = 0; i < n2; i++) for(j = 0; j < m2; j++) scanf("%d", &a2[i][j]);
	
	pthread_t thread;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	ret = pthread_create(&thread, &attr, mul, NULL);
	if (ret) {
		printf("Error in creating thread :: %d\n", (int)thread);
		exit(-1);
	}
	pthread_join(thread, NULL);
	pthread_attr_destroy(&attr);
	
	printf("Size of Output Matrix :: %d %d\n", n1, m2);
	printf("Output Matrix\n");
	for(i = 0; i < n1; i++) { for(j = 0; j < m2; j++) printf("%d ", mat[i][j]); printf("\n"); }
	pthread_exit(NULL);
	
	return 0;
}
