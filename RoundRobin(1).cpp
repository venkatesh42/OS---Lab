#include<iostream>
using namespace std;
int main()

{

      int i,noOfProcess,total=0,x,counter=0,time_quantum;

      int wait_time=0,turnaround_time=0,arrival_time[10],burst_time[10],temp[10];

      float average_wait_time, average_turnaround_time;

      cout<<"Enter total no of Procesess:";

      cin>>noOfProcess;

      x=noOfProcess;

      for(i=0;i<noOfProcess;i++)

      {

            cout<<"\nEnter Details of Process"<<i+1<<":\n";

            cout<<"Arrival Time:";

            cin>>arrival_time[i];

            cout<<"Burst Time:";

            cin>>burst_time[i];

            temp[i]=burst_time[i];

      }

      cout<<"\nEnter Time Quantum:";

      cin>>time_quantum;

      cout<<"\nProcess "<<"\tBurstTime"<<" \tArrivalTime"<<"\tTurnaroundTime"<<"\tWaiting Time";

      for(total=0,i=0;x!=0;)

      {

            if(temp[i]<=time_quantum&&temp[i]>0)

            {

                  total=total+temp[i];

                  temp[i]=0;

                  counter=1;

            }

            else if(temp[i]>0)

            {

                  temp[i]=temp[i]-time_quantum;

                  total=total+time_quantum;

            }

            if(temp[i]==0&&counter==1)

            {

                  x--;
                  cout<<"\nProcess"<<i+1<<"\t\t"<<burst_time[i]<<"\t\t"<<arrival_time[i]<<"\t\t"<<total-arrival_time[i]<<"\t\t"<<total-arrival_time[i]-burst_time[i];

                  wait_time=wait_time+total- arrival_time[i]-burst_time[i];

                  turnaround_time=turnaround_time+total-arrival_time[i];

                  counter=0;

            }

            if(i==noOfProcess-1)

            {

                  i=0;

            }

            else if(arrival_time[i+1]<=total)

            {

                  i++;

            }

            else

            {

                  i=0;

            }

      }

      average_wait_time=wait_time*1.0/noOfProcess;

      average_turnaround_time=turnaround_time*1.0/noOfProcess;

      cout<<"\n\nAverage Waiting Time:"<<average_wait_time;

      cout<<"\nAvg Turnaround Time:"<<average_turnaround_time;

      return 0;

}

