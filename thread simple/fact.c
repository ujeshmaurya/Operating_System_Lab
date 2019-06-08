#include<stdio.h>
#include<malloc.h>
#include<pthread.h>
int c_fact(int a){
        if(a==1)        
                return 1;
        return a*c_fact(a-1);
        
}
void* fact(void* arg){
        int* a=(int*)arg;
        printf("%d ",*a);
        int p[*a+1],i;
        p[0]=1;
        for(i=1;i<=*a;i++){
           p[i]=i*p[i-1];
        }
        //int k=c_fact(*a);
        printf("%d\n",p[*a]);
        
}
void main(){
       int n[1];
       scanf("%d",&n[0]);
       pthread_t tid;
       pthread_create(&tid,NULL,&fact,(void*)n);
       pthread_join(tid,NULL);
}
