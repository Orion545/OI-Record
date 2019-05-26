#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<ctime>
#define MOD 1000000007
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
int n,m,inv2,pri[10010],cntp,vis[100010];ll g[100010],ans[100010];
void init(){
	int i,j,k;
	for(i=2;i<=n;i++){
		if(!vis[i]) pri[++cntp]=i;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>n) break;
			vis[k]=1;if(i%pri[j]==0) break;
		}
	}
}
int _plus(int a,int b){
	a+=b;
	return (a>=MOD)?a-MOD:a;
}
int _minus(int a,int b){
	a-=b;
	return (a<0)?a+MOD:a;
}
void fwt(ll *a,int type){
	int mid,j,k,len,x,y;
	for(mid=1;mid<n;mid<<=1)
		for(len=mid<<1,j=0;j<n;j+=len)
			for(k=0;k<mid;k++){
				x=a[j+k];y=a[j+k+mid];
				a[j+k]=_plus(x,y);a[j+k+mid]=_minus(x,y);
				if(type==-1) a[j+k]=1ll*a[j+k]*inv2%MOD,a[j+k+mid]=1ll*a[j+k+mid]*inv2%MOD;
			}
}
int main(){
//	freopen("in.in","r",stdin);
//	freopen("my.out","w",stdout);
	n=65536;init();inv2=qpow(2,MOD-2);
//	int c1,c2,c3,c4;
	while(cin>>m>>n){
		int i,cnt=0;
//		c1=clock();
		while((1<<cnt)<=n) cnt++;
		memset(g,0,sizeof(g));
		for(i=2;i<=n;i++) if(vis[i]==0) g[i]=1;
		n=1<<cnt;
//		for(i=0;i<n;i++) cout<<g[i]<<' ';cout<<'\n';
		fwt(g,1);m--;
		memcpy(ans,g,sizeof(g));
//		for(i=0;i<n;i++) cout<<g[i]<<' ';cout<<'\n';
//		c2=clock();
		while(m){
			if(m&1) for(i=0;i<n;i++) ans[i]=ans[i]*g[i]%MOD;
			m>>=1;for(i=0;i<n;i++) g[i]=g[i]*g[i]%MOD;
		}
//		c3=clock();
		fwt(ans,-1);
//		for(i=0;i<n;i++) cout<<ans[i]<<' ';cout<<'\n';
		printf("%lld\n",ans[0]);
//		c4=clock();
//		cout<<n<<' '<<c2-c1<<' '<<c3-c2<<' '<<c4-c3<<'\n';
	}
}

