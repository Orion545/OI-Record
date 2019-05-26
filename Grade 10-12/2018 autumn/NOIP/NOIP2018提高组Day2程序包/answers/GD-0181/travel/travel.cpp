#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define qread(x) x=read()
#define qreadl(x) x=readl()
using namespace std;
typedef long long LL;
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
inline LL readl() {
	LL x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
const int N=5010;
struct node {
	int x,y,next;
}a[2*N];int len,last[N],du[N],mp[N][N];bool v[N],f[N][N];
void ins(int x,int y){a[++len].x=x;a[len].y=y;a[len].next=last[x];last[x]=len;}
int top,h[N],cnt,z[N],n,m;
bool tp(int x,int fa) {
	if(v[x]) {
		while(top) {
			h[++cnt]=z[top];
			if(z[top--]==x)break;
		}return true;
	}v[x]=1;z[++top]=x;
	for(int i=1;i<=du[x];++i)
		if(mp[x][i]!=fa && !f[x][mp[x][i]])
			if(tp(mp[x][i],x))
				return true;
			else v[mp[x][i]]=0,--top;
	return false;
}bool bk;int k,q[N];
void dfs(int x,int fa) {
	q[++k]=x;//f[fa][x]=f[x][fa]=1;
	for(int i=1;i<=du[x];++i) {
		int y=mp[x][i];
		if(f[x][y] || y==fa)continue;
		dfs(y,x);
	}
}int as[N],b[N][N];
bool chk() {
	for(int i=1;i<=n;++i) {
		if(q[i]>as[i])return false;
		if(q[i]<as[i])return true;
	}
}
int main() {
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	memset(du,0,sizeof(du));
	qread(n);qread(m);
	for(int i=1;i<=m;++i) {
		int x,y;qread(x);qread(y);b[x][y]=b[y][x]=1;
		ins(x,y);ins(y,x);mp[x][++du[x]]=y;mp[y][++du[y]]=x;
	}for(int i=1;i<=n;++i)sort(mp[i]+1,mp[i]+du[i]+1);
	if(!tp(1,0)) {
		k=0;dfs(1,0);
		for(int i=1;i<=n;++i)as[i]=q[i];
	}
	else {
//		for(int i=1;i<=cnt;++i)printf("%d ",h[i]);puts("");
		for(int i=1;i<=n;++i)as[i]=n+1;
		for(int i=2;i<=cnt;++i) {
			f[h[i-1]][h[i-2]]=f[h[i-2]][h[i-1]]=0;
			f[h[i]][h[i-1]]=f[h[i-1]][h[i]]=1;
			/*if(i==3) {
				memset(h,0,sizeof(h));
				memset(z,0,sizeof(z));
				memset(v,0,sizeof(v));
				top=0;cnt=0;
				bool flag=tp(1,0);
				if(flag){puts("ORZ");for(int i=1;i<=cnt;++i)printf("%d ",h[i]);puts("");return 0;}
			}*/k=0;dfs(1,0);
			if(chk())for(int i=1;i<=n;++i)as[i]=q[i];
		}
	}for(int i=1;i<=n;++i)printf("%d ",as[i]);puts("");
	return 0;
}
