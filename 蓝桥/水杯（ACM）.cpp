#include<iostream>

using namespace std;

class Solution{
private:
	bool memo[1000000] = {0};
	int size[3];
	int f1,f2,f3;
	int res = -1;
	void dfs(int c1,int c2,int c3,int cnt){
		cout << c1 <<" "<< c2 <<" "<< c3 <<endl;
		if(f1==c1&&f2==c2&&f3==c3) {
			res = cnt;
			return;
		}		
		int a = getVal(c1,c2,c3);
		if(memo[a]) {
			cout << endl;
			return;	
		}
		memo[a] = true;
		if(c1 > 0){
			if (leftSpace(c1,c2,1))
				dfs(c1+c2-size[1],size[1],c3,cnt+1);
			else
				dfs(0,c2+c1,c3,cnt+1);
				
			if(leftSpace(c1,c3,2))
				dfs(c1+c3-size[2],c2,size[2],cnt+1);
			else
				dfs(0,c2,c3+c1,cnt+1);
		}
			
		if(c2 > 0){
			if(leftSpace(c2,c1,0))
				dfs(size[0],c2+c1-size[0],c3,cnt+1);
			else
				dfs(c1+c2,0,c3,cnt+1);
				
			if(leftSpace(c2,c3,2))
				dfs(c1,c2+c3-size[2],size[2],cnt+1);
			else
				dfs(c1,0,c3+c2,cnt+1);
		}
			
		if(c3 > 0){
			if(leftSpace(c3,c1,0))
				dfs(size[0],c2,c3+c1-size[0],cnt+1);
			else
				dfs(c1+c3,c2,0,cnt+1);
				
			if(leftSpace(c3,c2,1))
				dfs(c1,size[1],c3+c2-size[1],cnt+1);
			else
				dfs(c1,c3+c2,0,cnt+1);
		}	
		
	}
	int getVal(int c1,int c2,int c3){
		return c1*10000 + c2*100 + c3;
	}
	bool leftSpace(int a,int b,int index){
		return a > size[index] - b;
	}
public:
	int countMin(){
		int m = INT_MIN;
		int imin = 0;	
		for(int i = 0 ; i < 3; i++){
			cin >> size[i];
			int a = m;
			m = max(size[i],m);
			if(a!=m) imin = i;
		}
		cin >> f1 >> f2 >> f3;
//		Cups c;
//		c.setCups(size[0],0,0);
//		memo.push_back(c);
		if(imin == 0)
			dfs(m,0,0,-1);
		else if(imin == 1)
			dfs(0,m,0,-1);
		else if(imin == 2)
			dfs(0,0,m,-1);	
		return res;	 
	} 
};

int main(){
	int x;
	cin >> x;
	for(int i = 0; i < x; i++){
		Solution s;
		cout << s.countMin()<<endl;
	}
		
	return 0;
} 
