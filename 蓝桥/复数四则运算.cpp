#include<iostream>

using namespace std;

int main(){
	float a1,i1,a2,i2;
	char ch;
	cin >> a1 >> i1 >> ch >> a2 >> i2;
	
	switch(ch){
	case'+':
		if(a1+a2 == 0 && i1+i2==0) cout << 0;
		cout << a1+a2;
		if(i1+i2>0) cout << "+";
		if(i1+i2==0) break;
		cout << i1+i2 <<"i";
		break;
	case'-':
		if(a1-a2 == 0 && i1-i2==0) cout << 0;
		cout << a1-a2;
		if(i1-i2>0) cout << "+";
		if(i1-i2==0) break;
		cout << i1-i2 <<"i";
		break;
	case'*':
		if(a1*a2 -i1*i2 == 0 && a1*i2 + a2*i1 ==0) {cout << 0;exit(0);} 
		if(a1*a2 -i1*i2 !=0)
			cout << a1*a2 -i1*i2;
		if(a1*i2 + a2*i1 !=0)
			cout << a1*i2 + a2*i1 << "i";
		break;
	case'/':
		if(a2*a2-i2*i2 + 2*a2*i2!= 0){
			if(a1*a2 - i1*i2 == 0 && a1*i2 + a2*i1 == 0) {cout << 0;exit(0);} 
			if(a1*a2 - i1*i2 !=0)
				cout << (a1*a2 -i1*i2)/(a2*a2-i2*i2 + 2*a2*i2) ;
			if(a1*i2 + a2*i1 !=0){
				if((a1*i2 + a2*i1)/(a2*a2-i2*i2 + 2*a2*i2)> 0 ) cout << "+";
				cout << (a1*i2 + a2*i1)/(a2*a2-i2*i2 + 2*a2*i2) << "i";
			}							
		}
		else cout << "error" ;		
		break;
	} 
	return 0;
} 
