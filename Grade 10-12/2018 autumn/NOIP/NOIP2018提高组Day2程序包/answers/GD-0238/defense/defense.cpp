#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define max(q,w) ((q)>(w)?(q):(w))
#define min(q,w) ((q)<(w)?(q):(w))
using namespace std;
typedef long long LL;
const int N=100500;
int read(int &n)
{
	int w=1;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return n=n*w;
}
int n,m;
LL ans;
struct TR
{
	int fa,v,si,c,dfn,lt;
	LL f[4];
}a[N];
LL f[N][2];
LL Ans[4];
int dfn0,dfn[N];
int B[N*2][3],A[N],B0=1;
LL tr[N*4][4];
void link(int q,int w)
{
	B[++B0][0]=A[q],A[q]=B0,B[B0][1]=w;
	B[++B0][0]=A[w],A[w]=B0,B[B0][1]=q;
}
int dfs(int q,int fa,int qq,int q1,int w,int w1)
{
	f[q][0]=0;
	f[q][1]=a[q].v;
	efo(i,q)if(B[i][1]!=fa)
	{
		dfs(B[i][1],q,qq,q1,w,w1);
		f[q][0]+=f[B[i][1]][1];
		f[q][1]+=min(f[B[i][1]][1],f[B[i][1]][0]);
	}
	if(q==qq)f[q][!q1]=1e17;
	if(q==w)f[q][!w1]=1e17;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int q,w,q1,w1;
	read(n),read(m),read(q);
	fo(i,1,n)read(a[i].v);
	fo(i,1,n-1)read(q),read(w),link(q,w);
	fo(i,1,m)
	{
		read(q),read(q1),read(w),read(w1);
		dfs(1,0,q,q1,w,w1);
		ans=min(f[1][0],f[1][1]);
		if(ans>1e11)printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
