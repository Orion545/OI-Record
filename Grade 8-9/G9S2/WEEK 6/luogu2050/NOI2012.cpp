#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define inf 1e9
#define id(i,j) ((i-1)*p+j+n)
#define left(x) ((x-n-1)/p+1)
#define right(x) ((x-n-1)%p+1)
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
int n,m,cnt=-1,first[100010],dis[100010],vis[100010],pre[100010],limit[100010];
struct edge{
	int to,next,w,cap;
}a[10000010];
inline void add(int u,int v,int w,int cap){
//	cout<<"add "<<u<<' '<<v<<' '<<w<<' '<<cap<<'\n';
	a[++cnt]=(edge){v,first[u],w,cap};first[u]=cnt;
	a[++cnt]=(edge){u,first[v],-w,0};first[v]=cnt;
}
int q[200010],ans,cost[50][110],p;
bool spfa(int s,int t){
//	cout<<"spfa "<<s<<" "<<t<<"\n";
	int head=0,tail=1,u,v,w,i;
	memset(dis,-1,sizeof(dis));memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));memset(limit,0,sizeof(limit));
	q[0]=s;vis[s]=1;dis[s]=0;limit[s]=inf;
	while(head<tail){
		u=q[head++];vis[u]=0;
//		cout<<"	begin "<<u<<' '<<dis[u]<<"\n";
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;w=a[i].w;
//			cout<<"		to "<<v<<' '<<dis[v]<<' '<<w<<' '<<a[i].cap<<'\n';
			if(a[i].cap&&((dis[v]==-1)||(dis[v]>dis[u]+w))){
//				cout<<"			suc\n";
				dis[v]=dis[u]+w;
				pre[v]=i;limit[v]=min(limit[u],a[i].cap);
				if(!vis[v]) q[tail++]=v,vis[v]=1;
			}
		}
	}
	return ~dis[t];
}
void mcmf(int s,int t){
	int u,i;
	while(spfa(s,t)){
//		cout<<"end spfa "<<limit[t]<<"\n";
		for(u=t;~pre[u];u=a[pre[u]^1].to){
			a[pre[u]].cap-=limit[t];a[pre[u]^1].cap+=limit[t];
			ans+=limit[t]*a[pre[u]].w;
		}
		u=a[pre[t]^1].to;
//		cout<<"used "<<u<<' '<<pre[t]<<", new "<<u+1<<'\n';
		add(u+1,t,0,1);
		for(i=1;i<=n;i++) add(i,u+1,cost[i][left(u+1)]*right(u+1),1);
//		system("pause"); 
	}
}
int main(){
	memset(first,-1,sizeof(first));int i,j,t1;
	n=read();m=read();
	for(i=1;i<=n;i++){
		t1=read();p+=t1;
		add(0,i,0,t1);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cost[i][j]=read();
			add(i,id(j,1),cost[i][j],1);
		}
	}
//	system("pause");
	for(j=1;j<=m;j++) add(id(j,1),n+p*m+1,0,1);
	mcmf(0,n+p*m+1);
	cout<<ans<<endl;
}
