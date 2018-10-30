#include<iostream>
#include<math.h> 

using namespace std; 

int main(){
	double res = 2;
	for(int i = 5000000; i < 6000000; i++){
		double x = 2+(double)i/10000000;
		//cout << x*log10(x) - 1 << endl;
		if(x*log10(x) - 1 <  10e-8 && x*log10(x) - 1 > -10e-8) printf("%.7lf\n",x);
	}
	return 0;
} 
