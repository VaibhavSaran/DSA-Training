/*Write a program to print duplicate characters from a string*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cout<<"Enter the input string: ";
	getline(cin,str);
	for (int i = 0; i < str.length(); i++)
  		str[i] = tolower(str[i]);
	unordered_map<char,int> duplicate;
	string::iterator i;
	for(i = str.begin();i!=str.end();i++)
	{
		if(*i != ' ')
		{
			if(duplicate.find(*i)==duplicate.end())
				duplicate.insert(pair<char,int>(*i,1));
			else
			{
				unordered_map<char, int>::iterator j = duplicate.find(*i);
				j->second++;
			}
		}
		else
			continue;
	}
	unordered_map<char, int>::iterator k;
	cout<<"Character"<<"\t"<<"Count"<<endl;
	for(k = duplicate.begin();k!=duplicate.end();k++)
	{
		if(k->second>=2)	
			cout<<'\t'<<k->first<<"\t"<<k->second<<endl;
	}
	return 0;
}