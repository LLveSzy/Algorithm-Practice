#include<iostream>
#include<vector> 
#include<string>
using namespace std;

class Solution{
private:
	vector<int> memo;
	int res = 0;
	int n;
	bool allused(vector<int> memo){
		for(int i = 0; i < 4; i++){
			if(memo[i]==0) return false;
		}
		return true;
	}
	void dfs(int index,vector<int> memo,string s){
		if(index > n) {
			if(allused(memo)){
				res=(res+1)%1000000007;
			//	cout << s << endl;
			}				
			return;	
		}
		
		if(!memo[1]&&index!=1) {
			string ss = s + "0";
			memo[0]++; 
			dfs(index+1,memo,ss);
			memo[0]--;				
		}
		if(!memo[3]) {
			memo[2]++;
			string ss = s + "2";	
			dfs(index+1,memo,ss);
			memo[2]--;		
		}		
		
		memo[1]++;
		string ss = s + "1";
		dfs(index+1,memo,ss);
		memo[1]--;
		
		memo[3]++;
		string sss = s + "3";
		dfs(index+1,memo,sss);
	}
public:
	int count(){
		cin >> n;
		memo = vector<int>(4,0);
		dfs(1,memo,"");
		return res;
	}
};

int main(){
	Solution s;
	cout << s.count();
	return 0;
}
