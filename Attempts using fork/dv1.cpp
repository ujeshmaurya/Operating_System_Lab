#include<bits/stdc++.h>
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

static int *turn;

int cnt = 0 ;

int main(void)
{
	turn = (int*)mmap(NULL, sizeof *turn, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    
    *turn = 1;
    
	if(fork()==0)
		{
				while(1) 
				{
				printf("\t\tp NON-CRITICAL SECTION\n\n");
				while(*turn != 1) {
					printf("\t\tp Waiting...\n\n");
					sleep(5);
				}
				{
					printf("\t\t==================\n");
					printf("\t\tp CRITICAL SECTION\n");
					printf("\t\t==================\n\n");
				}
				printf("\t\tp Out of Critical Section\n\n");
				*turn = 2;
				sleep(7);
				//cnt++;
				//if (cnt == 3)exit(0);
				
			}
			
		}
	if(fork()>0)
		{
				while(1) {
				//int c = 0;
				printf("\tq NON-CRITICAL SECTION\n\n");
				while(*turn != 2) {
					//c++;
					printf("\tq Waiting...\n\n");
					//if (cnt == 3 && c > 7) {
					//	printf("Starvation, process p preempted\n");
						//exit(0);
					//}
					sleep(5);
				}
				{
					printf("\t==================\n");
					printf("\tq CRITICAL SECTION\n");
					printf("\t==================\n\n");
				}
				
				printf("\tq Out of Critical Section\n\n");
				*turn = 1;
				sleep(7);
			}
			
		}

	return 0;
}
