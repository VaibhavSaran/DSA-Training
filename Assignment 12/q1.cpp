/*Given an undirected graph with N vertices and M edges, the task is to find the absolute difference between sum of degrees of 
odd degree nodes and even degree nodes in an undirected Graph.
Input: 
		N = 4
	    edges[][] = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 2 }, { 1, 3 }, { 2, 3 } }
Output: 12
*/
#include <bits/stdc++.h>
using namespace std;
int OddEvenDegree(int N, int M,int edges[][2])
{
    vector<int> Adj[N + 1];    
    int EvenSum = 0;
    int OddSum = 0;
    for(int i = 0 ; i < M ; i++) 
    {
        int x = edges[i][0];
        int y = edges[i][1];
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }
    for (int i = 1; i <= N; i++) 
    {
 	    int x = Adj[i].size();
        if (x % 2 != 0)
            OddSum += x;
        else
            EvenSum += x;             
    }
    return abs(OddSum - EvenSum);
}
int main()
{
	int N=4,M=6;
	int edges[M][2]={{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
	cout<<"The difference is: "<<OddEvenDegree(N,M,edges);
	return 0;
}