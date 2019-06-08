#include<bits/stdc++.h>

using namespace std;
struct node
{
	int pno;
	int at;
	int bt;
};
bool cmp(struct node a,struct node b)
{
	if(a.at==b.at)
	{
		return a.pno<b.pno;
	}
	return a.at<b.at;
}
int main()
{
	int n,i;
	cout<<"Enter the number of processes:\t";
	cin>>n;
	cout<<"Enter the arrival time and burst time of "<<n<<" processes\n";
	struct node p[n];
	for(i=0;i<n;i++)
	{
		cin>>p[i].at>>p[i].bt;
		p[i].pno=i+1;
	}
	cout<<"You have entered:\npid\tat\tbt\n";
	for(i=0;i<n;i++)
	{
		cout<<p[i].pno<<"\t"<<p[i].at<<"\t"<<p[i].bt<<endl;
	}
	sort(p,p+n,cmp);
	int times=0;
	int wt[n],rt[n],tat[n],ct[n];
	float wtt=0.0,rtt=0.0,tatt=0.0;
	cout<<"\t\t\tScheduling:\n\n";
	cout<<"T\tpid\tat\tbt\trt\twt\tct\ttat\n";
	for(i=0;i<n;i++)
	{
		times=max(p[i].at,times);
		rt[i]=times-p[i].at;
		ct[i]=times+p[i].bt;
		wt[i]=times-p[i].at;
		tat[i]=wt[i]+p[i].bt;
		cout<<times<<"\t"<<p[i].pno<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<rt[i]<<"\t"<<wt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<endl;
		times=times+p[i].bt;
		wtt+=(float)wt[i];
		rtt+=(float)rt[i];
		tatt+=(float)tat[i];
	}
	wtt/=(float)n;
	rtt/=(float)n;
	tatt/=(float)n;
	cout<<"\nAverage response time = "<<rtt<<" units"<<endl;
	cout<<"\nAverage waiting time = "<<wtt<<" units"<<endl;
	cout<<"\nAverage turn around time = "<<tatt<<" units"<<endl<<endl;
	return 0;
}
