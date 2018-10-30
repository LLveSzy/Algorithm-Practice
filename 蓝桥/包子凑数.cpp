#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
	
public:
	int countbz(int n,vector<int> &arr){
		vector<bool> memo(1000,false);
		
		for(int i = 0; i < arr.size(); i++){
			for(int j = arr[i];j < 1000; j++){
				if(j%arr[i] == 0) 
					memo[j] = true;
				else if(j-arr[i] > 0 && memo[j-arr[i]] == true) 
					memo[j] = true;	
			}
		}
		int res = 0;
		for(int i = 1; i < 1000; i++)
			if(memo[i] == false) res ++;
			
		return res;
	}
};

int main(){
	int n,c;
	Solution s;
	vector<int> arr;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> c;
		arr.push_back(c);
	}
	cout << s.countbz(n,arr);
	return 0;
} 
