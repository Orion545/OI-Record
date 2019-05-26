#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
inline ll rd(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
	return f*x;
}
const ll maxn=1e5,maxm=1e5,inf=1ll<<45;
ll N,M,u,v,A,X,B,Y,P[maxn+50],edge_head[maxn+50],num_edge=0,F[maxn+50][2],ans;
bool vis[maxn+50];
char s[5];
struct Edge{
	int to,nx;
}edge[(maxn<<1)+50];
inline void Add_edge(int from,int to){
	edge[++num_edge].nx=edge_head[from];
	edge[num_edge].to=to;
	edge_head[from]=num_edge;
	return;
}
inline void DP(int x,int fa){
	vis[x]=1;
	F[x][1]=P[x];
	for(int i=edge_head[x];i;i=edge[i].nx){
		int y=edge[i].to;
		if(y==fa)continue;
		if(vis[y]==0)DP(y,x);
		F[x][1]+=min(F[y][0],F[y][1]);
		F[x][0]+=F[y][1];
		if(F[x][0]>=inf)F[x][0]=inf;
	}
	if((x==A&&X==1)||(x==B&&Y==1))F[x][0]=inf;
	if((x==A&&X==0)||(x==B&&Y==0))F[x][1]=inf;
	return;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	N=rd();M=rd();scanf("%s",s);
	for(int i=1;i<=N;i++)P[i]=rd();
	for(int i=1;i<N;i++){
		u=rd();v=rd();
		Add_edge(u,v);
		Add_edge(v,u);
	}
	while(M--){
		A=rd();X=rd();B=rd();Y=rd();
		memset(vis,0,sizeof(vis));
		memset(F,0,sizeof(F));
		DP(1,0);
		if(F[1][0]<F[1][1])ans=F[1][0];else ans=F[1][1];
		if(ans>=inf)printf("-1\n");
		else printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
