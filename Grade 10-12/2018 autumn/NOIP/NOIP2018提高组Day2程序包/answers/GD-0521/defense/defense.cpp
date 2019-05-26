#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define ll long long
#define INF 1e12
using namespace std;
int n,m;
bool b[100010];
char typ[2];
ll f[100010][2],ans;
int mp[2010][2010];
int p[100010];
int u,v,x,y;
void dfs(int now,ll cost){
	if(now==n+1){
		ans=min(cost,ans);
		return;
	}
	if((now==u&&x==1)||(now==v&&y==1)){
		b[now]=1;
		dfs(now+1,cost+p[now]);
		b[now]=0;
		return;
	}
	if((now==u&&x==0)||(now==v&&y==0)){
		for(int i=1;i<=mp[now][0];i++)
			if(mp[now][i]<now&&!b[mp[now][i]])return;
		dfs(now+1,cost);
		return;
	}
	b[now]=1;
	dfs(now+1,cost+p[now]);
	b[now]=0;
	for(int i=1;i<=mp[now][0];i++)
		if(mp[now][i]<now&&!b[mp[now][i]])return;
	dfs(now+1,cost);
	return;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,&typ);
	if(typ[0]=='A'){
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		for(int i=1;i<n;i++)
			scanf("%d%d",&u,&v);
		while(m--){
			memset(f,0,sizeof(f));
			scanf("%d%d%d%d",&u,&x,&v,&y);
			for(int i=1;i<=n;i++){
				f[i][0]=f[i-1][1];
				f[i][1]=min(f[i-1][1],f[i-1][0])+p[i];
				if(u==i)
					x?f[i][0]=INF:f[i][1]=INF;
				if(v==i)
					y?f[i][0]=INF:f[i][1]=INF;
			}
			if(f[n][0]>=INF&&f[n][1]>=INF)f[n][0]=-1;
			printf("%d\n",min(f[n][0],f[n][1]));
		}
	}else{
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			mp[u][++mp[u][0]]=v;
			mp[v][++mp[v][0]]=u;
		}
		while(m--){
			scanf("%d%d%d%d",&u,&x,&v,&y);
			memset(b,0,sizeof(b));
			ans=INF;
			dfs(1,0);
			printf("%d\n",(ans==INF)?-1:ans);
		}
	}
}