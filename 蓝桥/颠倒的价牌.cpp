#include<iostream>
#include<math.h>
using namespace std;

int transfer(int a);
int switched(int n,int ct[], int i);

int main(){
	for(int i = 1000; i < 9999; i++){
		int a = transfer(i);
		if(a){
			if(i - a == 282)
			cout << i << endl;
		}		
	} 
	return 0;
}

int transfer(int a)
{
	int n[4] = {0},ct[4] = {0},i = 0;
	while(a!=0){
		n[i] = a%10;
		a /= 10;
	//	cout << n[i] << endl;
		if(!switched(n[i],ct,i)) return 0;
		i++;		
	}
	return ct[0]*1000 + ct[1]*100 + ct[2]*10 + ct[3]; 
}

int switched(int n,int ct[], int i){
	switch(n){
		case 0:
		case 1:
		case 2:
		case 5:
		case 8:
			ct[i] = n;
			return 1;
			break;
		case 6:
			ct[i] = 9;
			return 1;
			break;
		case 9:
			ct[i] = 6;
			return 1;
			break;
		default:
			return 0;
	}
}






