#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
struct Node{
	int data;
	Node*next;
};
void Push(Node**head,int x){
	Node*newNode = new Node;
	newNode->data = x;
	newNode->next = (*head);
	(*head) = newNode;
}
void Reverse(Node*head){
	stack<Node*> S;
	Node*temp = head;
	while(temp != NULL){
		S.push(temp);
		temp = temp->next;
		
	}
	while(!S.empty()){
		cout << S.top()->data<<" ";
//		temp->next = S.top();
		S.pop();
//		temp = temp->next;
	}
//	temp->next = NULL;
	
}
int main(){
	Node*head = NULL;
	
	Push(&head,2);
	Push(&head,4);
	Push(&head,6);
	Push(&head,8);
	Reverse(head);
	return 0;
	}
