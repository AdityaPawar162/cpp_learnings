#include <iostream>
using namespace std;
struct Node{
	int data;
	Node*next;
};
//Node*head;
void Insert(Node*head,int data)
{
   Node*temp = new Node;
   temp->data = data;
   temp ->next = NULL;
   if(head != NULL)temp->next = head ;
   temp = head ;
   
}
Node* ReversePrint(Node*p){
	Node*head;
	if(p->next == NULL){
		head = p;
		return head;
	}
	head = ReversePrint(p->next);
	cout << p->data;
	p->next->next = p;
	p->next = NULL;
	return head;
}
int main(){
	  Node* head = NULL;
    Insert(head, 1);
    Insert(head, 2);
    Insert(head, 3);
    Insert(head, 4);
    cout << "Original List: ";
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    cout << "Reversed List: ";
    head = ReversePrint(head);
    cout << endl;
    return 0;
	
}
