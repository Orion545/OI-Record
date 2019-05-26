#include<bits/stdc++.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define max(a,b) (a>b?a:b)
using namespace std;
inline int read(){
	int n=0,f=1;char c;
	for(c=getchar();c!='-'&&(c<'0'||c>'9');c=getchar());
	if (c=='-') c=getchar(),f=-1;
	for(;c>='0'&&c<='9';c=getchar()) n=n*10+c-48;
	return n*f;
}
const int maxn=1e5+5;
int i,j,n,m,k[maxn],ne[maxn],g[maxn],c[maxn],num,l,r,X,ans,mx[maxn];
int son[maxn],cnt;bool bz[maxn];
void add(int x,int y,int z){
	ne[++num]=k[x],k[x]=num,g[num]=y,c[num]=z;
}
int work(){
	int s=0;
	for(int i=cnt,j=1;j<i;i--){
		if (bz[i]) i--;
		for(;bz[j]||(j<i&&son[i]+son[j]<X);j++);
		if (j<i) s++,j++;else break;
	}return s;
}
void dfs(int x,int fa){
	for(int i=k[x];i;i=ne[i])if (g[i]!=fa) dfs(g[i],x);
	if (ans>=m) return;
	cnt=0;
	for(int i=k[x];i;i=ne[i]){
		int y=g[i];
		if (y==fa) continue;
		son[++cnt]=mx[y]+c[i];
		if (son[cnt]>=X) cnt--,ans++;
	}
	sort(son+1,son+1+cnt);
	int t,T=work(),l,r,mid;
	for(l=0,r=cnt;l<r;){
		mid=(l+r+1)>>1;
		bz[mid]=1,t=work(),bz[mid]=0;
		if (t==T) l=mid;else r=mid-1;
	}ans+=T,mx[x]=son[l];
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	fo(i,1,n-1){
		int x=read(),y=read(),z=read();
		add(x,y,z),add(y,x,z),r+=z;
	}
	for(l=0,r/=m;l<r;){
		X=(l+r+1)>>1,ans=0;
		dfs(1,0);
		if (ans>=m) l=X;else r=X-1;
	}
	printf("%d\n",l);
	return 0;
}
