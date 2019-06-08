#include<bits/stdc++.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

int main() 
{
	int var=1;
    int d1=fork();
    int d2=fork();
    if(d1==0&&d2==0)
    	cout<<"It is 1. My Pid is "<<getpid()<<" and my parent's pid is "<<getppid()<<endl<<endl;
	usleep(1000);
	
	if(d1==0&&d2!=0)
		cout<<"\tIt is 2. My Pid is "<<getpid()<<" and my parent's pid is "<<getppid()<<endl<<endl;
	usleep(1000);
	
	if(d1!=0&&d2==0)
    	cout<<"\t\tIt is 3. My Pid is "<<getpid()<<" and my parent's pid is "<<getppid()<<endl<<endl;
	usleep(1000);
	
	if(d2!=0&&d1!=0)
		cout<<"\t\t\tIt is 4. My Pid is "<<getpid()<<" and my parent's pid is "<<getppid()<<endl;
	usleep(1000);
    return 0;
}
