#include<iostream>

using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;
	int i = 2;
	while(1){
		if(a % i == 0)
			if(b % i == 0) break;
		if(i >= a){
			i = 1;
			break;
		}
		i++;		
	}
	cout << (a/i)*(b/i)*i;	
	return 0;
} 
