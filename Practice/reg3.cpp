#include<iostream>
using namespace std;

int getClosest(int val1, int val2,int target)
{
	if (target - val1 >= val2 - target)
		return val2;       
	else
    	return val1;       
}
int findClosest(int arr[], int n, int target)
{
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];
    int i = 0, j = n, mid = 0;
    while (i < j) 
    {
        mid = (i + j) / 2;
        if (arr[mid] == target)
            return arr[mid];
        if (target < arr[mid]) 
        {
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(arr[mid - 1],arr[mid], target);
            j = mid;
        }
        else 
        {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(arr[mid],arr[mid + 1], target);
            i = mid + 1;
        }
    }
    return arr[mid];
}
int main()
{
	int n,a[50],sum=0,min=0,temp;
	float avg;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter the elements of array: ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	avg=sum/n;
	cout<<"The number closest to the average "<<avg<<" is: "<<findClosest(a,n,avg);
	return 0;
}