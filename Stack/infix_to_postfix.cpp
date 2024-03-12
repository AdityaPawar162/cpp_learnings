#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int Perform(int*exp[i],int*Op1,int*Op2){
	if((*exp[i]) == '+')return 
}
int EvaluatePostfix(string exp){
	stack<int> S;
	for (int i = 0;i < strlen(exp)-1;i++){
		if(exp[i] != '/'|| exp[i] != '*'||exp[i] != '-'||exp[i] != '+'){
		
		S.push(exp[i]);
	}
	    else {
	    	int Op1,Op2;
	    	Op2 = S.pop();
	    	Op1 = S.pop();
	    	res = Perform(&exp[i],&Op2,&Op1);
	    	S.push(res);
		}
	}
	return S.top()
}
int main(){
	return 0;
}
