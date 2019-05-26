#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i) 
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define max(q,w) ((q)<(w)?(w):(q))
#define min(q,w) ((q)<(w)?(q):(w))
using namespace std;
const int N=100500;
int read(int &n)
{
	int w=1;n=0;
	char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return n=n*w;
}
int n,m,K,ans;
int a[N];
int B[N*2][3],A[N],B0;
int f[N],g[N];
int d[N];
int z[N],TI;
void link(int q,int w,int e)
{
	B[++B0][0]=A[q],A[q]=B0,B[B0][1]=w,B[B0][2]=e;
	B[++B0][0]=A[w],A[w]=B0,B[B0][1]=q,B[B0][2]=e;
}
bool PX(int q,int w){return g[q]<g[w];}
void dfs(int q,int fa,int LI)
{
	f[q]=g[q]=0;
	efo(i,q)if(B[i][1]!=fa)dfs(B[i][1],q,LI),g[B[i][1]]+=B[i][2],f[q]+=f[B[i][1]];
	d[0]=0;
	efo(i,q)if(B[i][1]!=fa)d[++d[0]]=B[i][1];
	sort(d+1,d+1+d[0],PX);
	for(;d[0]&&g[d[d[0]]]>=LI;++f[q],--d[0]);
	int w=-1,j=1;
	++TI;
	fod(i,d[0],1)
	{
		if(i==j)w=i;
		if(i<=j)break;
		for(;i>j&&g[d[j]]+g[d[i]]<LI;++j);
		if(i>j)++f[q],z[d[j]]=z[d[i]]=TI,++j;
		else w=i;
	}
	if(w>0)
	{
		if(g[d[w-1]]+g[d[w]]>=LI)
		{
//			g[q]=g[d[d[0]]];
//			printf("%d\n",q);
			j=w-1;
			fo(i,w,d[0])
			{
				if(i==d[0]||g[d[i]]+g[d[j]]<LI)
				{
					g[q]=g[d[i]];break;
				}else --j;
			}
		}else g[q]=g[d[w]];
	}else
	{
		fod(i,d[0],1)if(z[d[i]]<TI)
		{
			g[q]=g[d[i]];break;
		}
	}
}
int Doit(int t)
{
	dfs(1,0,t);
	return f[1];
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int q,w,e,sum=0;
	read(n),read(K);
	fo(i,1,n-1)read(q),read(w),sum+=read(e),link(q,w,e);
	int l=0,r=sum;
//	printf("%d\n",Doit(6));return 0;
	for(;l<r;)
	{
		int mid=(l+r+1)>>1;
		if(Doit(mid)>=K)l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}
