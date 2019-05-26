#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<set>
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
int n,m,q,w[100010],tot;
multiset<int>s[200010];
namespace t{
	int first[200010],cnte=1;
	struct edge{
		int to,next;
	}a[400010];
	inline void add(int u,int v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	int dep[200010],st[200010][20];
	void dfs(int u,int f){
		int i,v;
		st[u][0]=f;
		dep[u]=dep[f]+1;
//		cout<<"dfs "<<u<<' '<<f<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs(v,u);
		}
	}
	void ST(){
		int i,j;
		for(j=1;j<=19;j++){
			for(i=1;i<=n;i++)
				st[i][j]=st[st[i][j-1]][j-1];
		}
	}
	int lca(int l,int r){
		int i;
		if(dep[l]>dep[r]) swap(l,r);
		for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
		if(l==r) return l;
		for(i=19;i>=0;i--){
			if(st[l][i]!=st[r][i]){
				l=st[l][i];
				r=st[r][i];
			}
		}
		return st[l][0];
	}
	void change(int u,int val){
		int i,v;
		s[u].clear();
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			s[v].erase(s[v].find(w[u]));
		}
		w[u]=val;
		s[u].insert(w[u]);
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			s[v].insert(w[u]);
		}
	}
	int calc(int u,int v){
		int f=lca(u,v),re=*(s[f].begin());
		while(u!=f){
			re=min(re,*(s[u].begin()));
			u=st[u][0];
		}
		while(v!=f){
			re=min(re,*(s[v].begin()));
			v=st[v][0];
		}
		return re;
	}
}
namespace g{
	int first[100010],cnte=1,dfn[100010],low[100010],clk;
	struct edge{
		int to,next;
	}a[400010];
	inline void add(int u,int v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	int sta[100010],top;
	void tarjan(int u){
		int i,v;
		sta[++top]=u;
		dfn[u]=low[u]=++clk;
		s[u].insert(w[u]);
//		cout<<"tarjan "<<u<<' '<<w[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(!dfn[v]){
				tarjan(v);
				low[u]=min(low[u],low[v]);
				if(low[v]>=dfn[u]){
					t::add(++tot,u);
					s[tot].insert(w[u]);
					int tmp;
					do{
						tmp=sta[top--];
						s[tot].insert(w[tmp]);
						t::add(tot,tmp);
					}while(tmp!=v);
				}
			}
			else low[u]=min(low[u],dfn[v]);
		}
	}
}
int main(){
	memset(g::first,-1,sizeof(g::first));
	memset(t::first,-1,sizeof(t::first));
	n=read();m=read();q=read();int i,t1,t2;char ss[10];
	tot=n;
	for(i=1;i<=n;i++) w[i]=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		g::add(t1,t2);
	}
	g::tarjan(1);
	t::dfs(1,0);
	t::ST();
	while(q--){
		scanf("%s",ss);
		t1=read();t2=read();
		if(ss[0]=='C') t::change(t1,t2);
		else printf("%d\n",t::calc(t1,t2));
	}
}
