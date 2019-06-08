#include<bits/stdc++.h>

using namespace std;
struct node
{
	int pno;
	int at;
	int bt;
	bool flag;
};
bool cmp(struct node a,struct node b)
{
	if(a.at==b.at)
	{
		if(a.bt==b.bt)
			return a.pno<b.pno;
		return a.bt<b.bt;
	}
	return a.at<b.at;
}
bool check(struct node p[],int n)
{
	for(int i=0;i<n;i++)
		if(p[i].flag==false)
			return false;
	return true;
}

int main()
{
	int n,i;
	cout<<"Enter the number of processes:\t";
	cin>>n;
	cout<<"Enter the arrival time and burst time of "<<n<<" processes\n";
	struct node p[n];
	//int arr[n][3];
	for(i=0;i<n;i++)
	{
		cin>>p[i].at>>p[i].bt;
		p[i].pno=i+1;
		p[i].flag=false;
		/*arr[i][0]=p[i].pno=i+1;
		arr[i][1]=p[i].at;
		arr[i][2]=p[i].bt;*/
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	cout<<"You have entered:\npid\tat\tbt\n";
	for(i=0;i<n;i++)
	{
		cout<<p[i].pno<<"\t"<<p[i].at<<"\t"<<p[i].bt<<endl;
		
	}
	sort(p,p+n,cmp);
	int times=0,j,k;
	int wt[n],rt[n],tat[n],ct[n];
	int mapp[100000+1]={0};
	float wtt=0.0,rtt=0.0,tatt=0.0;
	cout<<"\t\t\tScheduling:\n\n";
	pq.push(make_pair(p[0].bt,p[0].pno));
	mapp[p[0].pno]=1;
	cout<<"T\tpid\tat\tbt\trt\twt\tct\ttat\n";
	//for(i=0;i<n;i++)
	while(1)
	{
		
		
		pair<int,int> it=pq.top();
		pq.pop();
		for(j=0;j<n;j++)
		{
			if((it).second==p[j].pno)
				break;
		}
		//struct node temp=p[j];
		times=max(p[j].at,times);
		//cout<<p[j].pno<<" ";
		rt[j]=times-p[j].at;
		ct[j]=times+p[j].bt;
		wt[j]=times-p[j].at;
		tat[j]=wt[j]+p[j].bt;
		cout<<times<<"\t"<<p[j].pno<<"\t"<<p[j].at<<"\t"<<p[j].bt<<"\t"<<rt[j]<<"\t"<<wt[j]<<"\t"<<ct[j]<<"\t"<<tat[j]<<endl;
		times=times+p[j].bt;
		p[j].flag=true;
		wtt+=(float)wt[j];
		rtt+=(float)rt[j];
		tatt+=(float)tat[j];
		lab:
		for(k=0;k<n;k++)
		{
			if(p[k].flag==false&&mapp[p[k].pno]==0)
			{
				if(p[k].at<=times)
				{
					pq.push(make_pair(p[k].bt,p[k].pno));
					mapp[p[k].pno]=1;
				}
			}
		}
		if(pq.empty()&&check(p,n))break;
		if(pq.empty()){times++; goto lab; }
		
	}
	wtt/=(float)n;
	rtt/=(float)n;
	tatt/=(float)n;
	cout<<"\nAverage response time = "<<rtt<<" units"<<endl;
	cout<<"\nAverage waiting time = "<<wtt<<" units"<<endl;
	cout<<"\nAverage turn around time = "<<tatt<<" units"<<endl<<endl;
	return 0;
}
