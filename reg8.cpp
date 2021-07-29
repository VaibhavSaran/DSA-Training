#include <iostream>
using namespace std;
int main() 
{
	int x = 0, y = 10;
	x = x ^ y; 
	y = x ^ y; 
	x = x ^ y; 
	cout << "After Swapping: x =" << x << ", y=" << y<<endl;
	return 0;
}