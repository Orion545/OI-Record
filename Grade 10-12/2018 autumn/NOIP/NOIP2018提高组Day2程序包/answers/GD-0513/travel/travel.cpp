#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
const int N=5005;
int n,m,za[N],flag[N],tot,a[N][N],cnt[N],ans[N],hjy,yys,u[N],v[N];
using namespace std;
void dfs(int x){
	if (x!=hjy) swap(hjy,yys);
	za[++tot]=x;
	flag[x]=1;
	for (int i=1;i<=cnt[x];i++) 
	 if (!flag[a[x][i]]&&(hjy!=x||yys!=a[x][i])) dfs(a[x][i]);
}

bool cmp(int a,int b){
	return a<b;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		a[u[i]][++cnt[u[i]]]=v[i];
		a[v[i]][++cnt[v[i]]]=u[i];
	}
	for (int i=1;i<=n;i++)	sort(a[i]+1,a[i]+cnt[i]+1,cmp);
	ans[1]=123456;
	dfs(1);
	for (int i=1;i<=n;i++) ans[i]=za[i];
	for (int i=1;i<=m;i++){
		hjy=u[i],yys=v[i];
		tot=0;
		memset(flag,0,sizeof(flag));
		dfs(1);
		if (tot==n){
			bool la=0;
			for (int i=1;i<=n;i++) 
			 if (ans[i]>za[i]) la=1;
			 else if (ans[i]<za[i]) break;
			if (la) for (int i=1;i<=n;i++) ans[i]=za[i];
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
