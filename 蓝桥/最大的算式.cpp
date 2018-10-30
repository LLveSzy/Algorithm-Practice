#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

class Solution{
private:
	int n,k;
	vector<int> num;

	int dfs(int index,int ka,int ad,int adnum,int res){
		
		if(index > n-1 && ka ==0 && ad == 0) return res*adnum;
		if(ka < 0 || ad < 0) return INT_MIN;
		
		//³ËºÅ 
		int res1 = dfs(index+1,ka-1,ad,num[index],res*adnum);
		//¼ÓºÅ 
		int res2 = dfs(index+1,ka,ad-1,adnum+num[index],res);
		return max(res1,res2);		
	}
	int maxComb(int a[]){
		int ad = num[0],res = 1;
		for(int i = 0; i < n-1; i++){
			if(a[i] == 0){//¼Ó 
				ad += num[i+1]; 
			}
			else if(a[i] == 1){
				res *= ad;
				ad = num[i+1];
			}
		}
		return res * ad;
	}
public:
	int maxRes(){
		cin >> n >> k;
		num = vector<int>(n, 0);
		for(int i = 0; i < n; i++){
			cin >> num[i];
		}
		
		int ka = k;
		return dfs(1,ka,n-ka-1,num[0],1);
		
	}
	int maxRes2(){
		cin >> n >> k;
		int mx = INT_MIN;
		num = vector<int>(n, 0);
		for(int i = 0; i < n; i++){
			cin >> num[i];
		}
		int a[n-1] = {0};
		for(int i = n-2; i > n-k-2; i--){
			a[i] = 1;
		}
		
		do{
			mx = max(mx,maxComb(a));
		}while(next_permutation(a,a+n-1));
		return mx; 
	}
};

int main(){
	Solution s;
	cout << s.maxRes();
	//cout << s.maxRes2();
	return 0;
} 
