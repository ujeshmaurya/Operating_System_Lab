#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
struct node
{
	int pno;
	int at;
	int bt;
	int wt;
	int rt;
	int ct;
	bool chck;
	bool ck;
	int tat;
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
	int n,i,quant=3;
	cout<<"Enter the number of processes:\t";
	cin>>n;
	cout<<"Enter the arrival time and burst time of "<<n<<" processes\n";
	struct node p[n];
	for(i=0;i<n;i++)
	{
		cin>>p[i].at>>p[i].bt;
		p[i].pno=i+1;
		p[i].wt=0;
		p[i].rt=-1;
		p[i].ct=-1;
		p[i].chck=false;
		p[i].ck=false;
	}
	cout<<"You have entered:\npid\tat\tbt\n";
	for(i=0;i<n;i++)
	{
		cout<<p[i].pno<<"\t"<<p[i].at<<"\t"<<p[i].bt<<endl;
	}
	sort(p,p+n,cmp);
	int btime[n];
	for(i=0;i<n;i++)
	{
		btime[i]=p[i].bt;
	}
	int times=0;
	int wt[n],rt[n],tat[n],ct[n];
	float wtt=0.0,rtt=0.0,tatt=0.0;
	queue<int> q;
	cout<<"\t\t\tScheduling:\n\n";
	cout<<"pid\tat\trt\twt\tct\ttat\n";
	while(1)
	{
		//cout<<times<<" ";
		bool flag=true;
		for(i=0;i<n;i++)
		{
			if(times>=p[i].at&&p[i].ck==false)
			{
				q.push(i);
				p[i].ck=true;
			}
		}
		for(i=0;i<n;i++)
		{
			if(p[i].bt>0)
			{
				flag=false;
				break;
			}
		}
		if(q.empty()&&flag)
			break;
		//usleep(100000);
		if(q.empty())
		{
			times+=1;
			continue;
		}
		int temp=q.front();
		//cout<<p[temp].pno<<endl;
		q.pop();
		int ttimes=(p[temp].bt-quant<=0)?times+p[temp].bt:times+quant;
		for(i=0;i<n;i++)
		{
			if(ttimes>=p[i].at&&p[i].ck==false)
			{
				q.push(i);
				p[i].ck=true;
			}
		}
		if(p[temp].chck==false)
		{
			p[temp].chck=true;
			p[temp].rt=times-p[temp].at;
		}
		if(p[temp].bt-quant<=0)
		{
			p[temp].ct=times+p[temp].bt;
			times+=p[temp].bt;
			p[temp].bt=0;
		}
		else
		{
			times+=quant;
			p[temp].bt-=quant;
			q.push(temp);
		}
	}
	for(i=0;i<n;i++)
	{
		p[i].wt=p[i].ct-btime[i]-p[i].at;
		p[i].tat=p[i].ct-p[i].at;
		cout<<p[i].pno<<"\t"<<p[i].at<<"\t"<<p[i].rt<<"\t"<<p[i].wt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<endl;
		wtt+=(float)p[i].wt;
		rtt+=(float)p[i].rt;
		tatt+=(float)p[i].tat;
	}
	wtt/=(float)n;
	rtt/=(float)n;
	tatt/=(float)n;
	cout<<"\nAverage response time = "<<rtt<<" units"<<endl;
	cout<<"\nAverage waiting time = "<<wtt<<" units"<<endl;
	cout<<"\nAverage turn around time = "<<tatt<<" units"<<endl<<endl;
	return 0;
}
