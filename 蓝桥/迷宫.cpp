#include<iostream> //20:10
#include<vector>

using namespace std;

class Solution{
private:
	int m, n;
public:
	int CountN(vector<vector<char> > map){
		m = map.size();
		n = map[0].size();

		int res = 0;
		
		for(int i = 0; i < m; i++){			
			for(int j = 0; j < n; j++){
				int count = 0;
				int x = i,y = j;
				while(x >= 0 && x < m && y >= 0 && y < n && count < 100){
					char c = map[x][y];
						if(c =='U')
							x--;
						else if(c =='D')
							x++;				
						else if(c =='L')
							y--;
						else if(c =='R')
							y++;					
					cout << x << "---" << y << "---"<< count <<endl;
					cout << i << "---" << j << "---" <<endl;
					count ++;	
				}
				if(count < 100) res ++ ;											
			}						
		}
		return res;
	}
};

int main(){
	vector<vector<char> > map  = vector<vector<char> >(10,vector<char>(10,'\0'));
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++){
			cin >> map[i][j];
		}	
	
	Solution s;		
	cout << s.CountN(map);
	return 0;
} 
