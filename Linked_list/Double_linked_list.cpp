#include<bits/stdc++.h>
using namespace std;
//Creation 
struct Node
{
 int data;
 Node*next ;
 Node*prev ;
};
Node *head;
Node*GetNewNode(int x)
{
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void InsertAtHead(int data)
{
	Node*newNode = GetNewNode(data);
	if(head == NULL)
	{
		head = newNode;
		return ;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
	
}

void InsertAtTail(int data)
{
	Node*temp = head;
	Node*newNode = GetNewNode(data);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void deleteNode(int pos)
{
	Node*curr,*nxt;
	Node*temp = head;
	if(pos == 1)
	{
		head = temp->next;
		free(temp);
		return ;
	}
	for(int i = 0;i < pos-2;i++)
	{
		temp = temp->next;
	}
	curr = temp->next;
	temp->next = curr->next;
//	 = temp
}

void print()
{
	Node*temp = head;
	while(temp != NULL)
	{	 
		cout << temp->data << " ";
	  temp = temp->next;
	}
	cout << endl;
}

int main()
{
	head = NULL;
	InsertAtHead(2);
	InsertAtHead(4);
	InsertAtHead(6);
	print();
	InsertAtTail(8);
	print();
	
	return 0;
}

