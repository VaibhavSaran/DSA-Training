/*Write a program to implement a doubly linked list such that apart from the head pointer, you need to maintain the tail pointer, 
also that points to the last node of the linked list. Perform following operations:
1. Add Node to the start
2. Add Node to the end
3. Delete node from the list
4. Counting of the node
5. Display elements of the list
6. Search element in the list
7. Sort the elements of the list.*/

# include <bits\stdc++.h>
using namespace std;
struct node
{
	int val;
	struct node *next;
	struct node *prev;
};
struct node* head=NULL;
struct node* tail=NULL;
void begPush(int val)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->val = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	if(head==NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	newNode = NULL;
	free(newNode);
}
void endPush(int val)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->val = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	if(tail==NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	newNode = NULL;
	free(newNode);
}
void delVal(int val)
{
	if(head==NULL)
		cout<<"No value to delete in Linked List";
	else
	{
		struct node* flag,*temp;
		if(head->val==val)
		{
			flag = head;
			head = head->next;
			free(flag);
		}
		else if(tail->val==val)
		{
			flag = tail;
			tail = tail->prev;
			free(flag);
		}
		else
		{
			flag = head;
			temp = head->next;
			int check=1;
			while(temp!=NULL)
			{
				if(temp->val == val)
				{
					flag->next = flag->next->next;
					temp->next->prev = temp->prev;
					free(temp);
					break;
				}
				else
				{
					flag = flag->next;
					temp = temp->next;
					check = 0;
				}
			}
			if(check == 0)
				cout<<"Value not found!!";
			else
				cout<<"Value deleted successfully!";
		}
		flag = NULL;
		temp = NULL;
		free(flag);
		free(temp);
	}
}
void countNode()
{
	struct node* temp;
	temp = head;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	cout<<"\nThe number of nodes in linked list is: "<<count<<endl;
	temp = NULL;
	free(temp);
}
void display()
{
	struct node* temp;
	temp = head->next;
	cout<<"EOL<=>"<<head->val<<"<=>";
	while(temp!=NULL)
	{
		cout<<temp->val<<"<=>";
		temp=temp->next;
	}
	cout<<"EOL\n";
	temp = NULL;
	free(temp);
}
void searchNode(int val)
{
	if(head==NULL)
		cout<<"No Linked List to search!";
	else
	{
		struct node* temp;
		temp = head;
		int flag = 0,count=1;
		while(temp!=NULL)
		{
			if(temp->val == val)
			{
				flag = 1;
				cout<<"\nThe value is at node: "<<count<<endl;
				display();
				break;
			}
			count++;
			temp = temp->next;
		}
		if(flag==0)
			cout<<"The value is not in linked list!";
	}
}
void sortNode()// bubble sort
{
	if(head==NULL)
		cout<<"No Linked List to sort!!";
	else if (head->next=NULL)
		cout<<"Linked List is already sorted! there is only one element DUH!!";
	else
	{
		struct node* flag,*temp,*small;
		flag = head;
		int jar;
		while(flag!=NULL)
		{
			temp = flag;
			small = temp;
			// finding values
			while(temp!=NULL)
			{
				if(temp->val<=small->val)
					small = temp;
				temp = temp->next;
			}
			// swapping values
			jar = small->val;
			small->val = flag->val;
			flag->val = jar;
			//incrementing flag
			flag = flag->next;
		}
		flag = NULL;
		temp = NULL;
		small = NULL;
		free(flag);
		free(temp);
		free(small);
	}
}
int main()
{
	int ch=0,ret,val;
	cout<<"\n1) Add Node to the start of Linked List\n";
	cout<<"\n2) Add Node to the end of Linked List\n";
	cout<<"\n3) Delete Node from Linked List\n";
	cout<<"\n4) Count Nodes in Linked List\n";
	cout<<"\n5) Display Linked List\n";
	cout<<"\n6) Search element in Linked List\n";
	cout<<"\n7) Bubble sort the Linked List\n";
	cout<<"\n8) Exit\n";
	cout<<"Enter your choice: ";
	cin>>ch;
	do
	{
		switch(ch)
		{
			case 1: cout<<"Enter the value to be added in start of linked list: ";
					cin>>val;
					begPush(val);
					ret = main();

			case 2: cout<<"Enter the value to be added in end of linked list: ";
					cin>>val;
					endPush(val);
					ret = main();

			case 3: cout<<"Enter the value to be deleted in linked list: ";
					cin>>val;
					delVal(val);
					ret = main();

			case 4: countNode();
					ret = main();
			
			case 5: display();
					ret = main();
			case 6: cout<<"Enter the value to be searched in linked list: ";
					cin>>val;
					searchNode(val);
					ret = main(); 
			
			case 7: sortNode();
					ret = main();
			
			case 8: exit(0);
			
			default: cout<<"Enter the correct choice\n\n\n\n\n";
					 ret = main();
		}

	}while(ch!=8);
	return 0;
}