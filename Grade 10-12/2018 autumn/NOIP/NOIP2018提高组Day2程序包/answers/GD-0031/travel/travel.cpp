#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;
inline int rd(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
	return f*x;
}
const int maxn=5000,maxm=5000;
int N,M,num_edge=0,edge_head[maxn+50],u,v,ans[maxn+50],num,goin[maxn+50];
int s1,s2;
bool vis[maxn+50],flag2,flag,flag_;
struct Edge{
	int to,nx;
}edge[(maxm<<1)+50];
inline void Add_edge(int from,int to){
	edge[++num_edge].nx=edge_head[from];
	edge[num_edge].to=to;
	edge_head[from]=num_edge;
	return;
}

inline void Dfs1(int x,int fa){
	priority_queue<int,vector<int>,greater<int> >q;
	ans[++num]=x;
	vis[x]=1;
	for(int i=edge_head[x];i;i=edge[i].nx){
		int y=edge[i].to;
		if(y!=fa&&vis[y]==0){
			q.push(y);
		}
	}
	while(!q.empty()){
		int y=q.top();
		q.pop();
		if(vis[y]==0)Dfs1(y,x);
	}
	return;
}

inline void Dfs2(int x,int fa){
	if(flag_==0&&flag&&fa!=0)return;
	if(vis[x]==0){
		vis[x]=1;
		ans[++num]=x;
	}
	if(fa==0){
		if(flag){
			Dfs2(s2,x);
			return;
		}
		for(int i=edge_head[x];i;i=edge[i].nx){
			int y=edge[i].to;
			if(s1==0)s1=y;
			else s2=y;
		}
		if(s2<s1){int t=s1;s1=s2;s2=t;}
		Dfs2(s1,x);
		if(flag){
			flag_=1;
			Dfs2(s2,x);
		}
		return;
	}
	for(int i=edge_head[x];i;i=edge[i].nx){
		int y=edge[i].to;
		if(y!=fa&&vis[y]==0){
			if(flag_ || y<s2)Dfs2(y,x);
			else{
				flag=1;
				return;
			}
		}
	}
	return;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	flag2=1;
	N=rd();M=rd();
	for(int i=1;i<=M;i++){
		u=rd();v=rd();
		Add_edge(u,v);
		Add_edge(v,u);
		goin[u]++;
		goin[v]++;
	}
	for(int i=1;i<=N;i++)if(goin[i]!=2)flag2=0;
	if(M==N-1){
		memset(vis,0,sizeof(vis));
		num=0;
		Dfs1(1,0);
		for(int i=1;i<=N;i++)printf("%d ",ans[i]);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	
	if(flag2){
		memset(vis,0,sizeof(vis));
		s1=s2=0;
		num=0;
		flag=0;
		flag_=0;
		Dfs2(1,0);
		for(int i=1;i<=N;i++)printf("%d ",ans[i]);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	for(int i=1;i<=N;i++)printf("%d ",i);
	fclose(stdin);fclose(stdout);
	return 0;
}
