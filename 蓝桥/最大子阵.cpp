#include<iostream>
#include<vector>
using namespace std; 

class Solution {
private:
	int m,n;
	vector<vector<int> > memo;
	int maxrect(){
		int mr = INT_MIN;
		for(int i = 1; i <= m ; i++)
			for(int j = 1; j <= n; j++){
				for(int x = 0; x < i; x++)
					for(int y = 0; y < j; y++){
						mr = max(memo[i][j] - memo[i][y] - memo[x][j] + memo[x][y],mr);
					}								
			}
		return mr;
	}
public:
	int maxRec(){
		cin >> m >> n;
		memo = vector<vector<int> >(m+1,vector<int>(n+1,0));
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= n; j++){
				int c;
				cin >> c;
				memo[i][j] = memo[i-1][j] + memo[i][j-1] - memo[i-1][j-1] + c;
			}		
		return maxrect();
	}
}; 

int main(){
	Solution s;
	cout << s.maxRec(); 
}
