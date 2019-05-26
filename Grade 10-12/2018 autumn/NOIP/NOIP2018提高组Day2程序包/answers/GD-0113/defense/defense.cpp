#include<algorithm>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#define fo(i,a,b) for(i=a;i<=b;i++)
#define rep(i,x) for(i=la[x];i;i=ne[i])
#define Min(x,y) (x<y)?x:y
const int N=100005,INF=0x7fffffff;
char C;
int n,m,i,x,y,Pa,Pb,a,b,ans,sum;
int c[N],la[N],ne[N*2],da[N*2],f[N][2];
bool P,lef[N];
int read(){
	char c=getchar();int x=0;
	for(;'0'>c||'9'<c;c=getchar());
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
void ins(int x,int y){
	da[++sum]=y;ne[sum]=la[x];la[x]=sum;
	da[++sum]=x;ne[sum]=la[y];la[y]=sum;
}
void walk(int x,int fa){
	int i;
	rep(i,x)if(da[i]!=fa){walk(da[i],x);lef[x]=0;}
}
void dfs(int x,int fa){
	if(P) return;
	int i,y,m0,m1,m2;
	if(f[x][1]>=0) f[x][1]=c[x];
	if(lef[x]) f[x][0]=-1;
	rep(i,x)if(da[i]!=fa){
		y=da[i];dfs(y,x);m0=m1=INF;
		if(f[x][1]!=-1){
			if(f[y][1]>=0&&f[y][1]<m1) m1=f[y][1];
			if(f[y][0]>=0&&f[y][0]<m1) m1=f[y][0];
			if(m1<INF&&!lef[y]) f[x][1]+=m1;
			if(lef[y]&&((y==a&&Pa==1)||(y==b&&Pb==1))) f[x][1]+=m1;
		}
		if(f[x][0]!=-1){
			if(f[y][1]>=0) f[x][0]+=f[y][1];else f[x][0]=-1;
		}
	}
	if(!lef[x]&&f[x][0]==-1&&f[x][1]==-1) P=1;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	n=read(),m=read();
	for(C=getchar();'A'>C||'C'<C;C=getchar());
	x=getchar()-'0';
	fo(i,1,n) c[i]=read();
	fo(i,1,n-1){
		x=read();y=read();
		ins(x,y);
	}
	memset(lef,1,sizeof(lef));
	walk(1,0);
	fo(i,1,m){
		a=read(),Pa=read();b=read(),Pb=read();
		memset(f,0,sizeof(f));P=0;ans=INF;
		if(Pa) f[a][0]=-1;else f[a][1]=-1;
		if(Pb) f[b][0]=-1;else f[b][1]=-1;
		dfs(1,0);
		if(f[1][1]>=0&&f[1][1]<ans) ans=f[1][1];
		if(f[1][0]>=0&&f[1][0]<ans) ans=f[1][0];
		if(P||ans==INF) printf("-1\n");else printf("%d\n",ans);
	}
}
