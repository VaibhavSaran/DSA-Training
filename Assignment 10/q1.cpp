/*Given an integer K and an array of integers arr, the task is to find the maximum element from the array and after every retrieval 
the number will get decremented by 1. Repeat these steps exactly K number of times and print the sum of all the values retrieved in 
the end.
Input: K = 3, arr[] = {2, 3, 5, 4}
Output: 13

For K = 1, current maximum is 5 (Sum = 5 and arr[] = {2, 3, 4, 4})
For K = 2, current maximum is 4 (Sum = 5 + 4 = 9 and arr[] = {2, 3, 3, 4})
For K = 3, current maximum is 4 (Sum = 9 + 4 = 13 and arr[] = {2, 3, 3, 3})

Hence, the result is 13
*/
// Average complexity is O(k*n) and worst case is O(n^2)
#include<iostream>
using namespace std;
int main()
{
	int k,n,arr[50],small,large,pos,temp,sum=0;
	cin>>k;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		large=arr[i];
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]>=large)
			{
				large = arr[j];
				pos = j;
			}
		}
		if(k==0)
			break;
		else
		{
			sum+=large;
			arr[pos]=arr[pos]-1;
			k--;
		}
	}
	cout<<"The sum is: "<<sum;
	return 0;
}