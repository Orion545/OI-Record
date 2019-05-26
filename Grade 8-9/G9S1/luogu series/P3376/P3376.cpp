#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
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
int n,m,cnt,xx,yy,ans,first[100010];
int dep[100010],q[100010],num[100010],cur[100010];
struct edge{
	int to,next,w;
}a[200010];
inline void add(int u,int v,int w){
	a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
	a[++cnt]=(edge){u,first[v],0};first[v]=cnt;
}
void bfs(int s,int t){
	memset(num,0,sizeof(num));memset(dep,0,sizeof(dep));memset(q,0,sizeof(q));
	int i,u,v,head=0,tail=1;
	num[dep[t]=0]++;q[0]=t;dep[t]=1;
	for(i=1;i<=n;i++) cur[i]=first[i];
	while(head<tail){
		u=q[head++];
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(!a[i].w&&!dep[v]){
				num[dep[v]=dep[u]+1]++;
				q[tail++]=v;
			}
		}
	}
}
inline int _min(int l,int r){return (l<r)?l:r;}
int dfs(int u,int s,int t,int limit){
//	cout<<"dfs "<<u<<ends<<s<<ends<<t<<ends<<limit<<endl;
	if(u==t||!limit) return limit;
	int flow=0,i,v,f;
	for(i=first[u];~i;i=a[i].next){
		cur[u]=i;
		v=a[i].to;
//		cout<<"	to "<<v<<endl;
		if(dep[u]==dep[v]+1){
			f=dfs(v,s,t,_min(limit,a[i].w));
			flow+=f;limit-=f;
			a[i].w-=f;a[i^1].w+=f;
			if(!limit) return flow;
		}
	}
	if(!(--num[dep[u]])) dep[s]=n+1;
	num[++dep[u]]++;cur[u]=first[u];
	return flow;
}
void isap(int s,int t){
	bfs(s,t);
//	for(int i=1;i<=n;i++) cout<<dep[i]<<ends;cout<<endl;
	ans=dfs(s,s,t,inf);
	while(dep[s]<n) ans+=dfs(s,s,t,inf);
}
void init(){
	memset(first,-1,sizeof(first));memset(a,0,sizeof(a));
	cnt=-1;ans=0;
}
int main(){
	init();
	int i,t1,t2,t3;
	n=read();m=read();xx=read();yy=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	isap(xx,yy);
	printf("%d\n",ans);
}
