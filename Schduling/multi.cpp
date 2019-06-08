#include<bits/stdc++.h>
using namespace std;

struct multi
{
	int arrivalTime;
	int burstTime;
	int priority;
	int processId;
};

bool cmp(struct multi aer,struct multi aer1)
	{
		if(aer.arrivalTime == aer1.arrivalTime)
			return aer.processId < aer1.processId;
		return aer.arrivalTime < aer1.arrivalTime;
	};


bool cmp1(struct multi aer,struct multi aer1){
	if(aer.arrivalTime == aer1.arrivalTime)return aer.processId < aer1.processId;
	return aer.arrivalTime < aer1.arrivalTime;
}

int main()
{

	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq1;
	pair <int, int> p;
	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq2;
	pair <int, int> p1;
	int i,n;
	cout<<"Enter the no of processess-";
	cin>>n;
	struct multi asd[n+1];
	cout<<"if it is a system process then priority 1\n";
	cout<<"if it is a interactive process then priority 2\n";
	cout<<"if it is a batch process then priority 3\n";
	cout<<"Enter the arrival time and Burst time and priority of processes-\n";
	int rt[10000], ct[10000], at[10000], bt[10000];
	for(i=0;i<n;i++)
		{
			cin>>asd[i].arrivalTime>>asd[i].burstTime>>asd[i].priority;
			at[i] = asd[i].arrivalTime;
			bt[i] = asd[i].burstTime;
			asd[i].processId=i+1;
		}
	sort(asd,asd+n,cmp1);
	struct multi asd3[n+1];
	//process asd1[n],asd2[n];
	int fcf=0,g=0;
	//int sjf1=0;
	//int sfj2=0;
	int t = 0; 
	i = 0;
	int j;
	t=asd[i].arrivalTime;
	while(1)
	{
	for(j=i;j<n;j++)
		{
			if(asd[j].arrivalTime<=t)
			{
			 if(asd[j].priority==3)
				{
					asd3[fcf].arrivalTime=asd[j].arrivalTime;
					asd3[fcf].burstTime=asd[j].burstTime;
					asd3[fcf].processId=asd[j].processId;
					asd3[fcf].priority=asd[j].priority;
					fcf++;
				}
			else if(asd[j].priority==1)
				{
					pq1.push(make_pair(asd[j].burstTime, asd[j].processId));
					//asd1[sjf1]arrivalTime=asd[i].arrivalTime;
					//asd1[sfj1].burstTime=asd[i].burstTime;
					//asd1[sfj1].processId=i+1;
					//sfj1++;
				}
			else
				{
					pq2.push(make_pair(asd[j].burstTime, asd[j].processId));
					//asd2[sjf2]arrivalTime=asd[i].arrivalTime;
					//asd2[sfj2].burstTime=asd[i].burstTime;
					//asd2[sfj2].processId=i+1;
					//sfj2++;
				}
			}
		   else
		   		break;
		}
		i=j;
		if(pq1.empty() && i==n && pq2.empty() && g>=fcf){break;}
		else if(pq2.empty() && pq1.empty() && g>=fcf){t++; continue;}
		
		if(!pq1.empty())
		{
		p = pq1.top();
		pq1.pop();
		rt[p.second - 1] = t;
		t += (p.first);
		ct[p.second - 1] = t;
		}
		else if (!pq2.empty())
		{
		p1 = pq2.top();
		pq2.pop();
		rt[p1.second - 1] = t;
		t += (p1.first);
		ct[p1.second - 1] = t;
		}
		else if(g<fcf)
		{
			if(t < asd3[g].arrivalTime)
			{
				t=asd3[g].arrivalTime;
				break;
			}
			rt[asd3[g].processId-1]=t;
			ct[asd3[g].processId-1]=asd3[g].burstTime+t;
			t=t+asd3[g].burstTime;
			g++;
		}
	}
	int frt[100], fta[100], fwt[100];
	double avg_wt = 0.0, avg_rt = 0.0, avg_ta = 0.0;
	for(i = 0; i < n; i++){
		frt[i] = rt[i] - at[i];
		fta[i] = ct[i] - at[i];
		fwt[i] = ct[i] - at[i] - bt[i];
	}
	cout<<"Pno\tAt\tct\trt\tta\twt"<<endl;
	for(i = 0; i < n; i++){
		cout<<i+1<<"\t"<<at[i]<<"\t"<<ct[i]<<"\t"<<frt[i]<<"\t"<<fta[i]<<"\t"<<fwt[i]<<endl;
		avg_wt += (fwt[i] * 1.0);
		avg_rt += (frt[i] * 1.0);
		avg_ta += (fta[i] * 1.0);
	}
	avg_wt /= (n * 1.0);
	avg_rt /= (n * 1.0);
	avg_ta /= (n * 1.0);
	cout<<"Average waiting time:"<<avg_wt<<"\nAverage response time: "<<avg_rt<<"\nAverage turnaround time: "<<avg_ta<<endl;
	return 0;	
}
