#include<iostream>
using namespace std;
//using one loop
int main()
{
	int arr[][3]={
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int sumPrimary=0, sumSecondary = 0;
	for(int i=0,j=2;i<3;i++,j--)
	{
		sumPrimary+=arr[i][i];
		sumSecondary+=arr[i][j];	
	}
	cout<<"Difference of sum of diagonal is: "<<sumPrimary-sumSecondary;
	return 0;
}

//Naive method
// int main()
// {
// 	int arr[][3]={
// 		{1,2,3},
// 		{4,5,6},
// 		{7,8,9}
// 	};
// 	int sumPrimary=0, sumSecondary = 0;
// 	for (int i=0;i<3;i++)
// 	{
// 		for(int j=0;j<3;j++)
// 		{
// 			if(i==j)
// 				sumPrimary+=arr[i][i];
// 			if(i+j==2)
// 				sumSecondary+=arr[i][j];
// 		}
// 	}
// 	cout<<"Difference of sum of diagonal is: "<<sumPrimary-sumSecondary;
// 	return 0;
// }