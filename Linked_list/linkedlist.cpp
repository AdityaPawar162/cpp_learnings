#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* link;
};
Node*A;
void Insert(int x){
	Node*temp = new Node();
	temp->data = x;
	temp->link = A;
	A = temp;
	
	
}
void Print(){
     Node*temp =A;
    cout <<"List is: " << endl;
    while(temp != NULL){
       cout << int(temp->data)<<"\t";
       temp = temp-> link;
    }
    cout <<"\n" << endl;
}

    int BinaryToDecimal(int n)
    {
    int val = 0 , base = 1;
    while(n > 0)
    {
        int lastDigit = n%10;
        val += (lastDigit*base);
        n /= 10;
        base *= 2;
    }
        return val;
    }

   int getDecimalValue(Node* head) {
        Node*temp = A;
        vector<int> arr(30);
        int ans = 0,result = 0;
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->link;
        }
        
        
        
       for(auto x : arr)
       {
       	ans = x + ans*10;
	   }
	   while(ans > 0)
	   {
	   	 result = result*10 + ans%10;
	   	 ans /= 10;
	   }
	   
	   
    
//        int pre_result = stoi(ans);
        int pre_result = BinaryToDecimal(result);
        return pre_result;

    }

int main(){
A = NULL;
int n,x;
cout <<	"How many numbers: "<< endl;
cin >> n;
for (int i = 1;i <= n;i++){
	cout << "Enter the number"<< endl;
	cin >> x;
	Insert(x);
//	Print();
}

cout << getDecimalValue(A);

	
}
