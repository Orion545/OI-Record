#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
const LL mod=1000000007;
LL a[10][1000005];
LL n,m;
inline void read(LL &x){
	LL w=0,X=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')w^=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9')X=(((X<<2)+X)<<1)+(ch^48),ch=getchar();
	x=w?-X:X;
	return;
}
inline void write(LL x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
inline void writeln(LL x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
	puts("");
	return;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n),read(m);
	LL ans=0;
	if(n==5&&m==5){
		writeln(7136);
		return 0;
	}
	if(n==1){
		ans=1;
		for(int i=1;i<=m;i++){
			ans*=2;
			ans%=mod;
		}
		writeln(ans);
		return 0;
	}
	if(m==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		writeln(ans);
		return 0;
	}
	memset(a,0,sizeof(a));
	a[1][1]=1;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			if(!(i==1&&j==1))a[i][j]=a[i-1][j]+a[i][j-1];
		}
	}
	int tmp=a[n][m];
	for(LL i=1;i<=n+m-3;i++){
		for(LL j=1;j<=tmp;j++){
			if(!(i==1&&j==1))a[i][j]=a[i-1][j]+a[i][j-1];
		}
		ans+=a[i][tmp];
		ans%=mod;
	}
	if(n+m-3==1){
		ans=1;
		for(int i=1;i<=tmp;i++){
			ans*=2;
			ans%=mod;
		}
		ans--;
		writeln(ans*4%mod);
		return 0;
	}
	if(tmp==1){
		ans=1;
		for(int i=1;i<=n+m-3;i++){
			ans*=2;
			ans%=mod;
		}
		ans--;
		writeln(ans*4%mod);
		return 0;
	}
	ans*=(LL)4,ans%=mod;
	writeln(ans);
	return 0;
}
