#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int first[200010],cnt;
struct edge{
	int to,next;
}a[500010];
inline void add(int u,int v){
	a[++cnt]=(edge){v,first[u]};first[u]=cnt;
}
int dfn[200010],low[200010],ins[200010],s[200010],bcc,clk,top,belong[200010];
void tarjan(int u){
	int i,v;dfn[u]=low[u]=++clk;
	s[++top]=u;ins[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		bcc++;
		while(s[top]!=u){
			belong[s[top]]=bcc;ins[s[top]]=0;
			s[top--]=0;
		}
		belong[s[top]]=bcc;ins[s[top]]=0;
		s[top--]=0;
	}
}
int n,m;
int main(){
	memset(first,-1,sizeof(first));n=read();m=read();
	int i,t1,t2;
	for(i=1;i<=m;i++){
		t1=read();t2=read();add(t1,t2);
	}
	for(i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	if(bcc>1) puts("-1");
	else puts("
}
