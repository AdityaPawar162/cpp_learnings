#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
	int data;
	Node*next;
};
Node*front = NULL;
Node*rear = NULL;
void Enqueue(int x){
	Node*newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = newNode;
		return;
	}
	rear->next = newNode;
	rear = newNode;
	
}
void Dequeue(){
	Node*temp = front;
	if(front == rear ){
		front = rear = NULL;
    }
    if(front == NULL){
    	cout << "Queue is empty\n";
    	return;
	}
	else{
		front = front->next;
	}
	free(temp);

}
int Front(){
	if(front == NULL){
		cout << "Queue is empty\n";
		return 0;
		
	}
	return front->data;
}
void Print(){
	Node*temp = front;
	while(temp != NULL){
		cout << temp->data;
		temp = temp->next;
	}
	cout << "\n";
}
int main(){
		Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	
	Enqueue(8); Print();
}
