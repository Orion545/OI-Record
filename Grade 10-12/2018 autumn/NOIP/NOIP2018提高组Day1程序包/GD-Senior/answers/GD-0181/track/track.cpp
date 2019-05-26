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
const int N=50010;
struct node {
	int x,y,next;
	LL c;
}a[N*2];int len,last[N];
void ins(int x,int y,LL c) {
	a[++len].x=x;a[len].y=y;a[len].c=c;
	a[len].next=last[x];last[x]=len;
}LL dis[N],mx,p,q;
void dfs(int x,int fa) {
	for(int k=last[x];k;k=a[k].next) {
		int y=a[k].y;if(y==fa)continue;
		dis[y]=dis[x]+a[k].c;
		if(dis[y]>mx)mx=dis[y],q=y;
		dfs(y,x);
	}
}LL as=1e9;
LL d[N],s[N],f[1010][1010];
int main() {
	freopen("track.in","r",stdin);freopen("track.out","w",stdout);
	int n,m;qread(n);qread(m);
	len=0;memset(last,0,sizeof(last));
	if(m==1) {//树的直径 
		for(int i=1;i<n;++i) { 
			int x,y;qread(x);qread(y);
			LL c;qreadl(c);as=min(as,c);
			ins(x,y,c);ins(y,x,c);
		}
		memset(dis,0,sizeof(dis));mx=0;
		dis[1]=0;dfs(1,0);p=q;
		memset(dis,0,sizeof(dis));mx=0;
		dis[p]=0;dfs(p,0);printf("%lld\n",dis[q]);
	}
	else if(m==n-1) {//min最小边 
		for(int i=1;i<n;++i) {
			int x,y;qread(x);qread(y);
			LL c;qreadl(c);as=min(as,c);
		}printf("%lld\n",as);
	}
	else {
		bool flag=true,bk=true;
		for(int i=1;i<n;++i) {
			int x,y;qread(x);qread(y);
			if(y!=x+1)flag=false;if(x!=1)bk=false;
			LL c;qreadl(c);as=min(as,c);
			ins(x,y,c);ins(y,x,c);d[i]=c;
		}
		if(flag) {//在n-1个值中选出m个互不相交的区间使得最小区间和最大 
			for(int i=1;i<n;++i)s[i]=s[i-1]+d[i];
			memset(f,-63,sizeof(f));for(int i=1;i<n;++i)f[i][1]=s[i];
			for(int i=1;i<n;++i) {
				for(int j=2;j<=min(m,i);++j) {
					f[i][j]=f[i-1][j];
					for(int k=1;k<=i;++k)f[i][j]=max(f[i][j],max(min(f[i-1][j-1],d[i]),min(f[i-k][j-1],s[i]-s[i-k+1])));
				}
			}printf("%lld\n",f[n-1][m]);
		}
		else {
			memset(dis,0,sizeof(dis));mx=0;
			dis[1]=0;dfs(1,0);p=q;
			memset(dis,0,sizeof(dis));mx=0;
			dis[p]=0;dfs(p,0);printf("%lld\n",dis[q]);
		}
	}
	return 0;
}
