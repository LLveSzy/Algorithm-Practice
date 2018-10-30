#include<iostream>
using namespace std;

int* transfer(int i);
int* mult(int *a);
bool judge(int *a,int *b);

int main()
{
	for(int i = 100000; i < 999999; i++){
		int *a = transfer(i); //分解 
		int *b = mult(a); //做乘法 
		if(judge(a,b)) {
			cout << i << endl;	
		}
	}
	return 0;
 } 
 
 int* transfer(int i)
 {
 	int *a = new int[7],j = 0;
 	a[6] = 0;
 	while(i!=0){
 		a[j] = i%10;
 		i /= 10;
		j++;
	}
 	return a;
 }
int* mult(int *a)
{
	int b[12] = {0},cf = 0;
	for(int i = 0; i < 12; i++) b[i] = 0;
	int d[6][12] = {0};
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			d[i][i+j] = cf + a[i]*a[j];
			cf = d[i][i+j] / 10;
			d[i][i+j] %= 10;			
		}
	}
//	for(int i = 0; i < 6; i++){
//		for(int j = 0; j < 12; j++) cout << d[i][j] << " ";
//		cout << endl;
//	}
		
	cf = 0;
	for(int j = 0; j < 12; j++){		
		for(int i = 0; i < 6; i++)
			b[j] += d[i][j];
		b[j] += cf;			
		cf = b[j] / 10;
		b[j] %= 10;
	}	

	return b;
}
bool judge(int *a,int *b)
{
	int length = 11;
	int jud[10] = {0};
	while(b[length]==0) length--;
	for(int i = 0; i < 6; i++){
		if(jud[a[i]] == 0)
			jud[a[i]]++;
		else return false;
	}
		
	for(int i = 0; i <= length; i++){
		if(jud[b[i]] != 0) return false;
	}
	return true;
}




