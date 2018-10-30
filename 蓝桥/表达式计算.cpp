#include<iostream> 
#include<string>
using namespace std;

class Stack{
public:
	Stack(){
		top = 0;
	}
	void push(int n){
		a[top] = n;
		top++;
	}
	int pop(){
		if(top != 0){
			top--;
			return a[top];	
		}
		else return 0;		
	}
	bool isEmpty(){
		if(top == 0) return true;
		else return false;
	}
	int getTop(){
		return a[top-1];
	} 
	int top;
	int a[20];
};

int returnBig(char ch);

int main()
{
	string str;
	Stack st ,ob;
	int number,r = 0;
	cin >> str;
	int num[str.length()];
	for(int i = 0; i < str.length(); i++){
		number = 0;
		if(isdigit(str[i])){
			while(isdigit(str[i])){
				number = number*10 + str[i] - 48; 
				i++;
			}
			ob.push(number);
			i--;
		}			
		else{
			if(str[i] == '(') st.push(-1);
			else if(str[i] == ')'){
				while(st.getTop()!= -1)  ob.push(st.pop());
				st.pop();
			}
			else if(returnBig(str[i]) >= -6 && returnBig(str[i])<= -2){
				if(st.isEmpty()||(returnBig(str[i]) - st.getTop())< 2){
					st.push(returnBig(str[i]));
				}
				else
					while(!st.isEmpty()&&(returnBig(str[i]) - st.getTop())>= 2) {
						ob.push(st.pop());
						st.push(returnBig(str[i]));	
						break;
					}
			}					
		}
	} 
	int s = st.top;
	for(int i = 0; i < s; i++) ob.push(st.pop());
	s = ob.top;
	for(int i = 0; i < s; i++) cout << ob.a[i] << " ";	
}

int returnBig(char ch){
	switch(ch){
		case '(': 
			return -1;
		case '+':
			return -2;
		case '-':
			return -3;
		case '*':
			return -5;
		case '/':
			return -6;
	}	
}



