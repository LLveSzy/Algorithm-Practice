#include<iostream>
using namespace std;

int main(){
	for(int i = 1; i < 100;i ++)
		for(int j = 1; j < 100; j++)
			for(int k = 1; k < 100; k++)
				if(i*i+j*j+k*k == 1000) cout << i<<" " <<j << " "<< k<<endl;  
	return 0;
}
