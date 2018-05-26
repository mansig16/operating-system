#include<iostream> 
 using namespace std;
 

void roundrobin() 
{ 

 struct process
{
	int pid;
	int bt;
	int at;
	int rt;
};
 process p[10];
  int i,j,n,t,r,done=0,tq; 
  int wt=0,tat=0; 
  cout<<"Enter Total Process:\t "; 
  cin>>n; 
  r=n; 
  for(i=0;i<n;i++) 
  { 
    p[i].pid=i+1;
		cout<<"enter the arrival time of "<<i+1<<" process";
		cin>>p[i].at;
		cout<<"enter the burst time of "<<i+1<<" process";
		cin>>p[i].bt;
			p[i].rt=p[i].bt;
  } 
  cout<<"Enter Time Quantum:\t"; 
  cin>>tq;
 cout<<"process_id\t"<<"at\t"<<"bt\t"<<"tat\t"<<"wt\n";
  for(t=0,i=0;r!=0;) 
  { 
    if(p[i].rt<=tq && p[i].rt>0) 
    { 
      t+=p[i].rt; 
      p[i].rt=0; 
      done=1; 
    } 
    else if(p[i].rt>0) 
    { 
      p[i].rt-=tq; 
      t+=tq; 
    } 
    if(p[i].rt==0 && done==1) 
    { 
      r--; 
     cout<<p[i].pid<<"\t\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<t-p[i].at<<"\t"<<t-p[i].at-p[i].bt<<"\n"; 
      wt+=t-p[i].at-p[i].bt; 
      tat+=t-p[i].at; 
      done=0; 
    } 
    if(i==n-1) 
      i=0; 
    else if(p[i+1].at<=t) 
      i++; 
    else 
      i=0; 
  } 
 
	
	
	cout<<"average waiting tym is "<<(float)wt/n;
	cout<<"\naverage turn around tym is "<<(float)tat/n; 
  

}
