#include<iostream.h>
#include<conio.h>
#include<stdio.h>
int i,no;
class fcfs{
public:
int bt[10],wt[10],tp[10];
float sum_wt,sum_tp;
float av_wt,av_tp;
fcfs()
{
sum_wt=0;
sum_tp=0;
}
void init();
void input_burst();
void input_waiting();
void input_turn();
void average();
void output();
};
void main()
{
clrscr();
fcfs f;
f.init();
f.input_burst();
f.input_waiting();
f.input_turn();
f.average();
f.output();
getch();
}
void fcfs::input_burst()
{
for(i=1;i<=no;++i)
{
cout<<"Enter Burst time for Process "<<i<<": ";
cin>>bt[i];
}
cout<<"\n***************************\n";
}


void fcfs::init()
{
cout<<"Enter number of Process: ";
cin>>no;
cout<<"\n***************************\n";
}
void fcfs::input_waiting()
{
wt[1]=0;
for(i=2;i<=no;++i)
{
wt[i]=wt[i-1]+bt[i-1];
}
}
void fcfs::input_turn()
{
for(i=1;i<=no;++i)
{
tp[i]=wt[i]+bt[i];
}
}
void fcfs::average()
{
for(i=1;i<=no;++i)
{
sum_wt=sum_wt+wt[i];
sum_tp=sum_tp+tp[i];
}
av_wt=(float)(sum_wt/no);
av_tp=(float)(sum_tp/no);
}
void fcfs::output()
{
cout<<"Process no\tBurst time\tWaiting time\tTurnaround time\n";
for(i=1;i<=no;++i)
{
cout<<i<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tp[i]<<"\n";
}
cout<<"\n***************************\n";
cout<<"Average Waiting time: "<<av_wt<<"\n";
cout<<"Average Turnaround time: "<<av_tp;
cout<<"\n***************************\n";
}