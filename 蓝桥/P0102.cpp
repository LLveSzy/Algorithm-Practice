#include<iostream>//19:52
#include<math.h>
using namespace std;

int main(){
	int res = 0,count = 2;
	
	for(int i = 0; i < 3; i++){
		char c;
		int a;
		cin >> c;
		if(c<='9' && c>='0'){
			a = c-'0';
		}
		else a = c - 'A' + 10;
		
		res += a * pow(16,count);
		count --;

	}
	cout << res << endl;
	int res1 = 0;

	while(res !=0){
		cout << res%8;
		res/=8;
	}
	cout << res1;
	return 0;
} 
