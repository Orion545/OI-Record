#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#define mp make_pair
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,K;
namespace G{
	vector<pair<int,int> >e[30010];
	int dis[30010],pre[30010],pval[30010],vis[30010];
	queue<int>q;
	void spfa(){
		int i,u,v,w;
		for(i=1;i<=n;i++) dis[i]=1e9;
		q.push(1);dis[1]=0;
		while(!q.empty()){
			u=q.front();q.pop();vis[u]=0;
//			cout<<"spfa "<<u<<' '<<dis[u]<<' '<<pre[u]<<'\n';
			for(auto tmp:e[u]){
				v=tmp.first;w=tmp.second;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;pre[v]=u;pval[v]=w;
					if(!vis[v]) vis[v]=1,q.push(v);
				}
			}
		}
	}
	void readin(){
		int i,t1,t2,t3;
		for(i=1;i<=m;i++){
			t1=read();t2=read();t3=read();
			e[t1].push_back(mp(t2,t3));
			e[t2].push_back(mp(t1,t3));
		}
		for(i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
	}
}
int first[30010],cnte,siz[30010],sum,son[30010],root,vis[30010];
struct edge{
	int to,next,w;
}a[100010];
inline void add(int u,int v,int w){
//	cout<<"add "<<u<<' '<<v<<' '<<w<<'\n';
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
void getroot(int u,int f){
	int i,v;siz[u]=1;son[u]=0;
//	cout<<"getroot "<<u<<' '<<f<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]||v==f) continue;
//		cout<<"	to "<<v<<" from "<<u<<" edge num "<<i<<'\n';
		getroot(v,u);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
int tmp[30010],dep[30010],dis[30010],len[30010],lim,liml,ans=0,cntans=0;
int cnttmp[30010],cntlen[30010];
void gettmp(int u,int f){
	int i,v;dep[u]=dep[f]+1;lim=max(lim,dep[u]);

	if(tmp[dep[u]]<dis[u]) tmp[dep[u]]=dis[u],cnttmp[dep[u]]=1;
	else if(tmp[dep[u]]==dis[u]) cnttmp[dep[u]]++;

//	cout<<"	getlen "<<u<<' '<<f<<' '<<dep[u]<<' '<<dis[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]||v==f) continue;
		dis[v]=dis[u]+a[i].w;
		gettmp(v,u);
	}
}
void calc(int u,int st){
	dep[0]=0;tmp[0]=0;dis[u]=st;lim=0;
	gettmp(u,0);
	int i;
	for(i=0;i<=lim&&i<=K;i++) if(liml>=K-i){
		if(ans<tmp[i]+len[K-i]){
			ans=tmp[i]+len[K-i];
			cntans=cnttmp[i]*cntlen[K-i];
		}
		else if(ans==tmp[i]+len[K-i]){
			cntans+=cnttmp[i]*cntlen[K-i];
		}
	}
	for(i=0;i<=lim;i++){
		if(len[i]<tmp[i]) len[i]=tmp[i],cntlen[i]=cnttmp[i];
		else if(len[i]==tmp[i]) cntlen[i]+=cnttmp[i];
		tmp[i]=cnttmp[i]=0;
	}
	liml=max(liml,lim);
}
void dfs(int u,int cursum){
	int i,v;vis[u]=1;liml=0;cntlen[0]=1;
//	cout<<"dfs "<<u<<' '<<cursum<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		calc(v,a[i].w);
	}
	for(i=0;i<=liml;i++) len[i]=cntlen[i]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		sum=((siz[v]>siz[u])?(cursum-siz[u]):siz[v]);
		son[0]=sum;root=0;getroot(v,0);
		dfs(root,sum);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();K=read()-1;
	G::readin();G::spfa();
	for(int i=2;i<=n;i++)
		add(i,G::pre[i],G::pval[i]);
	sum=n;son[0]=sum;root=0;
	getroot(1,0);
	dfs(root,sum);
	printf("%d %d\n",ans,cntans);
}
