#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
private:
	vector<bool> memo;
	vector<int> grid;
	int n;
	int kinds;
	void dfs(){	
		if (n == 9) {
				if(judgePass()) kinds++;
				return;	
		}		
		for(int i = 2; i < 10; i++){		
			if(memo[i] == true) continue;
			memo[i] = true;						
			n++;
			grid[n] = i;				
			dfs();			
			memo[i] = false;
			grid[n] = 0;
			
			n--;
			
		}
		return ;
	}
	bool judgePass(){
		for(int i = 1; i < 5; i++){
			if(grid[i] < grid[i+1] && grid[i] < grid[i+5]&& grid[i+5] < grid[i+6] && grid[5] < grid[10])
				continue;
			else return false;
		}
		return true;
	}
	
	bool judgePass2(vector<int> v){
		for(int i = 0; i < 4; i++){
			if(v[i] < v[i+1] && v[i] < v[i+5] &&v[i+5] < v[i+6] && v[5] < v[10])
				continue;
			else return false;
		}
		return true;
	}
public:
	int countSitu(){
		memo = vector<bool>(10,false); 
		grid = vector<int>(10,0);
		grid[1] = 1;
		grid[10] = 10;
		kinds = 0;
		n = 1;
		dfs();
		return kinds;
	}
	int permutation(){
		vector<int> v;
		int res = 0;
		for(int i = 1; i < 11; i ++){
			v.push_back(i);
		}
		do{
			if(judgePass2(v)) {
				for(int i = 0; i < 10; i ++){
					cout << v[i];
					if(i == 4) cout << endl; 
				}
				cout <<endl << endl;	
				res ++;
			}
		}while(next_permutation(v.begin(),v.end()));
		return res;
	}
	
};

int main(){
	Solution s;
	cout << s.countSitu();
	return 0;
} 
