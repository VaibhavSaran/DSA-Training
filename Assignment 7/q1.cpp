/*Check if the sum of a subarray within a given range is a perfect square or not.Given an array arr[] of size N and an array range[]
the task is to check if the sum of the subarray {range[0], .. , range[1]} is a perfect square or not. If the sum is a perfect square
then print the square root of the sum Otherwise, print -1.

Input: arr[] = {2, 19, 33, 48, 90, 100}, range = [1, 3]
Output: 10
Explanation: The sum of element from position 1 to position 3 is 19 + 33 + 48 = 100, which is a perfect square of 10.

Input: arr[] = {13, 15, 30, 55, 87}, range = [0, 1]
Output: -1*/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int a[50];int range[2],n,sum=0;
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter the array:\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the range to be checked for perfect square\n";
	cout<<"Lower Bound: ";
	cin>>range[0];
	cout<<"Upper bound: ";
	cin>>range[1];
	for(int i = range[0];i<=range[1];i++)
		sum+=a[i];
	long long root = sqrt(sum);
	if(root*root == sum)
		cout<<root;
	else
		cout<<"-1";
	return 0;
}