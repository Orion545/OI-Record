#include<cstdio>
#include<algorithm>
#define maxn 5500
using namespace std;
struct enode{
	int nxt,y;
	int flag;
}e[maxn*2];
int first[maxn],d[maxn],son[maxn],v[maxn];
int q[maxn];
int tot=0,tim=0,z=0,sx,sy;
void adde(int x,int y){
	e[tot].nxt=first[x];
	e[tot].y=y;
	first[x]=tot++;
}
void dfs(int x,int fa){
	if (!v[x]) d[++tim]=x,v[x]=1;
	int l=z+1;
	for (int i=first[x];i>=0;i=e[i].nxt){
		int y=e[i].y;
		if (y!=fa&&(!e[i].flag)&&(!v[y])) son[++z]=y;
	}
	int r=z;
	if (l<r) sort(son+l,son+r+1);
	for (int i=l;i<=r;i++)
	dfs(son[i],x);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	first[i]=-1,q[i]=n-i+1;
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		adde(x,y);
		adde(y,x);
	}
	if (m==n-1){
		dfs(1,0);
		for (int i=1;i<=n;i++)
		printf("%d ",d[i]);
	}else {
		for (int o=0;o<n;o++){
			e[o*2].flag=e[o*2+1].flag=1;
			for (int i=1;i<=n;i++)
			v[i]=0;
			tim=z=0;
			dfs(1,0);
			int need=0;
			for (int i=1;i<=n;i++)
				if (q[i]>d[i]) need=1;else 
				if (q[i]<d[i]) break;
			if (tim!=n) need=0;
			if (need){
				for (int i=1;i<=n;i++)
				q[i]=d[i],d[i]=0;
			}
			e[o*2].flag=e[o*2+1].flag=0;
		}
		for (int i=1;i<=n;i++)
		printf("%d ",q[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
