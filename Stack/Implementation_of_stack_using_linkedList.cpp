#include<bits/stdc++.h>
using namespace std;
//int top;
  	struct Node{
		int data;
		Node*next;
	};
		
	private:
		int head;
	Node*head;	
	public:
	
	void Push(int x)
	{
		Node*newNode = new Node;
		newNode->data = x;
		newNode->next = head;
		head = newNode;
	}
	void Pop(){
		Node*temp;
		if(head == NULL)return;
		temp = top;
		top = top->next;
		free(temp);
	}
	
	int top(){
		return (*head);
	}
	void isEmpty(){
		if(head != NULL)return 0;
		else {
			return 1;
		}
	}
	
	void Print(){
		Node*temp = head;
		cout << "The stack: ";
		while(temp->next != NULL){
			temp = temp->next;
			cout << temp->data;
		}
		cout << "/n";
		
	}
};
int main(){
	stack s;
	s.Push(2);s.Print();
	s.Push(4);s.Print();
	s.Push(6);s.Print();
	s.Pop();s.Print();
	cout << "is empty condition: ";
	s.isEmpty();
	cout << "value at top";
	s.top();
	
}
