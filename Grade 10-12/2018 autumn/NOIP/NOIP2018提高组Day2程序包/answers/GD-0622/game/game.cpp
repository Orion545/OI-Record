#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
#define _ read()
const int mod=1e9+7;
int n,m;
ll f[2][256];
inline bool check(int a,int b) {
	int tota=n-1,totb=n-1,na[10]={0},nb[10]={0};
	while(a) { na[tota--]=a&1; a>>=1; }
	while(b) { nb[totb--]=b&1; b>>=1; }
	for(int i=1;i<n;i++)
		if(na[i]<nb[i-1]) return 0;
	return 1;
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=_; m=_;
	for(int j=0;j<(1<<n);j++)
		f[1][j]=1;
	for(int i=2;i<=m;i++) {
		memset(f[i&1],0,sizeof(f[i&1]));
		for(int j=0;j<(1<<n);j++) //枚举当前列的状态 
			for(int k=0;k<(1<<n);k++) { //枚举上一列的状态 
				if(check(k,j))
					f[i&1][j]=(f[i&1][j]+f[(i-1)&1][k])%mod;
			}
	}
	ll ans=0;
	for(int i=0;i<(1<<n);i++)
		cout<<f[n&1][i]<<"\n", //第n列，状态为i的方案数 
		ans=(ans+f[n&1][i])%mod;
	printf("%lld\n",ans);
} 
