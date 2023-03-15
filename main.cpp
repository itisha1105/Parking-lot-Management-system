#include  <iostream>
#include "Node.h"
using namespace std;
int main()
{
 int n;
 cout<<" **************Parking Management System**************"<<endl;
 cout<<endl;
 cout<<"Parking Management System Description: "<<endl;
 cout<<"1. When the parking space is full, the car will stop at the sidewalk "<<endl;
 cout<<"2. The parking lot is charged at the standard of thirty rupees per hour "<<endl;
 cout<<"3. There is no charge for vehicles parked on the sidewalk."<<endl;
 cout<<endl;
 Start:cout<<"Please set the total number of parking spaces in the parking lot: "<<endl;
 cin>>n;
 if (cin.good()!=1||n<=0)
	{
        cout <<"Incorrect input, please re-enter!" << endl;
		cin.clear();
		cin.sync();
		goto Start;
	}

 cout<<endl;
 cout<<"****************The parking space is set! Start the parking management system simulation below***************"<<endl ;
 cout<<endl;
 cout<<"*******************************Operating instructions********************************"<<endl;
 cout<<endl;
 cout<<"For vehicle entry registration: Please press 1  "<<endl;
 cout<<"For vehicle departure registration: please press 2"<<endl;
 cout<< "To check the parking status of the parking lot: please press 3"<<endl;
 cout<<"To check the parking space: please press 4"<<endl;
 cout<<"Exit the parking management system: please press 0"<<endl;
 cout<<endl;
 cout<<"***********************************************************************"<<endl;
 cout<<endl;
 while(1)
 {

	Query2(n);
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
    cout<<"******** Please select operation 1-4, if you want to quit please press 0 ********"<<endl;
	cout<<endl;
	cin.clear();
	cin.sync();
	int t; //choice entered
	cin>>t;
	 if(t==1)
		Push(n);
	 else if(t==2)
		Pop(n);
	 else if(t==3)
		Query1(n);
	 else if(t==4)
		Query2(n);
	 else if(t==0)
		break;
	 else
		  cout<<" Input is incorrect, please re-enter!"<<endl;
 cout<<endl;
 cout<<"********************End************************"<<endl;
 cout<<"********************************************"<<endl;
 cout<<endl;
 }
 cout<<endl;
 cout<<endl;
 cout<<"******** Thank you for using our parking lot management system, look forward to your next use ^_^ ********"<<endl;
 return 0;
}

