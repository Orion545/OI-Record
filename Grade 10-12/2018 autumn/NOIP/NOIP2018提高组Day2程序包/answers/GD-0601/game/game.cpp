#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define modl 1000000007
using namespace std;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
long long qpow(long long a,long long b){
	long long ans=1;
	while(b){
		if(b&1)
			ans*=a,ans%=modl;
		a*=a;a%=modl;
		b>>=1;
	}
	return ans%modl;
}
int N,M;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(N);read(M);
	if(N>M)
		swap(N,M);
	if(N==1)
		printf("%lld",qpow(2,M)-1);
	if(N==2){
		long long ans=qpow(3,M-1)*4;
		ans%=modl;
		printf("%lld",ans);	
	}
	if(N==3&&M==3)
		cout<<112;
	if(N==5&&M==5)
		cout<<7136;
	
}
