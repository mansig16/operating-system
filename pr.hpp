#include<iostream>
using namespace std;


void priority()
{
struct process1
{
	int pid;
	int prior;
	int at;
	int bt;
}pro[100];


//	p pro[100];
	int wt[100],tat[100],sum=0,sum1=0,n,ct[100];
	cout<<"enter the no of processes";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		pro[i].pid=i+1;
		cout<<"enter the arrival time of "<<i+1<<"process";
		cin>>pro[i].at;
		cout<<"enter the burst time of "<<i+1<<"process";
		cin>>pro[i].bt;
			cout<<"enter the priority of "<<i+1<<"process";
		cin>>pro[i].prior;
	
	}
	
		for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(pro[i].at>pro[j].at)
			{
			int temp=pro[j].prior;
				pro[j].prior=pro[i].prior;
				pro[i].prior=temp;
				int	mp=pro[j].bt;
				pro[j].bt=pro[i].bt;
				pro[i].bt=mp;
			int	kp=pro[j].pid;
				pro[j].pid=pro[i].pid;
				pro[i].pid=kp;
				int tp=pro[j].at;
				pro[j].at=pro[i].at;
				pro[i].at=tp;
	}
				if(pro[i].at==pro[j].at)
				{
						
			if(pro[i].prior<pro[j].prior)
			{
				int ep=pro[j].prior;
				pro[j].prior=pro[i].prior;
				pro[i].prior=ep;
				int	mop=pro[j].bt;
				pro[j].bt=pro[i].bt;
				pro[i].bt=mop;
			int	kop=pro[j].pid;
				pro[j].pid=pro[i].pid;
				pro[i].pid=kop;
			}
	
				
			}
		
	}
	
	
}
		wt[0]=pro[0].at;
	ct[0]=pro[0].at+pro[0].bt;
	tat[0]=ct[0]-pro[0].at;
	
	
	

	
		for(int i=1;i<n;i++)
	{
			ct[i]=ct[i-1]+pro[i].bt;
		tat[i]=ct[i]-pro[i].at;
		wt[i]=tat[i]-pro[i].bt;
		sum=sum+wt[i]+wt[0];
		sum1=sum1+tat[i]+tat[0];
		
	}
	cout<<"process_id\t"<<"at\t"<<"prior\t"<<"bt\t"<<"ct\t"<<"tat\t"<<"wt\n";
	for(int i=0;i<n;i++)
	{
		cout<<pro[i].pid<<"\t\t"<<pro[i].at<<"\t"<<pro[i].prior<<"\t"<<pro[i].bt<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\n";
		
	}
	cout<<"average waiting tym is"<<(float)sum/n;
	cout<<"\naverage turn around tym is "<<(float)sum1/n;

}
