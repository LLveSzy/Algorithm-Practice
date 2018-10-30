#include<iostream>//10:50
#include<vector>

using namespace std;

class Solution{
private:
	vector<vector<int> > memoNum;
	vector<bool> memoN;
	int memoRow[4] = {0};
	int memoCol[4] = {0};
	int memoLine[2] = {0};
	int res;
	
	void dfs(int x, int y){

		if(x*4+y==16) {
			res ++;	
//			for(int i = 0; i < 4 ; i++){
//				for(int j = 0; j < 4; j++){
//					cout << memoNum[i][j] << " ";
//				}
//				cout << endl;
//			}
//			cout << endl;
			return;
		}
		for(int i = 2;i <= 16; i ++){
			if(memoN[i] == false&&isValid(i,x,y)){
				memoNum[x][y] = i;

				memoN[i] = true;
				memoRow[x] += i;
				memoCol[y] += i;
				if((x*4+y) % 5 == 0) memoLine[0]+=i;
				if((x*4+y) == (x+1)*3) memoLine[1]+=i;
		
				dfs(x+(y+1)/4,(y+1)%4);
				
				memoNum[x][y] = 0;
				memoN[i] = false;
				memoRow[x] -= i;
				memoCol[y] -= i;
				if((x*4+y) % 5 == 0) memoLine[0]-=i;
				if((x*4+y) == (x+1)*3) memoLine[1]-=i;				
			}			
		}
	}
	
	bool isValid(int i,int x,int y){
		if((x*4+y) % 5 == 0 && memoLine[0]+i > 34) return false;
		if((x*4+y) == (x+1)*3 && memoLine[1]+i > 34) return false;
		if(x==3&&memoCol[y]+i!=34) return false;
		if(y==3&&memoRow[x]+i!=34) return false;
		if(x==3&&y==3&&memoLine[0]+i!=34) return false;
		if(x==3&&y==0&&memoLine[1]+i!=34) return false;		
		//cout << memoRow[x] + i << "---" << memoCol[y]  << endl<<endl;
		if(memoRow[x] +  i <= 34 && memoCol[y] +  i <= 34) ;
	}
public:
	int count(){
		res = 0;
		memoNum = vector<vector<int> >(4,vector<int> (4,0));
		memoNum[0][0] = 1;
		memoN = vector<bool>(17,false);
		memoRow[0] = 1;
		memoCol[0] = 1;
		memoLine[0] = 1;
		
		dfs(0,1);
		return res;
	}
}; 

int main(){
	Solution s;
	cout << s.count();
	return 0;
}
