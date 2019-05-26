#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define inf 1e9
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
int n,m,cnt=-1,flow,ans,first[1000],dis[1000],path[1000],pre[1000];
struct edge{
	int to,next,w,cap;
}a[100010];
inline void add(int u,int v,int w,int cap){
//	cout<<"add "<<u<<ends<<v<<ends<<w<<ends<<cap<<endl;
	a[++cnt]=(edge){v,first[u],-w,cap};first[u]=cnt;
	a[++cnt]=(edge){u,first[v],w,0};first[v]=cnt;
}
bool spfa(int s,int t){
	int i,u,v,q[2010],head=0,tail=1;
	memset(pre,-1,sizeof(pre));memset(path,-1,sizeof(path));
	for(i=s;i<=t;i++) dis[i]=inf;
	dis[s]=0;q[0]=s;
	while(head<tail){
		u=q[head++];
//		cout<<"do "<<u<<ends<<dis[u]<<ends<<head<<ends<<tail<<endl;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
//			cout<<"	to "<<v<<ends<<a[i].next<<endl;
			if(a[i].cap>0&&dis[v]>dis[u]+a[i].w){
//				cout<<"		suc"<<endl;
				dis[v]=dis[u]+a[i].w;
				pre[v]=u;path[v]=i;
				q[tail++]=v;
			}
		}
	}
	return ~pre[t];
}
void mcmf(int s,int t){
	int u,f;
	while(spfa(s,t)){
		f=inf;
		for(u=t;u!=s;u=pre[u]) f=min(f,a[path[u]].cap);
		flow+=f;ans+=f*dis[t];
		for(u=t;u!=s;u=pre[u]){
			a[path[u]].cap-=f;
			a[path[u]^1].cap+=f;
		}
	}
}
char s[1000][50];
bool vis[1000];
bool dfs(int u){
//	cout<<u<<endl;
	printf("%s\n",s[u]);vis[u]=1;
	if(u==n) return 1;
	for(int i=first[u<<1];~i;i=a[i].next){
		if(!a[i].cap&&(a[i].to&1)&&!vis[(a[i].to+1)>>1]) return dfs((a[i].to+1)>>1);
	}
}
bool search(int u){
//	cout<<u<<ends<<first[u<<1]<<endl;
	vis[u]=1;
	if(u==n) return 1;
	for(int i=first[u<<1];~i;i=a[i].next){
//		cout<<"dfs "<<a[i].cap<<ends<<a[i].to<<endl;
		if(!a[i].cap&&(a[i].to&1)&&!vis[(a[i].to+1)>>1]){
//			cout<<(u<<1)<<" to "<<a[i].to<<endl;
			if(search((a[i].to+1)>>1)) break;
		}
	}
	printf("%s\n",s[u]);return 1;
}
int main(){
	memset(first,-1,sizeof(first));
	int i,l,r,t3,t4;char t1[100],t2[100];
	n=read();m=read();
	for(i=1;i<=n;i++){
		scanf("%s",s[i]);
		add((i<<1)-1,(i<<1),1,((i==1||i==n)?2:1));
	}
	for(i=1;i<=m;i++){
		scanf("%s%s",t1,t2);
		for(l=1;l<=n&&strcmp(t1,s[l]);l++);
		for(r=1;r<=n&&strcmp(t2,s[r]);r++);
		if(l>r) l^=r,r^=l,l^=r;
		add((l<<1),(r<<1)-1,0,((l==1&&r==n)?2:1));
	}
	mcmf(1,n<<1);
	ans=-ans;
	if(flow!=2) printf("No Solution!");
	else{
		printf("%d\n",ans-2);
		dfs(1);
		vis[1]=0;search(1);
	}
}
