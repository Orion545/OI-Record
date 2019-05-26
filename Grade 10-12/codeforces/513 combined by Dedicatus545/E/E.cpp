#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,cnte,dep[200010],first[200010];
ll cnt1f[200010],cnt2f[200010],cnt1s[200010],cnt2s[200010];//f=fa s=son
ll sum1f[200010],sum2f[200010],sum1s[200010],sum2s[200010];
struct edge{
	int to,next;
}a[400010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs1(int u,int f){
	int i,v;dep[u]=dep[f]+1;
	cnt1s[u]=cnt2s[u]=sum1s[u]=sum2s[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);
		cnt1s[u]+=cnt2s[v];sum1s[u]+=sum2s[v]+cnt2s[v];
		cnt2s[u]+=cnt1s[v];sum2s[u]+=sum1s[v]+cnt1s[v];
	}
	cnt2s[u]++;
//	cout<<"finish dfs1 "<<u<<' '<<f<<' '<<cnt1s[u]<<' '<<cnt2s[u]<<' '<<sum1s[u]<<' '<<sum2s[u]<<'\n';
}
void dfs2(int u,int f){
	int i,v,tcnt;ll tsum;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
//		cout<<"do "<<u<<' '<<v<<'\n';
		//do single of v
		tcnt=cnt2s[u]-cnt1s[v]+cnt2f[u];
		tsum=sum2s[u]-(sum1s[v]+cnt1s[v])+sum2f[u]+tcnt;
		sum1f[v]=tsum;cnt1f[v]=tcnt;
		//do double of v
		tcnt=cnt1s[u]-cnt2s[v]+cnt1f[u];
		tsum=sum1s[u]-(sum2s[v]+cnt2s[v])+sum1f[u]+tcnt;
		sum2f[v]=tsum;cnt2f[v]=tcnt;
		dfs2(v,u);
	}
//	cout<<"finish dfs1 "<<u<<' '<<f<<' '<<cnt1f[u]<<' '<<cnt2f[u]<<' '<<sum1f[u]<<' '<<sum2f[u]<<'\n';
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs1(1,0);dfs2(1,0);
	ll ans=0;
	for(i=1;i<=n;i++){
		ans+=(sum2s[i]+sum2f[i])/2ll;
		ans+=(sum1s[i]-cnt1s[i])/2ll+(sum1f[i]-cnt1f[i])/2ll+(cnt1s[i]+cnt1f[i]);
	}
	cout<<ans/2ll;
}
