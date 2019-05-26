#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define ll long long
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
int n,first[2010],cnte=-1;
struct edge{
	int to,next,from;
}a[4000010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u],u};first[u]=cnte;
}
int s[2010],top,dfn[2010],low[2010],clk,ins[2010];
vector<int>bcc[2010];int cntb,belong[2010];
void tarjan(int u){
	int i,v;
	dfn[u]=low[u]=++clk;
	s[++top]=u;ins[u]=1;
	cout<<"tarjan "<<u<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		cntb++;
		cout<<"find bcc "<<cntb<<'\n';
		do{
			v=s[top--];
			bcc[cntb].push_back(v);
			belong[v]=cntb;
			ins[u]=0;
			cout<<"	ele "<<v<<'\n';
		}while(v!=u);
	}
}
int x[2010],y[2010],z[2010],in[2010],ans[2010];
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,j,tmp;
	for(i=1;i<=n;i++){
		x[i]=read();y[i]=read();z[i]=read();
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j) continue;
			tmp=0;
			tmp+=(x[i]>x[j]);
			tmp+=(y[i]>y[j]);
			tmp+=(z[i]>z[j]);
			if(tmp>=2) add(i,j);
		}
	}
	for(i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(i=0;i<=cnte;i++) if(belong[a[i].to]!=belong[a[i].from]) in[belong[a[i].to]]++;
	for(i=1;i<=cntb;i++){
		if(!in[i]){
			for(j=0;j<bcc[i].size();j++) ans[bcc[i][j]]=1;
		}
	}
	for(i=1;i<=n;i++) printf("%d\n",ans[i]);
}
		
