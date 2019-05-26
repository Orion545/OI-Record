#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,x,y,a[5005][5005],ans[5005],b[5005],vis[5005],cn[5005],fa[5005];
bool flag;
inline void dfs(int x,int cnt){
	//printf("%d\n",cnt);
	if (cnt==n){
		//for (int i=1;i<=n;++i) printf("%d ",b[i]);
		//printf("ss \n");
		flag=false;
		
		for (int i=1;i<=n;++i) {
			if (ans[i]>b[i]) {flag=true;break;}
			if (ans[i]<b[i]) {flag=false;break;}
		}
	//	printf("fl %d\n",flag);
		if (flag) for (int i=1;i<=n;++i) ans[i]=b[i];
		return;
	}
	for (int i=1;i<=cn[x];++i){
		if (!vis[a[x][i]]){
			
			if (a[x][i]<=ans[cnt+1]){
				vis[a[x][i]]=1;
				if (!fa[a[x][i]]) fa[a[x][i]]=x;	
				b[cnt+1]=a[x][i];
				//printf("%d\n",a[x][i]);
				dfs(a[x][i],cnt+1);
				fa[a[x][i]]=0;
				vis[a[x][i]]=0;
			}
			
		}
	}
	if (x!=1) dfs(fa[x],cnt);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		a[x][++cn[x]]=y;
		a[y][++cn[y]]=x;
	}
	//printf("sss\n");
	for (int i=1;i<=n;++i) sort(a[i]+1,a[i]+cn[i]+1);
	for (int i=1;i<=n;++i) ans[i]=999999999;
	b[1]=1;
	vis[1]=1;
	dfs(1,1);
	for (int i=1;i<=n;++i) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
