#include<stdio.h>
#include<stdint.h>
#include<pthread.h>
#include<limits.h>
int max=INT_MIN,min=INT_MAX;
void* find(void* arg){
	int* a=(int *)arg;
	int i;
	if(max<*a)
		max=*a;
	if(min>*a)
		min=*a;
}

void main(){
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		pthread_t tid;
		pthread_create(&tid,NULL,&find,(void*)(a+i));
		pthread_join(tid,NULL);	
	}
	printf("minimum is=%d maximum is=%d\n",min,max);
}

