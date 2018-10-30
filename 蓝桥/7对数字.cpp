#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
	vector<bool> memo;
	bool fillin(vector<int> & order,int index){
		if(index > 13) return true;
		for(int i = 0; i < 14; i++){
		cout << order[i];
	}
	cout << endl;
		if(order[index] != 0) fillin(order,index+1);
		if(order[index] == 0){
			for(int i = 1; i <= 6; i ++){
				if(memo[i] && index+i+1 <= 13&& order[index+i+1] == 0 ){
					order[index] = i;
					order[index+i+1] = i;
					memo[i] = false;
					if(!fillin(order,index+1)){
						order[index] = 0;
						order[index+i+1] = 0;
						memo[i] = true;						
					}
					else return true;
				}				
			}
		}
		return false;
	}
public:
	void count(vector<int> & order){
		memo = vector<bool>(8,true);
		fillin(order,1);
	}
};

int main(){
	vector<int> order(14,0);
	order[0] = 7;

	order[8] = 7;

	Solution s;
	s.count(order);
	for(int i = 0; i < 14; i++){
		cout << order[i];
	}
	return 0;
}
