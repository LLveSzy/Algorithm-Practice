#include<iostream>//21:50

using namespace std;

class Solution{
private:
	float n,sum,add,sub,res;
	void dfs(int index,int SUM,int n_1){
		if(index == n-1){
			//cout << int((sum - SUM)/n) << "--" << (sum - SUM)/n << endl;
			if(int((sum - SUM)/n) == (sum - SUM)/n) res ++;
			return;
		}
		dfs(index+1,SUM + n_1+ add,n_1+ add);
		dfs(index+1,SUM + n_1- sub,n_1- sub);
	}
public:
	int countN(){
		res = 0;
		cin >> n >> sum >> add >> sub;
		dfs(0,0,0);
		return res;
	}
}; 

int main(){
	Solution s;
	cout << s.countN();
	return 0;
}
