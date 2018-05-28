#include<iostream>
using namespace std;


void sjf_same()
{
	struct process
{
	int pid;
	int bt;
	int at;
}p[10];

	int wt[10],tat[10];
	int sum=0,sum1=0;
	cout<<"enter the no of processes";
	int n;
	int temp,kp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		p[i].pid=i+1;
		cout<<"enter the burst time of "<<i+1<<" process";
		cin>>p[i].bt;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(p[i].bt<p[j].bt)
			{
				temp=p[j].bt;
				p[j].bt=p[i].bt;
				p[i].bt=temp;
				kp=p[j].pid;
				p[j].pid=p[i].pid;
				p[i].pid=kp;
			}
		}
	}
	wt[0]=0;
	for(int i=0;i<n;i++)
	{
		wt[i+1]=wt[i]+p[i].bt;
		tat[i]=wt[i]+p[i].bt;
		sum=sum+wt[i];
		sum1=sum1+tat[i];
	}
	cout<<"process_id\t"<<"bt\t"<<"tat\t"<<"wt\n";
	for(int i=0;i<n;i++)
	{
		cout<<p[i].pid<<"\t\t"<<p[i].bt<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\n";
		
	}
	cout<<"average waiting tym is"<<(float)sum/n;
	cout<<"\naverage turn around tym is "<<(float)sum1/n;

}
