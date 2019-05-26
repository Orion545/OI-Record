#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define inf 2147483647
using namespace std;
int n,m,x,y,a,b,p[N],t[N*2],nx[N*2],l[N],f[N][2];
void add(int x,int y){
	t[++t[0]]=y;
	nx[t[0]]=l[x];
	l[x]=t[0];
}
void dp(int x,int y){
	if(f[x][1]!=inf) f[x][1]=p[x];
	for(int k=l[x];k;k=nx[k]){
		if(t[k]!=y){
			dp(t[k],x);
			if(f[x][1]!=inf){
				if(f[t[k]][1]==inf&&f[t[k]][0]==inf) f[x][1]=inf;
				else f[x][1]+=min(f[t[k]][1],f[t[k]][0]);
			}
			if(f[x][0]!=inf){
				if(f[t[k]][1]!=inf){
					f[x][0]+=f[t[k]][1];
				}
				else f[x][0]=inf;
			}
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	char ch=getchar();
	while(ch!='\n') ch=getchar();
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&x,&a,&y,&b);
		memset(f,0,sizeof(f));
		f[x][1-a]=f[y][1-b]=inf;
		dp(1,0);
		if(f[1][1]!=inf&&f[1][0]!=inf) printf("%d\n",min(f[1][1],f[1][0]));
		else if(f[1][1]!=inf&&f[1][1]>0) printf("%d\n",f[1][1]);
		else if(f[1][0]!=inf&&f[1][0]>0) printf("%d\n",f[1][0]);
		else printf("-1\n");
	}
	return 0;
}
