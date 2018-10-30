#include<iostream>
#include<algorithm>
using namespace std;

typedef struct{
	int width,height;
	choco(){
		width = 0;
		height = 0;
	}
}Choco;

//bool compare(Choco a,Choco b){
//	return min(a.width,a.height)<min(b.height,b.width);
//}
class Solution{
private:
	int n,kids;
public:
	int maxSide(){
		cin >> n >> kids;
		Choco choco[n];
		int minn = INT_MAX;
		for(int i = 0; i < n; i ++){
			cin >> choco[i].height;
			cin >> choco[i].width;
			int a = minn;
			minn = min(min(choco[i].height,choco[i].width),minn);
		}
		//sort(choco,choco+n,compare);	
		int i = minn;
		for(; i > 0; i--){
			int sum = 0;
			for(int j = 0; j < n ; j++){
				sum += max(choco[j].height,choco[j].width)/i*
						(min(choco[j].height,choco[j].width)/i);
			}
			if(sum >= kids) break;			
		}
		return i;	
	}
};

int main()
{
	Solution s;
	cout << s.maxSide();
	return 0;
}
