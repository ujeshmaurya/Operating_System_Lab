#include<bits/stdc++.h>
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

static bool *wantp, *wantq;
static int *c;
static int *cnt;

int main(void)
{
	cnt = (int*)mmap(NULL, sizeof *cnt, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	wantp = (bool*)mmap(NULL, sizeof *wantp, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	wantq = (bool*)mmap(NULL, sizeof *wantq, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	c = (int*)mmap(NULL, sizeof *c, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    
    *wantp = false;
    *wantq = false;
    *c = 0;
    *cnt = 0;
    
	if(fork()==0)
		{
				while(1) {
				printf("\t\tp NON-CRITICAL SECTION\n\n");
				while(*wantq != false) {
					printf("\t\tp Waiting...\n\n");
					sleep(1);
				}
				if (*c >= 4) sleep(1);
				*wantp = true;
				{
					
					printf("\t\t==================\n");
					printf("\t\tp CRITICAL SECTION\n");
					printf("\t\t==================\n\n");
					sleep(1);
					if (*wantq) {
						printf("both processes are in Critical Section\n");
						exit(0);
					}
				}
				*wantp = false;
				sleep(2);
				printf("\t\tp Out of Critical Section\n\n");
				sleep(1);
				//cnt++;
				c++;
	}
	//pthread_exit(NULL);
			
		}
	if(fork()>0)
		{
				while(1) {
				printf("\tq NON-CRITICAL SECTION\n\n");
				while(*wantp != false) {
					printf("\tq Waiting...\n\n");
					sleep(2);
				}
				if (*c >= 4) sleep(2);
				*wantq = true;
				{
					printf("\t==================\n");
					printf("\tq CRITICAL SECTION\n");
					printf("\t==================\n\n");
					sleep(2);
					if (*wantp) {
						exit(0);
					}
				}
				printf("\tq Out of Critical Section\n\n");
				*wantq = false;
				sleep(2);
			}
			//pthread_exit(NULL);
			
		}

	return 0;
}
