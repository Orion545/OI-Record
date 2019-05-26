#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,first[50010],cnte,m;
ll tot=0;
struct edge{
	ll to,next;
}a[100010];
inline void add(ll u,ll v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
namespace dfz{
	ll siz[50010],son[50010],sum,root,vis[50010];
	ll dep[50010],cnt[50010],tmp[50010],ans,limtmp,limcnt,lim;
	void getroot(ll u,ll f){
//		cout<<"getroot "<<u<<' '<<f<<'\n';
		ll i,v;siz[u]=1;son[u]=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f||vis[v]) continue;
			getroot(v,u);
			siz[u]+=siz[v];
			son[u]=max(son[u],siz[v]);
		}
		son[u]=max(son[u],sum-siz[u]);
		if(son[u]<son[root]) root=u;
	}
	void calc(ll u,ll f){
		ll i,v;dep[u]=dep[f]+1;
		tmp[dep[u]]++;limtmp=max(limtmp,dep[u]);
//		cout<<"calc "<<u<<' '<<f<<' '<<dep[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(vis[v]||v==f) continue;
			calc(v,u);
		}
	}
	void dfs(ll u,ll cursum){
//		cout<<"dfs "<<u<<'\n';
		ll i,j,v;vis[u]=1;dep[u]=0;
		cnt[0]=1;limcnt=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(vis[v]) continue;
			calc(v,u);
			for(j=1;j<=min(limtmp,lim);j++)
				ans+=tmp[j]*cnt[lim-j];
			for(j=1;j<=limtmp;j++) cnt[j]+=tmp[j];
			limcnt=max(limtmp,limcnt);
			for(j=1;j<=limtmp;j++) tmp[j]=0;
			limtmp=0;
		}
//		cout<<"finish phase 1\n";
		for(j=0;j<=limcnt;j++) cnt[j]=0;
		limtmp=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(vis[v]) continue;
			sum=((siz[v]>siz[u])?(cursum-siz[u]):siz[v]);
			root=0;son[root]=sum;
			getroot(v,0);
			dfs(root,sum);
		}
	}
	void get(ll len){
		lim=len;ans=0;
		memset(vis,0,sizeof(vis));
		sum=n;root=0;son[0]=sum;
		getroot(1,0);
		dfs(root,sum);
		tot+=ans;
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();ll i,t1,t2,sp[20]={0};
	for(i=1;i<=m;i++) sp[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=m;i++) dfz::get(sp[i]);
//	cout<<tot<<'\n';
	i=(n+2)/3;printf("%.2lf\n",(double)(i*(i-1))*(double(tot))/(double)(n*(n-1)));
	i=(n+1)/3;printf("%.2lf\n",(double)(i*(i-1))*(double(tot))/(double)(n*(n-1)));
	i=(n+0)/3;printf("%.2lf\n",(double)(i*(i-1))*(double(tot))/(double)(n*(n-1)));
}
