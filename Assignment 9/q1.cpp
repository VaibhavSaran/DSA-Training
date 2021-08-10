/*Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. Both the arrays are not in sorted 
order. It may be assumed that elements in both array are distinct. (Use Hash Table for the same)
Examples:
Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1} 
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {1, 2, 4} 
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {10, 5, 2, 23, 19}, arr2[] = {19, 5, 3} 
Output: arr2[] is not a subset of arr1[]*/
#include <bits/stdc++.h>
using namespace std;
bool isSubset(int arr1[], int m,int arr2[], int n)
{
 
    // Using STL set for hashing
    set<int> hashset;
    // hset stores all the values of arr1
    for (int i = 0; i < m; i++)
        hashset.insert(arr1[i]);
 
    // loop to check if all elements of arr2 also lies in arr1
    for (int i = 0; i < n; i++) 
        if (hashset.find(arr2[i]) == hashset.end())
            return false;
    return true;
}
int main()
{
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    if (isSubset(arr1, m, arr2, n))
        cout << "arr2[] is subset of arr1[] "<< "\n";
    else
        cout << "arr2[] is not a subset of arr1[] "<< "\n";
    return 0;
}