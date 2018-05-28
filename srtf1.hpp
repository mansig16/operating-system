#include<iostream>
using namespace std;
struct p
{
	int pid;
	int at;
	int bt;
	int rt;
};

void srtf()
{
	p pro[100];
	int ct[100],wt[100],tat[100],t=0,n,comp=0,min=INT_MAX;
	int sum=0,sum1=0;
	
	cout<<"enter the no of processes";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		pro[i].pid=i+1;
		cout<<"enter the arrival time of "<<i+1<<"process";
		cin>>pro[i].at;
		cout<<"enter the burst time of "<<i+1<<"process";
		cin>>pro[i].bt;
		 pro[i].rt=pro[i].bt;
	}
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(pro[i].at<pro[j].at)
			{
			int	temp=pro[j].at;
				pro[j].at=pro[i].at;
				pro[i].at=temp;
			int		mp=pro[j].bt;
				pro[j].bt=pro[i].bt;
				pro[i].bt=mp;
			int	kp=pro[j].pid;
				pro[j].pid=pro[i].pid;
				pro[i].pid=kp;
					int	mop=pro[j].rt;
				pro[j].rt=pro[i].rt;
				pro[i].rt=mop;
			}
		}
	}
while(comp!=n)
	{
		for(int i=0;i<n;i++)
		{
			if((pro[i].at<=t) && (pro[i].rt<min) && (pro[i].rt>0))
			{
				min=pro[i].rt;
				pro[i].rt-=1;
				ct[i]=t+1;
				t++;
				if(pro[i].rt==0)
				{
					comp++;
				}
				if(min==1)
				{
					min=INT_MAX;
				}
			 }
			 
		}
	
	}
		for(int i=0;i<n;i++)
	{
			wt[i]=ct[i]-pro[i].at-pro[i].bt;
					tat[i]=wt[i]+pro[i].bt;
	
		sum=sum+wt[i];
		sum1=sum1+tat[i];
	}
	cout<<"process_id\t"<<"at\t"<<"bt\t"<<"ct\t"<<"tat\t"<<"wt\n";
	for(int i=0;i<n;i++)
	{
		cout<<pro[i].pid<<"\t\t"<<pro[i].at<<"\t"<<pro[i].bt<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\n";
		
	}
	cout<<"average waiting tym is"<<(float)sum/n;
	cout<<"\naverage turn around tym is "<<(float)sum1/n;
	
}
