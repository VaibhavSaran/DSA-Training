/*Given an array a, your task is to convert it into a non-increasing form such that we can either increment or decrement the array value 
by 1 in minimum changes possible.
Input : a[] = {3, 1, 5, 1}
Output : 4
We need to decrease 5 to 1 to make array sorted in non-increasing order.

Input : a[] = {1, 5, 5, 5}
Output : 4
We need to increase 1 to 5.
*/
/*
Approach:  Calculate the sum of absolute differences between the final array elements and the current array elements. Thus, the answer 
will be the sum of the difference between the ith element and the smallest element occurred until then. For this, we can maintain a 
min-heap to find the smallest element encountered till then. In the min-priority queue, we will put the elements and new elements are 
compared with the previous minimum. If new minimum is found we will update it, this is done because each of the next element which is 
coming should be smaller than the current minimum element found till now. 
Here, we calculate the difference so that we can get how much we have to change the current number so that it will be equal or less than 
previous numbers encountered till. 
Lastly, the sum of all these differences will be our answer as this will give the final value up to which we have to change the elements.
*/
#include<bits/stdc++.h>
using namespace std;
void decArray(int a[],int n)
{
	int sum=0,diff=0;
	priority_queue<int, vector<int>, greater<int> > vals;
	for(int i=0;i<n;i++)
	{
		if(!vals.empty() && vals.top()<a[i])
		{
			diff = a[i] - vals.top();
			sum+=diff;
			vals.pop();
		}
		vals.push(a[i]);
	}
	cout<<sum;
}
int main()
{
	int n,a[50];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	decArray(a,n);
	return 0;
}