#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

static int *turn;

int main(void)
{
	turn=(int*)mmap(NULL, sizeof *turn, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	*turn=1;
	int d=fork();
	int c=fork();
	int cnt=0,cnt1=0;
	if(d>0)
	{
		while(1) 
		{
			printf("1 NON-CRITICAL SECTION\n\n");
			while(*turn != 1) 
			{
				printf("2 Waiting...\n\n");
				//cout<<"\t\t"<<*turn<<endl;
				sleep(2);
			}
			printf("******************\n");
			printf("1 CRITICAL SECTION\n");
			printf("******************\n\n");
		printf("1 Out of Critical Section\n\n");
		*turn = 2;
		sleep(3);
		}
	}
	if(c>0)
	{
		while(1) 
		{
			printf("\t\t\t\t\t\t\t\t\t2 NON-CRITICAL SECTION\n\n");
			while(*turn != 2) 
			{
				printf("\t\t\t\t\t\t\t\t\t2 Waiting...\n\n");
				//cout<<"\t\t"<<*turn<<endl;
				sleep(2);
			}
			printf("\t\t\t\t\t\t\t\t\t******************\n");
			printf("\t\t\t\t\t\t\t\t\t2 CRITICAL SECTION\n");
			printf("\t\t\t\t\t\t\t\t\t******************\n\n");
		printf("\t\t\t\t\t\t\t\t\t2 Out of Critical Section\n\n");
		*turn = 1;
		sleep(3);
		}
	}
	return 0;
}
