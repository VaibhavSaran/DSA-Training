/*Given arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms 
required for the railway station so that no train waits. We are given two arrays which represent arrival and departure times of 
trains that stop.
Input: 
	arr[] = {900, 940, 950, 1100, 1500, 1800} 
	dep[] = {910, 1200, 1120, 1130, 1900, 2000} 
Output: 3
Explanation: There are at-most three trains at a time (time between 1100 and 1120)
*/
#include <bits/stdc++.h>
using namespace std;
int findPlatform(int arr[], int dep[], int n)
{
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;
    for (int i = 0; i < n; i++) 
    {
        plat_needed = 1;
        for (int j = i + 1; j < n; j++) 
        {
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i]))
                plat_needed++;
        }
        result = max(result, plat_needed);
    }
    return result;
}
int main()
{
	int arr[50],dep[50],n;
	cout<<"Enter the number of time stamps: ";
	cin>>n;
	cout<<"Enter the arrival times: ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the departure times: ";
	for(int i=0;i<n;i++)
		cin>>dep[i];
	cout<<"The minimum number of platforms required are: "<<findPlatform(arr,dep,n);
	return 0;
}