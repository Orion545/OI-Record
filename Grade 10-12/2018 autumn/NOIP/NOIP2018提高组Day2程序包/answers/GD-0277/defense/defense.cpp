#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
#define min(a,b)(a<b?a:b)
#define ll long long
using namespace std;
const int N=1e5+5,mo=1e9+7;
int n,m,c[N],la[N],ne[N*2],to[N*2],d[N],ld[N],hv[N],fa[N],js;
ll f[N][2],g[N][2];
int x,y,a,b,z;
ll an;
char ch[10];
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
void dfs(int x){
	d[x]=d[fa[x]]+1;int y;
	ff(i,x)if((y=to[i])!=fa[x]){
		fa[y]=x;
		dfs(y);
		f[x][1]+=min(f[y][0],f[y][1]);
		f[x][0]+=f[y][1];
	}
	f[x][1]+=c[x];
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);scanf("%s",ch);
	fo(i,1,n)R(c[i]);
	fo(i,2,n)R(x),R(y),link(x,y),link(y,x);
	dfs(1);
	for(;m--;){
		R(x);R(a);R(y);R(b);
		if(a){
			g[x][0]=1e18;
			g[x][1]=f[x][1];
		}else{
			g[x][0]=f[x][0];
			g[x][1]=1e18;
		}
		if(b){
			g[y][0]=1e18;
			g[y][1]=f[y][1];
		}else{
			g[y][0]=f[y][0];
			g[y][1]=1e18;
		}
		for(;x!=y;){
			if(d[x]<d[y])swap(x,y);
			if(fa[x]==fa[y]){
				z=fa[x];
				g[z][0]=f[z][0]-f[x][1]-f[y][1]+g[x][1]+g[y][1];
				g[z][1]=f[z][1]-min(f[x][0],f[x][1])+min(g[x][0],g[x][1])-min(f[y][0],f[y][1])+min(g[y][0],g[y][1]);
				x=z;y=z;
			}else
			if(fa[x]==y){
				g[y][0]+=-f[x][1]+g[x][1];
				g[y][1]+=-min(f[x][1],f[x][0])+min(g[x][1],g[x][0]);
				x=y;
			}else{
				z=fa[x];
				g[z][0]=f[z][0]-f[x][1]+g[x][1];
				g[z][1]=f[z][1]-min(f[x][0],f[x][1])+min(g[x][0],g[x][1]);
				x=z;
			}
		}
		for(;x!=1;){
			z=fa[x];
			g[z][0]=f[z][0]-f[x][1]+g[x][1];
			g[z][1]=f[z][1]-min(f[x][0],f[x][1])+min(g[x][0],g[x][1]);
			x=z;
		}
		an=min(g[1][0],g[1][1]);
		if(an>1e17)an=-1;
		printf("%lld\n",an);
	}
	fclose(stdin);fclose(stdout);return 0;
}
