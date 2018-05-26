/*valid for different and unique arrival times*/

#include<iostream>
using namespace std;



void priority_premp()
{
	struct process1
{
		int prior1;
	int pid;
	int at;
	int bt;
	int rt;
}pro1[100];
	
	
	int wt[100],tat[100],sum=0,sum1=0,n,ct[100];
	int max=0,t=0,comp=0;
	cout<<"enter the no of processes";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		pro1[i].pid=i+1;
		cout<<"enter the arrival time of "<<i+1<<"process";
		cin>>pro1[i].at;
		cout<<"enter the burst time of "<<i+1<<"process";
		cin>>pro1[i].bt;
			cout<<"enter the priority of "<<i+1<<"process";
		cin>>pro1[i].prior1;
		pro1[i].rt=pro1[i].bt;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(pro1[i].at>pro1[j].at)
			{
			int temp=pro1[j].prior1;
				pro1[j].prior1=pro1[i].prior1;
				pro1[i].prior1=temp;
			int	mp=pro1[j].bt;
				pro1[j].bt=pro1[i].bt;
				pro1[i].bt=mp;
			int	kp=pro1[j].pid;
				pro1[j].pid=pro1[i].pid;
				pro1[i].pid=kp;
			int tp=pro1[j].at;
				pro1[j].at=pro1[i].at;
				pro1[i].at=tp;
					int	mop=pro1[j].rt;
				pro1[j].rt=pro1[i].rt;
				pro1[i].rt=mop;
			}
				if(pro1[i].at==pro1[j].at)
				{
						
			if(pro1[i].prior1<pro1[j].prior1)
			{
				int ep=pro1[j].prior1;
				pro1[j].prior1=pro1[i].prior1;
				pro1[i].prior1=ep;
				int	mop=pro1[j].bt;
				pro1[j].bt=pro1[i].bt;
				pro1[i].bt=mop;
			int	kop=pro1[j].pid;
				pro1[j].pid=pro1[i].pid;
				pro1[i].pid=kop;
			}
	
				
			}
		}
	}
	

	for(int j=0;j<n;j++)
	{
	
		while(t<pro1[j].at)
		{
			t++;
		}
	
	for(int i=0;i<n;i++)
	{
		if(t==pro1[i].at)
		{
			pro1[i].rt--;
			ct[i]=t+1;
		}
		
	}
	t++;
}
	
	
		for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
						
			if(pro1[i].prior1<pro1[j].prior1)
			{
				int ep=pro1[j].prior1;
				pro1[j].prior1=pro1[i].prior1;
				pro1[i].prior1=ep;
				int	mop=pro1[j].bt;
				pro1[j].bt=pro1[i].bt;
				pro1[i].bt=mop;
			int	kop=pro1[j].pid;
				pro1[j].pid=pro1[i].pid;
				pro1[i].pid=kop;
				int	mp=pro1[j].rt;
				pro1[j].rt=pro1[i].rt;
				pro1[i].rt=mp;
				int eop=pro1[j].at;
				pro1[j].at=pro1[i].at;
				pro1[i].at=eop;
			}
	
		
	}
	
	
}
	ct[0]=t+pro1[0].rt;
		for(int i=1;i<n;i++)
	{
			ct[i]=ct[i-1]+pro1[i].rt;
		
	}
	
	for(int i=0;i<n;i++)
	{
			
		tat[i]=ct[i]-pro1[i].at;
		wt[i]=tat[i]-pro1[i].bt;
		sum=sum+wt[i];
		sum1=sum1+tat[i];
		
	}
	cout<<"process_id\t"<<"at\t"<<"prior\t"<<"bt\t"<<"ct\t"<<"tat\t"<<"wt\n";
	for(int i=0;i<n;i++)
	{
		cout<<pro1[i].pid<<"\t\t"<<pro1[i].at<<"\t"<<pro1[i].prior1<<"\t"<<pro1[i].bt<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\n";
		
	}
	cout<<"average waiting tym is"<<(float)sum/n;
	cout<<"\naverage turn around tym is "<<(float)sum1/n;

}
