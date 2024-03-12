#include<iostream>
using namespace std;
struct Node{
	int data;
	Node*next;
};
Node*head ;
void Push(int x){
	Node*newNode = new Node;
	newNode->data = x;
	newNode->next = head;
	head = newNode;
}
//void Pop(){
//	Node*temp ;
//	if(head == NULL)return;
//	else{
//	
//	temp = head;	
//	head = head->next;
//	free(temp);
//}
//}
bool isEmpty(){
	return head == NULL;
}
int top(){
	if(!isEmpty())return head->data;
}

void Print()
{
	Node*temp;
	cout << "The stack is:";
	while(temp->next!= NULL){
		temp = temp->next;
		cout << temp->data;
//	cout << "\n";
	}
}
int main(){
	Node* head = NULL;
	Push(2);Print();
    Push(4);Print();
	Push(6);Print();
	Push(5);Print();
	cout << "\n";
//	Pop();Print();
	cout << "The element at the top is";
	cout << top()<<"\n";
	cout << "Checking if stack is empty";
	cout << isEmpty()<<"\n";
}
