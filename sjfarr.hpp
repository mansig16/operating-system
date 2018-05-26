#include<iostream>
using namespace std;


void sjf()
{
	struct process
{
	int pid1;
	int bt1;
	int at1;
}p[10];
	int wt1[10],tat1[10],ct1[10];
	int sum1=0,sum11=0;
	cout<<"enter the no of processes";
	int n1;
	int temp1,kp1;
	cin>>n1;
	for(int i=0;i<n1;i++)
	{
		p[i].pid1=i+1;
		cout<<"enter the arrival time of "<<i+1<<" process";
		cin>>p[i].at1;
		cout<<"enter the burst time of "<<i+1<<" process";
		cin>>p[i].bt1;
	}
	ct1[0]=p[0].bt1;

	for(int j=0;j<n1;j++)
	{
		for(int i=j+1;i<n1;i++)
		{
			if(p[i].at1<=ct1[j]  )
			{
				if(p[i+1].at1<=ct1[j])
				{
				
				if(p[i+1].bt1<p[i].bt1)
			{
				temp1=p[i+1].bt1;
				p[i+1].bt1=p[i].bt1;
				p[i].bt1=temp1;
				kp1=p[i+1].pid1;
				p[i+1].pid1=p[i].pid1;
				p[i].pid1=kp1;
				int	mp1=p[i+1].at1;
				p[i+1].at1=p[i].at1;
				p[i].at1=mp1;
			}
		}
		
			}
			
		}
		ct1[j+1]=ct1[j]+p[j+1].bt1;
	}
	wt1[0]=0;
	
	tat1[0]=ct1[0];
		for(int i=1;i<n1;i++)
	{

		tat1[i]=ct1[i]-p[i].at1;
		wt1[i]=tat1[i]-p[i].bt1;
	
		sum1=sum1+wt1[i];
		sum11=sum11+tat1[i];
	}
	cout<<"process_id\t"<<"at\t"<<"bt\t"<<"ct\t"<<"tat\t"<<"wt\n";
	for(int i=0;i<n1;i++)
	{
		cout<<p[i].pid1<<"\t\t"<<p[i].at1<<"\t"<<p[i].bt1<<"\t"<<ct1[i]<<"\t"<<tat1[i]<<"\t"<<wt1[i]<<"\n";
		
	}
	cout<<"average waiting tym is"<<(float)sum1/n1;
	cout<<"\naverage turn around tym is "<<(float)sum11/n1;

}
