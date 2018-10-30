#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;

int test(int *d);
bool over(int *d); 
int main(){
	int a[9];
	int j = 0;
	for(int i = 8; i >= 0; i--){
		a[j] = i;
		j++;
	}
	int min = 999,ct,*d;
//	for(int i = 0; i < 1; i++){
//		d = new int[9];
//		d = a;
//		ct = test(d);
//		if(ct < min) min = ct;
//	}
//	cout << ct;
cout << test(a);
	return 0;
}

int test(int *d)
{
	int k = 8,i = 0;
	while(!over(d)){
		srand(clock());
		int c = rand()%3,l,t;
		cout << c << endl;
		switch(c){
			case 0:
				l = 1;
				break;
			case 1:
				l = -1;
				break;
			case 2:
				l = 2;
				break;
			case 3:
				l = -2; 
				break;
		}
		swap(d[k],d[(k+l+9)%9]);
//		t = d[k]; 
//		d[k] = d[(k+l)%9];
//		d[(k+l)%9]= t;
		k = (k+l+9)%9;
		for(int i = 0; i < 9; i++) cout << d[i]<<" ";
		cout << endl;
		i++;
	}
	return i;
 } 
 
 bool over(int *d){
 	for(int i = 0; i < 8; i++){
 		cout << d[i] << "---" <<i << endl;
 		if(d[i]!= i) return false;
	 }
	 return true;
 }
