#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
	int n;
	vector<int> stone;
	vector<int> memo;
	vector<int> count;
public:
	int combineStones(){
		cin >> n;
		
		stone = vector<int> (n+1,0);
		count = vector<int> (n+1,0);
		memo = vector<int> (n+1,0);
		
		for(int i = 1; i <= n ; i++){
			cin >> stone[i];
			count[i] = stone[i];
			count[i]+=count[i-1];
		}
		if(n <= 2) return count[n];
		
		memo[1] = stone[1];
		memo[2] = stone[1] + stone[2];
		for(int i = 3; i <= n ; i++){
			memo[i] = min(memo[i-1] + count[i-1] + stone[i],(stone[i] + stone[i-1])*2 + memo[i-2]+count[i-2] );
		}
		return memo[n];
	}
};

int main()
{
	Solution s;
	cout << s.combineStones(); 
	return 0;
 } 
