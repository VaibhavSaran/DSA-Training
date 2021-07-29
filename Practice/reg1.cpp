#include<iostream>
using namespace std;
int main()
{
	int call,msg;
	float callCharge=0.0,msgCharge=0.0;
	cout<<"Enter the number of calls: ";
	cin>>call;
	cout<<"Enter the number of messages: ";
	cin>>msg;

	if(call > 300)
		callCharge = 227.5 + (call - 300)*.95;
	else if(call > 150)
		callCharge = 100 + (call - 150)*.85;
	else if(call > 50)
		callCharge = 25 + (call - 50)*.75;
	else
		callCharge = call*0.50;

	if(msg > 350)
		msgCharge = 80 + (msg - 350)*.60;
	else if(msg > 200)
		msgCharge = 20 + (msg - 200)*.40;
	else if(msg > 100)
		msgCharge = (msg-100)*0.20;
	else
		msgCharge = 0;

	cout<<"The call charges are: "<<callCharge;
	cout<<"\nThe message charges are: "<<msgCharge;
	cout<<"\nTotal Bill: "<<callCharge+msgCharge;
	return 0;
}