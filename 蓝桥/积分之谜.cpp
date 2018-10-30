#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int> a1 ;
	int a2[] = {1,4,6,7};
	a1.push_back(2);a1.push_back(3);a1.push_back(5);a1.push_back(8);
	int a[4] = {0},b[4] = {0};
	int res1 ,res2 ,i = 0;
	do{
		res1 = 0; res2 = 0;
		for(int i = 0; i < 4; i++){
			res1 += pow(a1[i] * 10 + a2[i],2);
			res2 += pow(a2[i] * 10 + a1[i],2);
		}
		if(res1 == res2) {		
			cout << a1[0] << " " << a1[1] << " "<< a1[2] << " "<< a1[3]  << " " <<res1 << " " << res2 << endl<< endl;
			i++;
		}
	}while(next_permutation(a1.begin(),a1.end()));
	cout << i;
	return 0;
}
