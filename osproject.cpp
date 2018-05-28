
#include<iostream>
#include"fcfs1.hpp"
#include"sjfarr.hpp"
#include"srtf1.hpp"
#include"pr.hpp"
#include"r.hpp"
//#include"priorpremp.hpp"
#include"sjf.hpp"
using namespace std;


int main()
{
	cout<<"enter your choice\n";
	cout<<"press 1 for fcfs scheduling algorithm\n"<<"press 2 for sjf with different arrival time scheduling algorithm\n"<<"press 3 for srtf with diffrent arrival time scheduling algorithm\n"<<"press 4 for priority without premption scheduling algorithm\n"/*<<"press 5 for priority with premption scheduling algorithm\n"*/;
	cout<<"press 5 for round robin scheduling algorithm\n";
		cout<<"press 6 for sjf with same arrival time scheduling algorithm\n";
	int n;
	cin>>n;
	switch(n)
	{
		case 1:
			{
			cout<<"fcfs\n\n";
			fcfs();
			break;
			}
		case 2:
			{
			cout<<"sjf\n\n";
			sjf();
			break;
			}
		case 3:
			{
			cout<<"srtf\n\n";
			srtf();
			break;
			}
	case 4:
			{
			cout<<"priority without premption\n\n";
			priority();
			break;
			}
		/*case 5:
			{
			cout<<"priority with premption\n\n";
			priority_premp();
			break;
			}*/
		case 5:
			{
			cout<<"round robin\n\n";
			roundrobin();
			break;
			}
				case 6:
			{
			cout<<"sjf with same arrival time\n\n";
			sjf_same();
			break;
			}
		default:
			{
				cout<<"no such case exist";
			}
	}
	return 0;
}
