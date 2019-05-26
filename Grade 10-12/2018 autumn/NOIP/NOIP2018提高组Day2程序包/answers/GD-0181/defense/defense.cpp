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
const int N=1e5+10;
struct node {
	int x,y,next;
}a[2*N];int len,last[N];LL c[N],f[N][2];char st[N];int d1,xd,d2,yd;
void ins(int x,int y){a[++len].x=x;a[len].y=y;a[len].next=last[x];last[x]=len;}
void pre(int x,int fa) {
	f[x][0]=0;f[x][1]=c[x];
	if(x==d1 && xd==1)f[x][0]=c[x];if(x==d2 && yd==1)f[x][0]=c[x];
	if(x==d1 && xd==0)f[x][1]=0;if(x==d2 && yd==0)f[x][1]=0;
	for(int k=last[x];k;k=a[k].next) {
		int y=a[k].y;if(y==fa)continue;
		pre(y,x);
		f[x][0]=f[y][1];
		f[x][1]+=min(f[y][0],f[y][1]);
		if((y==d1 && xd==0) || (y==d2 && yd==0))f[x][0]=f[x][1];
	}
}int mp[2010][2010];
LL F[N][2];//处理了前i个点 第i个点选/不选的最优解 
int main() {
	freopen("defense.in","r",stdin);freopen("defense.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);scanf("%s",st+1);
	for(int i=1;i<=n;++i)qreadl(c[i]);
	for(int i=1;i<n;++i) {
		int x,y;qread(x);qread(y);
		ins(x,y);ins(y,x);mp[x][y]=mp[y][x]=1;
	}
	if(st[1]=='A') {
		while(m--) {
			int x,xd,y,yd;qread(x);qread(xd);qread(y);qread(yd);
			memset(F,63,sizeof(F));F[1][0]=0;F[1][1]=c[1];
			if(x==1 && xd==1)F[1][0]=c[1];if(y==1 && yd==1)F[1][0]=c[1];
			if(x==y+1 || y==x+1){puts("-1");continue;}
			for(int i=2;i<=n;++i) {
				if(x==i && xd==1)F[i][0]=F[i][1]=min(F[i-1][0],F[i-1][1])+c[i];
				else if(y==i && yd==1)F[i][0]=F[i][1]=min(F[i-1][0],F[i-1][1])+c[i];
				else if(x==i && xd==0)F[i][0]=F[i][1]=F[i-1][1];
				else if(y==i && yd==0)F[i][0]=F[i][1]=F[i-1][1];
				else {
					if((x==i-1 && xd==0) || (y==i-1 && yd==0))F[i][0]=F[i][1]=F[i-1][1]+c[i];
					F[i][0]=F[i-1][1];
					F[i][1]=min(F[i-1][1],F[i-1][0])+c[i];
				}
			}printf("%lld\n",min(F[n][1],F[n][0]));
		}
	}
	else {
		while(m--) {
			qread(d1);qread(xd);qread(d2);qread(yd);
			if(mp[d1][d2]==1 && d1==0 && d2==0){puts("-1");continue;}
			pre(1,0);
			printf("%lld\n",min(f[1][0],f[1][1]));
		}
	}
	return 0;
}
