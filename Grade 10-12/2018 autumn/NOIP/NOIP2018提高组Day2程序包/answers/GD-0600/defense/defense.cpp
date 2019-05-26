#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
#define min(a,b) (a<b?a:b)
#define fb(i,x) for(i=last[x];i;i=next[i])
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const ll maxN=1e5+10,maxM=3e5+10;
ll n,i,x,y,m,a[maxN],f[maxN][2],last[maxN],next[maxM],tov[maxM],
tot,a1,b1,a2,b2,ans;
char ch1,ch2;
void ins(ll x,ll y){tov[++tot]=y,next[tot]=last[x],last[x]=tot;
}
void dfs(ll x,ll fx){
	int i,y;
	if (x==a1 || x==b1){
		if (x==a1) f[x][1-a2]=-1;
		else f[x][1-b2]=-1;
	}
	if (f[x][1]!=-1) f[x][1]=a[x];
	fb(i,x){
		y=tov[i];
		if (y!=fx){
			dfs(y,x);
			if (f[x][0]!=-1){
				if (f[y][1]==-1) f[x][0]=-1;
				else f[x][0]+=f[y][1];
			}
			if (f[x][1]!=-1){
				if (f[y][0]==-1 && f[y][1]==-1) f[x][1]=-1;
				else if (f[y][0]==-1) f[x][1]+=f[y][1];
				else if (f[y][1]==-1) f[x][1]+=f[y][0];
				else f[x][1]+=min(f[y][0],f[y][1]);
			}
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%lld%lld %ch",&n,&m,&ch1);ch2=getchar();
	fo(i,1,n)
		scanf("%lld",&a[i]);
	fo(i,1,n-1){
		scanf("%lld%lld",&x,&y);
		ins(x,y),ins(y,x);
	}
	for(;m;m--){
		memset(f,0,sizeof(f));
		scanf("%lld%lld%lld%lld",&a1,&a2,&b1,&b2);
		dfs(1,0);
		if (f[1][0]==-1) ans=f[1][1];
		else if (f[1][1]==-1) ans=f[1][0];
		else  ans=min(f[1][0],f[1][1]);
		printf("%lld\n",ans);
	}
	return 0;
}
