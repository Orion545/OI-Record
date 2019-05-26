#include<bits/stdc++.h>
#define res register int
using namespace std;
const int N=50020;
typedef long long ll;
int n,m;
ll Tdis[N];
inline int rd(){
	char ch;int f=0,w=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=f*10+(ch-'0');ch=getchar();}
	return f*w;
}
int dep[N],head[N],cnt=0;
struct hs{
	int nxt,to,w;
}e[N<<1];
inline void bd(int x,int y,int z){
	e[++cnt].nxt=head[x];head[x]=cnt;
	e[cnt].to=y;e[cnt].w=z;
}
int fa[N][22];
inline void dfs(int x,int fath){
	dep[x]=dep[fath]+1;fa[x][0]=fath;
	for(res i=1;(1<<i)<=dep[x];i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(res i=head[x];i;i=e[i].nxt){
		int vv=e[i].to;
		if(vv==fath)continue;
		Tdis[vv]=Tdis[x]+e[i].w;
		dfs(vv,x);
	}
}
inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	if(dep[x]<dep[y]){
		for(res i=20;i>=0;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	}
	if(x==y)return x;
	for(res i=20;i>=0;i--)
	if(fa[x][i]!=fa[y][i]){
		x=fa[x][i];y=fa[y][i];
	}
	return fa[x][0];	
}

int u,v,ww;ll ans=0;
bool fl=true;
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=rd();m=rd();
	for(res i=1;i<n;i++){
		u=rd();v=rd();ww=rd();
		bd(u,v,ww);bd(v,u,ww);
		if(abs(u-v)!=1)fl=false;
	}
	memset(Tdis,0,sizeof(Tdis));
	dfs(1,0);
	if(m==1&&n<=5000){
		ll dd=0,d1;
		for(res i=1;i<=n;i++)
		for(res j=i+1;j<=n;j++){
			d1=Tdis[i]+Tdis[j]-2*Tdis[lca(i,j)];
			if(dd<d1)dd=d1;
		}
		printf("%I64d",dd);
	}
	
	return 0;
}
