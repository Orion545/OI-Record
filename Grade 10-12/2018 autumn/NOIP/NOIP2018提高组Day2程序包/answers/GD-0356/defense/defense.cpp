#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 100010
#define ll long long
struct E{int to,nxt;}le[N<<1];
ll n,m,a,b,x,y,u,v,tot;
ll fst[N],dp[N][2],p[N];
char tp;
void rd(ll &x){
	static char ch;ll F=1;
	while(!isdigit(ch=getchar()))if(ch=='-')F=-1;
	for(x=0;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	x*=F;
}
void rd(int &x){
	static ll T_T;
	rd(T_T);x=T_T;
}
void dfs(int u,int F){
	int v;
	ll sum=0,min1=0;
	for(int now=fst[u];now;now=le[now].nxt){
		v=le[now].to;
		if(v==F)continue;
		dfs(v,u);
		min1=min1+min(dp[v][0],dp[v][1]);
		sum+=dp[v][1];
	}
	dp[u][0]=sum;
	dp[u][1]=p[u]+min1;
	if(u==a)dp[u][1-x]=32984298398ll;
	if(u==b)dp[u][1-y]=32984298398ll;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	rd(n),rd(m),tp=getchar(),getchar();
	for(int i=1;i<=n;++i)rd(p[i]);
	for(int i=1;i<n;++i){
		rd(u),rd(v);
		le[++tot]=(E){v,fst[u]},fst[u]=tot;
		le[++tot]=(E){u,fst[v]},fst[v]=tot;
	}
	if(m<=2000&&n<=2000){
		while(m--){
			rd(a),rd(x),rd(b),rd(y);
			dfs(1,0);
			ll ans=min(dp[1][0],dp[1][1]);
			if(ans>30000000000ll)puts("-1");
			else printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
}

