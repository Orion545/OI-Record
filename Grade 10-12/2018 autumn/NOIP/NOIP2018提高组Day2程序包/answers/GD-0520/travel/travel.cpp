#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define of(i,l,r) for(int i=l;i>=r;--i)
#define fe(i,u) for(int i=0;i<(int)ve[u].size();++i)
#define fin(str) freopen(str,"r",stdin)
#define fou(str) freopen(str,"w",stdout)
using namespace std;
typedef long long ll;
inline int rd()
{static int x,f;static char ch;
	x=0;f=1;ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=5010;
int n,m,st[N],tp=0,a[N],b[N],t;
int cir[N],sz=0;
bool vis[N],bo[N][N];
vector<int>ve[N];

bool dfs(int u,int fat)
{
	vis[u]=1;st[++tp]=u;
	bool flag=0;
	fe(i,u){
		int v=ve[u][i];if(v==fat)continue;
		if(!vis[v])flag|=dfs(v,u);
		else{
			while(st[tp]!=v)cir[++sz]=st[tp--];
			cir[++sz]=st[tp--];flag=1;
		}
		if(flag)return 1;
	}
	return 0;
}

void travel(int u)
{
	vis[u]=1;b[++t]=u;
	fe(i,u){
		int v=ve[u][i];
		if(vis[v]||bo[u][v])continue;
		travel(v);
	}
}

inline bool cmp(){
	fo(i,1,n)
		if(a[i]!=b[i])return a[i]>b[i];
	return 0;
}

int main()
{
	fin("travel.in");fou("travel.out");
	n=rd();m=rd();
	fo(i,1,m){
		int x=rd(),y=rd();
		ve[x].push_back(y);
		ve[y].push_back(x);
	}
	fo(i,1,n)sort(ve[i].begin(),ve[i].end());
	dfs(1,0);
	memset(vis,0,sizeof vis);
	if(sz){
		fo(i,1,sz){
			int x=cir[i],y=cir[i%sz+1];
			memset(vis,0,sizeof vis);
			bo[x][y]=bo[y][x]=1;
			t=0;
			travel(1);
			if(!a[1]||cmp())
				fo(j,1,n)a[j]=b[j];
			bo[x][y]=bo[y][x]=0;
		}
		fo(i,1,n)printf("%d ",a[i]);puts("");
		return 0;
	}
	travel(1);
	fo(i,1,n)printf("%d ",b[i]);puts("");
	return 0;
}

