#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution{
private:
	int a , b , n , x;
	vector<int> memo;
	void dfs(int index,int res,int fetch){
		if(index > b - a) return;
		if(fetch >= n) {
			memo[res+abs(a)*n] ++;
	//		cout << res << endl;
			return ;	
		}		
		
		//2cout << res << endl;		
		dfs(index+1,res,fetch); //此数不取 
		dfs(index,res+a+index,fetch+1); //取一个此数 
	}
public:
	double ratio(){
		double all = 0;
		cin >> n >> a >> b >> x;
		memo = vector<int>(b*n+1 + abs(a)*n,0);
		dfs(0,0,0);
		for(int i = 0; i < b*n+1 + abs(a)*n; i++){
			all += memo[i];
		}
		printf("%0.4lf",memo[x+abs(a)*n]/all);
	}
};

int main(){
	Solution s;
	s.ratio(); 
	return 0;
}
