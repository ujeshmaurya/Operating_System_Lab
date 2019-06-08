#include<pthread.h>
#include<stdio.h>
pthread_t tid[5];
void* printhello(void* arg){
	printf("thread processing.....\n");
	printf("Hello\n");
	}
int main(){
	int t=5;
	int k;
	while(t--){
		k=pthread_create(&(tid[t]),NULL,&printhello,NULL);
		
		if(k==0){
		printf("thread created successfully\n");
		}
		else{
		printf("Error\n");
		}
		//pthread_join(tid[t],NULL);
	}
	pthread_exit(NULL);

}
