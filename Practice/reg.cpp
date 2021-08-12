/*Write a program using template to swap two numbers*/
#include <iostream>
using namespace std;
template <class T>
void swapNum(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a,b;
	cout<<"Enter two numbers: ";
	cin>>a>>b;
	cout<<endl<<a<<b;
	swapNum(a,b);
	cout<<"\nAfter swap: "<<a<<b;
	return 0;
}