#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(i=a;i<=b;++i)
using namespace std;
typedef long long ll;
const int N=3e5+5;
const ll inf=1e14+7;
int n,m,i,x,y,l1,l2,nx[N<<1],he[N],we[N<<1],tot,p[N];
ll f[N][2];   char st[N];
int read(){
	int sum=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') {
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
void add(int x,int y){
	nx[++tot]=he[x],he[x]=tot,we[tot]=y;
}
void dfs(int x,int fr){
	int i;
	for(i=he[x];i;i=nx[i])
	  if (we[i]!=fr){
	  	int y=we[i];
	  	dfs(y,x);
	  	if (f[x][0]!=inf) {
	  		  if (f[y][1]!=inf) f[x][0]+=f[y][1]; else f[x][0]=inf; 
	  	}
	  	if (f[x][1]!=inf) {
	  		  if (f[y][0]==inf&&f[y][1]==inf) f[x][1]=inf;
	  		    else f[x][1]+=min(f[y][1],f[y][0]);
	  	}
	  }
	  if (f[x][1]!=inf) f[x][1]+=p[x];
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",st);
	fo(i,1,n) p[i]=read();
	fo(i,2,n){
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	if ((n<=2000&&m<=2000)||(st[0]=='B')){
		while (m--){
			x=read(),l1=read(),y=read(),l2=read();
			fo(i,1,n) f[i][0]=f[i][1]=0;
			if (l1) f[x][0]=inf; else f[x][1]=inf;
			if (l2) f[y][0]=inf; else f[y][1]=inf;
			dfs(1,0);
			if (f[1][0]==inf&&f[1][1]==inf) printf("-1\n");
			  else printf("%lld\n",min(f[1][0],f[1][1]));
		}
		return 0;
	}
}
