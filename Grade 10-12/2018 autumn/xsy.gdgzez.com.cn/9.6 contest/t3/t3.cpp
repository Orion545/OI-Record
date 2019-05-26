#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define mp make_pair
#define rank DEEP_DRAK_FANTASY
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
int n,first[200010],cnte,ch[200010],fa[200010],par[200010][20],rank[200010][20],dep[200010],sa[200010];
struct edge{
	int to,next,w;
}a[400010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;dep[u]=dep[f]+1;fa[u]=f;
//	cout<<"dfs "<<u<<' '<<f<<' '<<dep[u]<<' '<<fa[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		ch[v]=a[i].w+1;dfs(v,u);
	}
}
pair<pair<int,int>,int>pos[200010];
int suf(int u,int v){
	u=sa[u];v=sa[v];
	if(u==v) return dep[u];
	int re=0,i;
	for(i=18;i>=0;i--){
		if(rank[u][i]==rank[v][i]){
			re+=(1<<i);
			u=par[u][i];
			v=par[v][i];
		}
	}
	return re;
}
void getrank(){
	int i,j,p;
	for(i=1;i<=n;i++) rank[i][0]=ch[i],par[i][0]=fa[i];
	for(j=1;j<=18;j++){
		for(i=1;i<=n;i++){
			pos[i]=mp(mp(rank[i][j-1],rank[par[i][j-1]][j-1]),i);
			par[i][j]=par[par[i][j-1]][j-1];
		}
		sort(pos+1,pos+n+1);
		rank[pos[1].second][j]=1;
		p=1;
		for(i=2;i<=n;i++) 
			rank[pos[i].second][j]=(pos[i-1].first==pos[i].first)?p:++p;
//		for(i=1;i<=n;i++) cout<<i<<' '<<rank[i][j]<<' '<<par[i][j]<<'\n';
	}
	for(i=1;i<=n;i++) sa[rank[i][18]]=i;
}
set<int>s[200010];
int ufs[200010],ans[200010],leaf[200010];
int find(int x){return ((ufs[x]==x)?x:ufs[x]=find(ufs[x]));}
void merge(int u,int v,int cur){
	if(s[u].size()<s[v].size()) swap(u,v);
	ufs[v]=u;
	set<int>::iterator it,i;
//	cout<<"	merge "<<u<<' '<<v<<'\n';
	for(i=s[v].begin();i!=s[v].end();i++){
		it=s[u].lower_bound(*i);
		if(it!=s[u].begin()) ans[cur]=max(ans[cur],suf((*(--it)),(*i))),it++;
		if(it!=s[u].end()) ans[cur]=max(ans[cur],suf((*it),(*i)));
	}
	for(i=s[v].begin();i!=s[v].end();i++) s[u].insert(*i);
}
void solve(int u,int f){
//	cout<<"solve "<<u<<' '<<f<<'\n';
	if(a[first[u]].to==f&&a[first[u]].next==-1){leaf[u]=1;return;}
//	cout<<"passed\n";
	int i,v;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		solve(v,u);
		ans[u]=max(ans[u],ans[v]);
		merge(find(u),find(v),u);
	}
//	cout<<"finish solve "<<u<<' '<<ans[u]<<' '<<dep[u]<<'\n';
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2;
	for(i=2;i<=n;i++){
		t1=read();t2=read();
		add(i,t1,t2);
	}
	ch[1]=0;dfs(1,0);
	getrank();
	for(i=1;i<=n;i++) ufs[i]=i,s[i].insert(rank[i][18]);
	solve(1,0);
	int re=0;
	for(i=1;i<=n;i++) if(!leaf[i]) re=max(re,ans[i]+dep[i]-1);
	printf("%d\n",re);
}
