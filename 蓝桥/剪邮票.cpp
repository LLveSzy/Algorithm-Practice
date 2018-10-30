#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

class Solution{
private:
	int res = 0;
	bool memo[9999];
	void dfs(int x,int y,int cnt,vector<vector<bool> > mem){
		if(x<=0||x>4||y>3||y<=0) return;
		//if(mem[y][x] == true) return;
		mem[y][x] = true;
		if(cnt == 5) {
			int sum = 0,ct = 0;
			for(int i = 0; i < 4; i++)
				for(int j = 0; j < 5; j++)
					if(mem[i][j]) {
						ct++;
						sum += pow(2,(i-1)*4+j);
						cout << i << "," << j << " ";
					}
					cout << sum << " " << res << " " <<memo[sum];
			cout << endl; 
			if(memo[sum] == false && ct == 5) res++;
			memo[sum] = true;			
			return;
		}
		
		dfs(x+1,y,cnt+1,mem);
		dfs(x-1,y,cnt+1,mem);		
		dfs(x,y+1,cnt+1,mem);
		dfs(x,y-1,cnt+1,mem);		
	}
public:
	int countNum(){
		memset(memo,0,sizeof(memo));
		for(int i = 1; i <= 3; i++){
			for(int j = 1; j <= 4; j++){
				vector<vector<bool> > mem(4,vector<bool>(5,false));
				dfs(j,i,1,mem);
			}			
		}
		return res;
	}
};

int main(){
	Solution s;
	cout << s.countNum();
	return 0;
} 
