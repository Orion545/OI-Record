#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 5010
using namespace std;
int n,m,tot,Ans[maxn],ans[maxn],sz,p;
int las[maxn],nex[maxn],tov[maxn],fa[maxn];
int l[maxn],r[maxn],dfn[maxn],low[maxn];
int stack[maxn],son[2],ss,ps,num;
bool vis[maxn],Scc[maxn],flag;
void ins(int x,int y){
	tov[++tot]=y,nex[tot]=las[x],las[x]=tot;
	tov[++tot]=x,nex[tot]=las[y],las[y]=tot;
}
void dfs1(int x){
	dfn[x]=low[x]=++sz;
	stack[++stack[0]]=x;
	for (int i=las[x];i;i=nex[i]){
		if(tov[i]==fa[x]) continue;
		if(!dfn[tov[i]]) 
			fa[tov[i]]=x,dfs1(tov[i]),low[x]=min(low[x],low[tov[i]]);
		else low[x]=min(low[x],dfn[tov[i]]);
	}
	if(dfn[x]==low[x]){
		if(stack[stack[0]]!=x)Scc[x]=true,p=x;
		while(stack[stack[0]]!=x)
			Scc[stack[stack[0]]]=true,stack[0]--;
		stack[0]--;
	}
}
bool pd(int x){
	for (int i=l[x];i<=r[x];++i) 
		if(ans[i]==ss) return false;
	return true;
}
void dfs2(int x){
	Ans[++Ans[0]]=x;
	vis[x]=true;
	if(x==p){
		l[x]=ans[0]+1;
		for (int i=las[x];i;i=nex[i]){
			if(tov[i]!=fa[x]) ans[++ans[0]]=tov[i];
			if(Scc[tov[i]]){
				int q=(!son[0])?0:1;
				son[q]=tov[i];
			}
		}
		r[x]=ans[0];
		ss=(son[0]>son[1])?son[0]:son[1];
		ps=(son[0]>son[1])?son[1]:son[0];
	}else{
		l[x]=ans[0]+1;
		for (int i=las[x];i;i=nex[i]) 
			if((!vis[tov[i]])&&tov[i]!=fa[x]) 
				ans[++ans[0]]=tov[i];	
		r[x]=ans[0];
	}
	if(x!=p&&Scc[x]&&(!flag)){
		int i;
		if(pd(x)){
			++r[x];
			ans[++ans[0]]=ss;
		}
		sort(ans+l[x],ans+l[x]+(r[x]-l[x]+1));
		for (i=l[x];i<=r[x];++i) 
			if(!Scc[ans[i]]) fa[ans[i]]=x,flag|=(ans[i]==ss)?1:0,dfs2(ans[i]);
			else break;
		if(i+1==r[x]){
			if(ans[i]==ss){
				flag|=(ans[i]==ss)?1:0;
				dfs2(ss);
				dfs2(ans[r[x]]);
			}
			else flag|=(ans[i]==ss)?1:0,dfs2(ans[i]);
		}else{
			if(i==r[x]&&ans[r[x]]==ss) flag=1,dfs2(ss);
			for (;i<=r[x];++i) 
				if(ans[i]!=ss) fa[ans[i]]=x,flag|=(ans[i]==ss)?1:0,dfs2(ans[i]);
		}
	}else{
		sort(ans+l[x],ans+l[x]+(r[x]-l[x]+1));
		for (int i=l[x];i<=r[x];++i) 
			if(!vis[ans[i]])fa[ans[i]]=x,flag|=(ans[i]==ss)?1:0,dfs2(ans[i]);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i,j,x,y;
	for (i=1;i<=m;++i) scanf("%d%d",&x,&y),ins(x,y);
	tot=0;
	dfs1(1);
	dfs2(1);
	for (i=1;i<=n;++i) printf("%d ",Ans[i]);
}
