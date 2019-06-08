#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

sem_t read,write,mutex;
int read_count=0;
void* reader(void* arg)
{
  while(1){
   
   sem_wait(&mutex);
   read_count++;
   if(read_count==1)
     sem_wait(&write);
   sem_post(&mutex);
   
   printf("Reading %d started\n",(int)arg);
    sleep(1);
    printf("Reading %d finished\n",(int)arg);

   sem_wait(&mutex);
   read_count--;
   if(read_count==0)
     sem_post(&write);
   sem_post(&mutex);
   sleep(1);
 }
}
void* writer(void* arg)
{
   while(1)
   {
    sleep(1);
    sem_wait(&write);
    printf("Writing %d started\n",(int)arg);
    sleep(1);
    printf("Writing %d finished\n",(int)arg);
    sem_post(&write);
    sleep(1);
   }
}


int main(int argc,char* arg[])
{	
	int i;
  
   sem_init(&mutex,0,1);
   sem_init(&write,0,1);
  
   int num_readers=atoi(arg[1]);
   int num_writers=atoi(arg[2]);

   pthread_t readth[num_readers],writeth[num_writers];
   for(i=0;i<num_readers;i++)
   pthread_create(&readth[i],NULL,reader,(void*)i);

   for(i=0;i<num_writers;i++)
   pthread_create(&writeth[i],NULL,writer,(void*)i);

  for(i=0;i<num_readers;i++)
   pthread_join(readth[i],NULL);

   for(i=0;i<num_writers;i++)
   pthread_join(writeth[i],NULL);

  return 0;
}
