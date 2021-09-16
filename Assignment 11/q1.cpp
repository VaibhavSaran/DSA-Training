/*Write a Program to evaluate postfix expression. (using string and stack of STL, Refer to polish notation for details)
Sample input: 234+*5-
sample output: 9.000000
*/
#include <bits/stdc++.h>
using namespace std;
class Stack
{
    public:
    int top;
    unsigned capacity;
    int* array;
};
Stack* createStack( unsigned capacity )
{
    Stack* stack = new Stack();
    if (!stack) 
    	return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = new int[(stack->capacity * sizeof(int))];
    if (!stack->array) 
    	return NULL;
    return stack;
}
int isEmpty(Stack* stack)
{
    return stack->top == -1 ;
}
int peek(Stack* stack)
{
    return stack->array[stack->top];
}
int pop(Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}
void push(Stack* stack,int op)
{
    stack->array[++stack->top] = op;
}
int evaluatePostfix(char* exp)
{
    Stack* stack = createStack(strlen(exp));
    int i;
    if (!stack) 
    	return -1;
    for (i = 0; exp[i]; ++i)
    {
        if(exp[i] == ' ')
        	continue;
        else if (isdigit(exp[i]))
        {
            int num=0;
            while(isdigit(exp[i]))
            {
            	num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;
            push(stack,num);
        }
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);     
            switch (exp[i])
            {
	            case '+': push(stack, val2 + val1); 
                          break;
	            case '-': push(stack, val2 - val1); 
                          break;
	            case '*': push(stack, val2 * val1); 
                          break;
	            case '/': push(stack, val2 / val1);
                          break;
            }
        }
    }
    return pop(stack);
}
int main()
{
	char exp[50];
	cout<<"Enter the postfix expression: ";
	cin.getline(exp,50);// input must be given as space separated for correct result
	cout<<"The evaluated expression is: "<<evaluatePostfix(exp);
	return 0;
}