#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
	int n,size;
	vector<vector<int> > goods;
	vector<int> memo;
public:
	int pack(){
		cin >> n >> size;
		goods = vector<vector<int> >(n,vector<int>(2,0));
		for(int i = 0; i < n; i++){
			cin >> goods[i][0] >> goods[i][1];
		}
		memo = vector<int>(size+1,0);
		
		for(int j = 0; j < n; j++){
			for(int i = size+1; i >= 0; i--){
				if(i - goods[j][0] >= 0 ){
					memo[i] = max(memo[i],goods[j][1] + memo[i - goods[j][0]]);
				}
			}
		}
		return memo[size];
	}
	
};

int main()
{
	Solution s;
	cout << s.pack();
	return 0;
}
