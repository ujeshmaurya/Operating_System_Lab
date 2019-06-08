
#include<bits/stdc++.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

int main() 
{
	int var=1;
    fork();
    cout<<"Hello world! "<<++var<<endl;
 	fork();
 	cout<<"\tHello world! "<<++var<<endl;
 	fork();
    cout<<"\t\tHello world! "<<++var<<endl;
    return 0;
}
