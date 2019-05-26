#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 50050
#define ll long long
struct E{ll to,w,nxt;}le[N<<1];
ll n,m,a,b,c,L,R,mid,lsum,tot;
ll used[N],fst[N],dp[N],dep[N],l[N];
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
void make(int u,int F){
	int v,cnt=0,tot=0;
	
	for(int now=fst[u];now;now=le[now].nxt){
		v=le[now].to;
		if(v==F)continue;
		make(v,u);
	}
	for(int now=fst[u];now;now=le[now].nxt){
		v=le[now].to;
		if(v==F)continue;
		++cnt;
		tot+=dp[v];
		l[cnt]=dep[v]+le[now].w;
	}
	if(!cnt){dp[u]=dep[u]=0;return;}
	for(int i=0;i<=cnt;++i)used[i]=0;
	sort(l,l+cnt+1);
	int i=1,j=cnt;
	while(l[j]>=mid)++tot,used[j]=1,--j;
	while(j>i&&l[j]+l[j-1]>=mid){
		while(l[j]+l[i]<mid)++i;
		used[i]=used[j]=1;
		++tot,++i,--j;
	}
	dp[u]=tot;
	j=cnt;
	while(used[j]&&j)--j;
	if(!j)dep[u]=0;
	else dep[u]=l[j];
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","W",stdout);
	rd(n),rd(m);
	for(int i=1;i<n;++i){
		rd(a),rd(b),rd(c);
		lsum+=c;
		le[++tot]=(E){b,c,fst[a]},fst[a]=tot;
		le[++tot]=(E){a,c,fst[b]},fst[b]=tot;
	}
	L=0,R=lsum/m;
	while(R-1>L){
		mid=(R+L)>>1;
		make(1,0);
		if(dp[1]>=m)L=mid;
		else R=mid;
		memset(dp,0,sizeof dp);
		memset(dep,0,sizeof dep);
	}
	printf("%lld\n",L);
}

