/*Given two strings A and B, the task is to print all the non-repeating words out of the two given sentences.
input: A = “I have a blue pen”, B = “I got a red pen”
Output: have blue got red
Explanation:
The words have, blue, got and red have not been repeated in either the same sentence or another 
sentence.*/
#include<bits/stdc++.h>
using namespace std;
void nonRepeat(string &s1, string &s2)
{
	cout<<"\nThe non repeating words in the two sentences are: ";
	string::iterator i;
	string s3 = s1 + " " + s2 + " ";
	string word="";
	for(i = s3.begin();i!=s3.end();i++)
	{
		if(*i==' ') // use of single is necessary as we are comparing a character "" means a string
		{
			if(s1.find(word)==string::npos || s2.find(word)==string::npos)
				cout<<word<<" ";
			word="";
		}
		else
			word = word + *i;
	}
}
int main()
{
	string s1,s2;
	cout<<"Enter the string 1: ";
	getline(cin,s1);
	cout<<"Enter the string 2: ";
	getline(cin,s2);
	nonRepeat(s1,s2);
	return 0;
}