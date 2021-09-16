/*Given a value V, if we want to make a change for V Rupees, and we have an infinite supply of each of the denominations in Indian 
currency, i.e., we have an infinite supply of {1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, 
what is the minimum number of coins and/or notes needed to make the change.
Input: V = 70
Output: 2
Explanation: We need a 50 Rs note and a 20 Rs note.

Input: V = 121
Output: 3
Explanation: We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.*/
#include <bits/stdc++.h>
using namespace std;
void findMin(int V)
{
	int deno[] = { 1, 2, 5, 10, 20,50, 100, 500, 1000 };
	int n = sizeof(deno) / sizeof(deno[0]);
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) 
    {
        while (V >= deno[i]) 
        {
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
int main()
{
	int n;
	cout<<"Enter the amount for which you need a change: ";
	cin>>n;
	cout<<"The change will of following denominations: ";
	findMin(n);
	return 0;
}