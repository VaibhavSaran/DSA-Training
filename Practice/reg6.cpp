#include<iostream>
using namespace std;
int main()
{
// a = 14(00001110), b = 9(00001001)
unsigned char a = 14, b = 9;
printf("a = %d, b = %d\n", a, b);
printf("a&b = %d\n", a & b);
printf("a|b = %d\n", a | b);
printf("a^b = %d\n", a ^ b);
printf("~a = %d\n", a = ~a);
printf("b<<1 = %d\n", b << 1);
printf("b>>1 = %d\n", b >> 1);
return 0;
}