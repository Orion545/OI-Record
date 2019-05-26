#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
int n,first[100010],cnte,dfn[100010],low[100010],clk;
struct edge{
	int to,next;
}a[1000010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
}
vector<int>g[100010];int cnt,belong[100010],dp[100010];
int s[100010],top,siz[100010];
bool ins[100010];
void tarjan(int u){
	int i,v;
	dfn[u]=low[u]=++clk;
	s[++top]=u;ins[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
//	cout<<"finish tarjan "<<u<<' '<<low[u]<<' '<<dfn[u]<<'\n';
	if(dfn[u]==low[u]){
		cnt++;int tmp=0;
		while(s[top]!=u){
			belong[s[top]]=cnt;tmp++;
			ins[s[top]]=0;s[top--]=0;
		}
		belong[s[top]]=cnt;
		ins[s[top]]=0;s[top--]=0;
		siz[cnt]=tmp+1;
	}
}
int m,in[100010],q[100010],head=0,tail=0;
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,u,v,t1,t2,flag;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(u=1;u<=n;u++){
		flag=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(belong[u]==belong[v]) flag++;
			if(flag>1) break;
		}
		if(flag>1){puts("-1");return 0;}
	}
	for(u=1;u<=n;u++){
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(belong[u]==belong[v]) continue;
			g[belong[u]].push_back(belong[v]);in[belong[v]]++;
		}
	}
//	cout<<"totcnt "<<cnt<<'\n';
//	for(i=1;i<=cnt;i++) cout<<i<<' '<<in[i]<<' '<<siz[i]<<'\n';
	for(i=1;i<=cnt;i++) if(!in[i]) q[tail++]=i;
	while(head<tail){
		u=q[head++];dp[u]+=(siz[u]>1);
//		cout<<"dp "<<u<<' '<<dp[u]<<'\n';
		for(i=0;i<g[u].size();i++){
			v=g[u][i];
			dp[v]=max(dp[v],dp[u]);
			if(!(--in[v])) q[tail++]=v;
		}
	}
	int ans=0;
	for(i=1;i<=cnt;i++) ans=max(ans,dp[i]);
	printf("%d\n",max(ans-1,0));
}
