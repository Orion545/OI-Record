#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=5005;
int n,m,head[N],cnt,flag,a[N],t,dfn[N],low[N],st[N],top,ee[N][N],belong[N],num,numn,hh[N],bian[N<<1];
bool b[N<<1],vis[N];
struct edge{
	int to,nxt;
}e[N<<1];
int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-f;c=getchar();}
	while(c<='9'&&c>='0'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void add(int a,int b){
	e[++cnt].to=b;
	e[cnt].nxt=head[a];
	head[a]=cnt;
	ee[a][b]=cnt;
}
void tarjan(int u,int f){
	if(flag!=0)return;
	dfn[u]=low[u]=++t;
	vis[u]=1;
	st[++top]=u;
	for(int v,i=head[u];i;i=e[i].nxt){
		v=e[i].to;
		if(v!=f){
			if(!dfn[v]){
				tarjan(v,u);
				low[u]=min(low[u],low[v]);
			}
			else if(vis[v])low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		belong[u]=++num;
		while(st[top]!=u){
			vis[st[top]]=0;
			belong[st[top]]=num;
			flag=num;
			hh[++numn]=st[top];
			top--;
		}
		vis[st[top--]]=0;
		if(flag==num)hh[++numn]=u;
	}
}
void dfs(int x,int f){
	if(flag==1)return;
	priority_queue <int> q;
	int v;
	for(int i=head[x];i;i=e[i].nxt){
		v=e[i].to;
		if(v!=f&&b[i]==0){
			q.push(-v);
		}
	}
	while(!q.empty()){
		v=-q.top();q.pop();
		cnt++;
		if((a[cnt]>v&&flag!=1)||flag==2){
			a[cnt]=v;
			flag=2;
		}
		else if(a[cnt]<v)flag=1;
		if(flag==1)return;
		dfs(v,x);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	memset(a,0x3f,sizeof(a));
	for(int u,v,i=1;i<=m;i++){
		u=read();
		v=read();
		add(u,v);
		add(v,u);
	}
	if(m==n-1){
		flag=0;
		cnt=0;
		a[++cnt]=1;
		dfs(1,0);
	}
	else{
		cnt=0;
		for(int i=1;i<=n;i++)if(!dfn[i]&&flag==0)tarjan(i,i);
		for(int i=1;i<numn;i++){
			for(int j=i+1;j<=numn;j++){
				if(ee[hh[i]][hh[j]]!=0){
					bian[++cnt]=(ee[hh[i]][hh[j]]-1)/2;
				}
			}
		}
		for(int i=1;i<=numn;i++){
			b[bian[i]+bian[i]+2]=1;
			b[bian[i]+bian[i]+1]=1;
			flag=0;
			cnt=0;
			a[++cnt]=1;
			dfs(1,0);
			b[bian[i]+bian[i]+2]=0;
			b[bian[i]+bian[i]+1]=0;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}
