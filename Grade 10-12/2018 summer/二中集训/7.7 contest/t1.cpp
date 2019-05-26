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
int n,m,w[500010],t[500010],s,cntt;
struct graph{
	int cnt,first[500010],dfn[500010],low[500010],in[500010],clk;
	int s[500010],top,belong[500010],bcc;
	
	struct edge{
		int from,to,next;
	}a[500010];
	void init(){
		memset(first,-1,sizeof(first));cnt=top=clk=0;
	}
	inline void add(int u,int v){
		a[++cnt]=(edge){u,v,first[u]};first[u]=cnt;
	}
	void tarjan(int u){
		int i,v;dfn[u]=low[u]=++clk;
		s[++top]=u;in[u]=1;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(!dfn[v]){
				tarjan(v);
				low[u]=min(low[u],low[v]);
			}
			else if(in[v]) low[u]=min(low[u],dfn[v]);
		}
		if(dfn[u]==low[u]){
			bcc++;
			while(s[top]!=u){
				belong[s[top]]=bcc;
				in[s[top]]=0;s[top--]=0;
			}
			belong[s[top]]=bcc;in[s[top]]=0;
			s[top--]=0;
		}
	}
}G;
struct graph2{
	int cnt,first[500010],dp[500010],val[500010],in[500010],q[500010];
	struct edge{
		int to,next;
	}a[500010];
	void init(){
		memset(first,-1,sizeof(first));cnt=0;
	}
	inline void add(int u,int v){
		a[++cnt]=(edge){v,first[u]};first[u]=cnt;
		in[v]++;
	}
	int DAG(int s,int t){
		dp[s]=val[s];int i,v,u,head=0,tail=1;
		q[0]=s;
		while(head<tail){
			u=q[head++];
			for(i=first[u];~i;i=a[i].next){
				v=a[i].to;
				dp[v]=max(dp[v],dp[u]+val[v]);
				in[v]--;
				if(!in[v]) q[tail++]=v;
			}
		}
		return dp[t];
	} 
}g;
int main(){
	G.init();g.init();
	n=read();m=read();int i,t1,t2;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		G.add(t1,t2);
	}
	for(i=1;i<=n;i++) w[i]=read();
	s=read();cntt=read();
	for(i=1;i<=cntt;i++) t1=read(),t[t1]=1;
	G.tarjan(s);
	s=G.belong[s];
	for(i=1;i<=G.cnt;i++){
		if(G.belong[G.a[i].from]&&G.belong[G.a[i].to]&&(G.belong[G.a[i].from]!=G.belong[G.a[i].to]))
			g.add(G.belong[G.a[i].from],G.belong[G.a[i].to]);
	}
	for(i=1;i<=n;i++) if(G.belong[i]&&t[i]) g.add(G.belong[i],G.bcc+1);
	for(i=1;i<=n;i++) if(G.belong[i]) g.val[G.belong[i]]+=w[i];
	printf("%d\n",g.DAG(s,G.bcc+1));
}
