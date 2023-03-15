#ifndef NODE_H
#define NODE_H
#include <iostream>
#include<cstring>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include <iomanip>
#include "Node.h"
using namespace std;


struct node
{
   string no;//plate number
   int time; // vehicle entry time (in hours)
   int sub;//the location of the vehicle in the parking lot
} nod;
 map<string,int>mp;//used to detect the vehicle in the parking lot or in the sidewalk
 deque<node>q1;//simulated parking lot
 deque<node>q2;//simulated sidewalk
 stack<node>sk;//exchange medium
 // string str1="park",str2="pavement";
 void Push(int n)//vehicle driving operation
{
    cout<<"Please enter the license plate number to enter the vehicle "<<endl;
	string x;
	cin>>x;
	int y;
    cout<<"Please enter the time the vehicle enters the parking lot (eg 0210 1530)"<<endl;
	cin>>y;
	cout<<endl;
	 if(!mp[x])//if the car is not in the parking lot or in the sidewalk, execute the following command
	{
		  if(q1.size()<n)//if the parking lot is not full
		 {
			nod.no=x;
			nod.time=y;
			nod.sub=q1.size()+1;
			q1.push_back(nod);
			mp[x]=q1.size();
			 cout<<"successfully parked in the parking lot!"<<endl;
		 }
		  else // after the parking lot is full, enter the road
		 {
			 nod.no=x;
			 nod.time=y;
			 nod.sub=q2.size()+1;
			 q2.push_back(nod);
			 mp[x]=n+q2.size();
			  cout<<"Your vehicle is on the sidewalk waiting for parking"<<endl;
		 }
	}
	else
	 cout<<"  error: The vehicle is already in the parking lot!"<<endl;
}
 void Pop(int n)//vehicle exit operation
{
    cout<<"Please enter the license plate number "<<endl;
	string x;
	cin>>x;
	int y,ans,minutes,hours,inhour;
	float payment;
    cout<<"Please enter the time when the vehicle leaves the parking lot (eg 0210 1530)"<<endl;
	cin>>y;
	cout<<endl;
	if(!mp[x])
		 cout<<"  error: The car is not in the parking lot!"<<endl;
    else if(mp[x]<=n)//if the car is in the parking lot
	{
		mp[x]=0;
		 while(q1.back().no!=x)//Car out
		{
			q1.back().sub--;
			sk.push(q1.back());
			q1.pop_back();
		}
		if(y<q1.back().time)
        {
            y=y+2400;
		}
		 ans=y-q1.back().time;
		 hours=ans/100;
		 minutes=ans-hours*100+hours*60;
		 inhour=minutes/60;
		 minutes=minutes%60;

		 payment=hours*5+minutes*5.0/60;
		 q1.pop_back();
		 while(!sk.empty())
		 {
			 q1.push_back(sk.top());
			 sk.pop();
			 mp[q1.back().no]=q1.back().sub;
		 }
         if(!q2.empty())//if there is also a car in the sidewalk, then enter the parking lot and the car behind the sidewalk moves forward
		 {
			 q2.front().time=y;
			 q2.front().sub=q1.size()+1;
			 q1.push_back(q2.front());
			 q2.pop_front();
			 while(!q2.empty())
			 {
				 q2.back().sub--;
				 sk.push(q2.back());
				 q2.pop_back();
			 }
			 while(!sk.empty())
			 {
				 q2.push_back(sk.top());
				 sk.pop();
				 mp[q2.back().no]=n+q2.back().sub;
			 }
			 mp[q1.back().no]=q1.size();
		 }
	  cout<<"**The vehicle has been parked for a total of "<<hours<<" hours "<<minutes<<" minutes"<<endl;
	  cout<<"**so the vehicle needs to pay "<<setprecision(4)<<payment<<" rupees "<<endl;
	}
	 else if(mp[x]>n)//if the car is in the sidewalk, then leave directly and the car behind moves forward
	{
		mp[x]=0;
		while(q2.back().no!=x)
		{
			 q2.back().sub--;
			 sk.push(q2.back());
			 q2.pop_back();
		}
		q2.pop_back();
		while(!sk.empty())
		{
			 q2.push_back(sk.top());
			 sk.pop();
		}
		 cout<<"**Since the vehicle does not enter the parking lot, there is no charge**"<<endl;
	}
}
 void Query1(int n)//Query the parking status of the parking lot
{
    cout<<"Please enter the license plate number "<<endl;
	string x;
	cin>>x;
	cout<<endl;
	if(!mp[x])
		 cout<<"The vehicle is not in the parking lot"<<endl;
	else if(mp[x]<=n)
		 cout<<"The vehicle is located in the parking lot "<<mp[x]<<endl;
	else
		 cout<<"The vehicle is located at the position "<<mp[x]-n<<" in sidewalk"<<endl;
}
 void Query2(int n)//Query the empty parking space of the parking lot
{
	cout<<endl;
	if(q1.size()==n)
	{
		 cout<<"Parking is full"<<endl;
	}
	else
	{
		 cout<<" Parking lot "<<q1.size()+1;
		for(int i=q1.size()+2; i<=n; i++)
		cout<<" "<<i;
		cout<<" position is empty"<<endl;
	}
}
#endif


