#include<bits/stdc++.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

int main() 
{
	int var=1;
    int d=fork();
    if(d==0)
    	cout<<"It is child. My Pid id "<<getpid()<<" and my parent's pid is"<<getppid()<<endl;
	else
		cout<<"It is parent. My Pid id "<<getpid()<<" and my parent's pid is"<<getppid()<<endl;
    return 0;
}
