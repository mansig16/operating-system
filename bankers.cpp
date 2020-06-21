#include<iostream>
using namespace std;
int main()
{
	int nop,nor;
		int finish[nop],work[nor];
	cout<<"enter the no of processes";
	cin>>nop;
	cout<<"enter the no of resources";
	cin>>nor;
	int avail[nor];
	cout<<"enter the no of available resources of each type";
	for(int i=0;i<nor;i++)
	{
		cin>>avail[i];
		work[i]=avail[i];
	}
	cout<<"enter the maximum demand of each resource of each type";
	int max[nop][nor];
	for(int i=0;i<nop;i++)
	{
		for(int j=0;j<nor;j++)
		{
			cin>>max[i][j];
		}
		finish[i]=0;
	}
	cout<<"enter the allocated number of each resource of each type";
	int alloc[nop][nor];
	for(int i=0;i<nop;i++)
	{
		for(int j=0;j<nor;j++)
		{
			cin>>alloc[i][j];
		}
	}
	cout<<"the need matrix is\n";
	int need[nop][nor];
	for(int i=0;i<nop;i++)
	{
		for(int j=0;j<nor;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
			cout<<need[i][j]<<" ";
		}
		cout<<"\n";
	}
	int count=0,c=0;
	while(c<nop)
	{
		for(int i=0;i<nop;i++)
		{
			count=0;
			if(finish[i]==0)
			{
				int j;
				for( j=0;j<nor;j++)
				{
					if(need[i][j]>work[j])
					{
						break;
					}
					//count++;
				}
			
				if(j==nor)
				{
					for(int k=0;k<nor;k++)
					{
						work[k]+=alloc[i][k];
					}
					finish[i]=1;
					c++;
				}
			}
			
		}
			if(c!=nop)
		{
			cout<<"system is not in safe state";
			return 0;
		}
	}

			cout<<"system is not in safe state";
		
	
	return 0;
}
