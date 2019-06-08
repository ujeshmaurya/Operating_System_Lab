#include<bits/stdc++.h>
using namespace std;
typedef struct process{
	int pno;
	int art;
	int brt;
} process;
bool func(process p1, process p2){
	if(p1.art == p2.art)return p1.pno < p2.pno;
	return p1.art < p2.art;
}
int main(){
	int n, i, j, no, quan;
	int rt[100], ct[100], at[100], bt[100], frt[100], fta[100], fwt[100];
	double avg_wt = 0.0, avg_rt = 0.0, avg_ta = 0.0;
	cout<<"Enter no. of processes: ";
	cin>>n;
	process arr[n + 1];
	cout<<"Enter quantum time: ";
	cin>>quan;
	cout<<"Enter arrival time and burst time for processes: "<<endl;
	for(i = 0; i < n; i++){		
		arr[i].pno = i + 1;		
		cin>>arr[i].art>>arr[i].brt;
		at[i] = arr[i].art;
		bt[i] = arr[i].brt;
	}
	sort(arr, arr + n, func);
	queue <process> q;
	process p;
	q.push(arr[0]);
	int t = arr[0].art;
	int flag; 
	i = 1; j = 0;
	while(!q.empty()||i<n){
		flag = 0;
		if(!q.empty()){
			flag = 1;
			p = q.front();
			q.pop();
			if(p.brt == bt[p.pno - 1])rt[p.pno - 1] = t;
			//cout<<p.pno<<" "<<p.brt<<" "<<t<<endl;
			if(p.brt>=quan){
				p.brt -= quan;
				t+=quan;
				//if(p.brt > 0)q.push(p);
				if(p.brt<=0){
					ct[p.pno - 1] = t;	
				}
			}
			else if(p.brt < quan){
				t+=p.brt;
				ct[p.pno - 1] = t;
				p.brt = 0;
			}
		}
		for(j = i; j < n; j++){
			if(t>=arr[j].art)q.push(arr[j]);
			else break;
		}
		i = j;
		if(flag && p.brt > 0)q.push(p);
		if(q.empty() && i<n){
			t++;
		}
	}
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
