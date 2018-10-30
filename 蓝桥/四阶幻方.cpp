#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std; 

bool isValid(vector<int> res){
	int b = res[0] + res[5] + res[10] +res[15];
	if(b!=34) return false;
	if(b!=res[3] + res[6] + res[9] +res[12]) return false;
	for(int i = 0; i < 4; i++){
		int a = 0;
		for(int j = 0; j < 4; j++){
			a += res[i*4+j];
			
		}
		if(a != b) return false;
	}
	return true;
}

int main(){
	vector<int> res;
	int result = 0;
	for(int i = 1; i <= 16; i++){
		res.push_back(i);
	}
	do{
		if(isValid(res)) {
			for(int i = 0; i < 4; i++){			
				for(int j = 0; j < 4; j++){
					cout << res[i*4+j];			
				}
				cout << endl;
			}
			cout << endl;
			result++;	
		}
	}while(next_permutation(res.begin()+1,res.end()));
	cout << result;
	return 0;
}
