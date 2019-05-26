#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define maxn 50005
using namespace std;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int N,M;
struct node{
	int nex,to,w;
	friend bool operator < (node a,node b){
		return a.w<b.w;
	}
}edge[maxn<<1];
int head[maxn],tot;
inline void insert(int from,int to,int w){
	edge[++tot].nex=head[from];
	head[from]=tot;
	edge[tot].to=to;
	edge[tot].w=w;
}
int fa[maxn],dis[maxn];
bool vis[maxn];
int ans;
void baoli_dfs(int x){
	ans=max(ans,dis[x]);
	for(int i=head[x];i;i=edge[i].nex){
		int y=edge[i].to;
		if(!dis[y]){
			dis[y]=dis[x]+edge[i].w;
			baoli_dfs(y);
		}
	}
}
void baoli2(){
	sort(edge+1,edge+1+tot);
	printf("%d",edge[1].w);
}
void baoli1(){
	ans=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			dis[j]=0;
		dis[i]=1;
		baoli_dfs(i);
	}
	printf("%d",ans-1);	
}
int tim;
bool check(int x,int u,int dept,int w,int mid){
	if(w>=mid){
		tim++;
		w=0;
	}
	if(tim>=M)
		return 1;
	if(dept==N)
		return 0;
	for(int i=head[x];i;i=edge[i].nex){
		int y=edge[i].to;
		if(y==u)
			continue ;
		return check(y,x,dept+1,w+edge[i].w,mid);
	}
}
void baoli3(){
	int l=1,r=1000000009,mid,an;
	while(l<=r){
		mid=l+r>>1;
		tim=0;
		if(check(1,1,1,0,mid))
			l=mid+1,an=mid;
		else
			r=mid-1;
	}
	printf("%d",an);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	read(N);read(M);
	int u,v,w;
	for(int i=1;i<N;i++){
		read(u);read(v);read(w);
		insert(u,v,w);
		insert(v,u,w);
	}
	if(M==1)
		baoli1();
	else if(M==N-1)
		baoli2();
	else
		baoli3();
}
