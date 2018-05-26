#include<iostream>

using namespace std;


void fcfs()
{
	struct process
{
	int pid;
	int bt;
	int at;
}p[10];
	int wt[10],tat[10],ct[10];
	int sum=0,sum1=0;
	cout<<"enter the no of processes";
	int n;
	int temp,kp,mp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		p[i].pid=i+1;
		cout<<"enter the arrival time of "<<i+1<<" process";
		cin>>p[i].at;
		cout<<"enter the burst time of "<<i+1<<" process";
		cin>>p[i].bt;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(p[i].at<p[j].at)
			{
				temp=p[j].at;
				p[j].at=p[i].at;
				p[i].at=temp;
					mp=p[j].bt;
				p[j].bt=p[i].bt;
				p[i].bt=mp;
				kp=p[j].pid;
				p[j].pid=p[i].pid;
				p[i].pid=kp;
			}
		}
	}
	wt[0]=p[0].at;
	ct[0]=p[0].at+p[0].bt;
	tat[0]=ct[0]-p[0].at;
	for(int i=1;i<n;i++)
	{
		ct[i]=ct[i-1]+p[i].bt;
		tat[i]=ct[i]-p[i].at;
		wt[i]=tat[i]-p[i].bt;
		sum=sum+wt[i]+wt[0];
		sum1=sum1+tat[i]+tat[0];
	}
	cout<<"process_id\t"<<"at\t"<<"bt\t"<<"ct\t"<<"tat\t"<<"wt\n";
	for(int i=0;i<n;i++)
	{
		cout<<p[i].pid<<"\t\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\n";
		
	}
	cout<<"average waiting tym is"<<(float)sum/n;
	cout<<"\naverage turn around tym is "<<(float)sum1/n;

}
