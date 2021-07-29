#include<iostream>
using namespace std;
int findOdd(int arr[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	res ^= arr[i]; //res = res^arr[i], res = 1, res = 0, res = 3,
	return res;
}

int main() 
{
	int arr[] = {1,1,3,2,2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<"The odd occurring element is "<<findOdd(arr, n);
	return 0;
}