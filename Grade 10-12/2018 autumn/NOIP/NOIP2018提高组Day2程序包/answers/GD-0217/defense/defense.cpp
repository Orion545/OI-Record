#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define rg register
#define N 200010
using namespace std;
int n,m,tot,type,last[N],f[N][2],val[N],t[N];
bool link[2010][2010];
struct edge{
	int to,pre;
}e[N<<1];
inline int read(){
	int k=0,f=1; char c=getchar();
	while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while('0'<=c&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
void dfs(int x,int fa){
	f[x][1]=val[x]; f[x][0]=0;
	if(t[x]==1) f[x][0]=2e9;
	if(t[x]==-1) f[x][1]=2e9;
	for(rg int i=last[x],to;i;i=e[i].pre)if((to=e[i].to)!=fa){
		dfs(to,x); 
		f[x][1]+=min(f[to][0],f[to][1]);
		f[x][0]+=f[to][1]; 
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(); m=read(); 
	char c=getchar(); while(c!='A'&&c!='B'&&c!='C') c=getchar(); type=read();
	for(rg int i=1;i<=n;i++) val[i]=read();
	for(rg int i=1;i<n;i++){
		int u=read(),v=read();
		e[++tot]=(edge){u,last[v]}; last[v]=tot;
		e[++tot]=(edge){v,last[u]}; last[u]=tot;
		if(n<=2000) link[u][v]=link[v][u]=1;
	}
	if(type==1){
		dfs(1,0);
		while(m--) printf("%d\n",f[1][1]);
		return 0;
	}
	if(n<=2000){
		while(m--){
			for(rg int i=1;i<=n;i++) f[i][0]=f[i][1]=t[i]=0;
			int a=read(),x=read(),b=read(),y=read();
			if(x==1) t[a]=1; else t[a]=-1;
			if(y==1) t[b]=1; else t[b]=-1;
			if(!x&&!y&&link[a][b]){
				puts("-1");
				continue;
			}
			else{
				dfs(a,0); 
				if(x) printf("%d\n",f[a][1]);
				else printf("%d\n",f[a][0]); 
			}
		}
		return 0;
	}
	return 0;
}
