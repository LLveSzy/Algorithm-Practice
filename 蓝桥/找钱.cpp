#include<iostream>

using namespace std;

int res = 0;

int f(int m, int n,int own){	
	if(m < 0) return 0;
	if(n < 0) return 0;
	if(own < 0) return 0;
	if(n == 0) return 1;
	
	res = f(m,n-1,own-1) + f(m-1,n,own+1);
	
}

int main(){
	int m , n; 
	cin >> m >> n; //0.5 1

	f(m,n,0);
	cout << res;
	return 0;
} 
