#include<cstdio>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fd(i,r,l) for(int i=r;i>=l;i--)
#define link(x,y) e[++tot]=y,nt[tot]=fi[x],fi[x]=tot
#define F(x) for(int i=fi[x];i;i=nt[i])
using namespace std;
const int N=1e5+5,M=2*N;
int e[M],nt[M],fi[N],tot;
int n,m,A,X,B,Y;
int p[N],f[N],g[N];
char s1,s2,sp;
int min(int x,int y){
	if(x==-1) return y;
	if(y==-1) return x;
	return x<y?x:y;
}
int dfs(int x,int fa){
	F(x){
		int y=e[i];if(y==fa) continue;
		int xx=dfs(y,x);
		if(xx==-1) return -1;
		if(g[y]==-1) f[x]+=(f[x]>-1)?f[y]:0,g[x]+=(g[x]>-1)?f[y]:0;
		else if(f[y]==-1) f[x]+=(f[x]>-1)?g[y]:0,g[x]=-1;
		else f[x]+=f[x]>-1?min(f[y],g[y]):0,g[x]+=g[x]>-1?f[y]:0;
	}
	f[x]+=f[x]>-1?p[x]:0;
	if(f[x]==-1 && g[x]==-1) return -1;
	return min(f[x],g[x]);
}
void gc(){
	int x,y;
	fo(i,1,n-1) scanf("%d%d",&x,&y),link(x,y),link(y,x);
	fo(i,1,m){
		fo(i,1,n) f[i]=g[i]=0;
		scanf("%d%d%d%d",&A,&X,&B,&Y);
		if(X==1) g[A]=-1;else f[A]=-1;
		if(Y==1) g[B]=-1;else f[B]=-1;
		printf("%d\n",dfs(1,1));
	}
}
void gc1(){
	
}
void gc2(){
	
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%c%c%c\n",&n,&m,&sp,&s1,&s2);
	fo(i,1,n) scanf("%d",&p[i]);
	if(n<=2000 && m<=2000) gc();
	else if(s1=='A') gc1();
	else if(s2=='1') gc2();
}
