//#include<iostream>//20:36 
//#include<math.h>
//using namespace std;
//
//int main(){
//	int n = pow(3,7)-1,res = 0;
//	int L,R;
//	cin >> L >> R;
//	for(int i = 2; i <= n; i++){
//		int j = 2;
//		for(; j*j <= i ; j++){
//			if(i%j==0) break;
//		}
//		if(j*j > i ) res++;
//		else if(i <= R && i >= L) res++;
//	}
//	cout << res;
//	return 0;
//} 
#include <iostream>
using namespace std;
bool IsPrime( int a )
{
    int i;
    if(a<2)return 0;
    for(i=2;i*i<=a;i++)
    {
        if(a%i==0)return 0;
    }
    return 1;
}
int main()
{
    int L,R,S,ans;
    while(cin>>L>>R)
    {
        ans=0;
        for(int i1=0;i1<3;i1++)
         for(int i2=0;i2<3;i2++)
          for(int i3=0;i3<3;i3++)
           for(int i4=0;i4<3;i4++)
            for(int i5=0;i5<3;i5++)
             for(int i6=0;i6<3;i6++)
        {
            S=i1+i2+i3+i4+i5+i6;
            if((S>=L&&S<=R)||IsPrime(S))ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
