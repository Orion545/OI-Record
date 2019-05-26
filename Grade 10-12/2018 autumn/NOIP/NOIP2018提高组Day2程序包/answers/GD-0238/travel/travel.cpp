#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define max(q,w) ((q)>(w)?(q):(w))
#define min(q,w) ((q)<(w)?(q):(w))
using namespace std;
const int N=100500;
int read(int &n)
{
	int w=1;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return n=n*w;
}
int n,m,ans;
int a[N];
int B[N*2][3],A[N],B0=1;
int Ans[N],d[N];
int hu[N];
int za[N],za1[N];
bool z[N];
void link(int q,int w)
{
//	prtinf("%d %d\n",q,w);
	B[++B0][0]=A[q],A[q]=B0,B[B0][1]=w;
	B[++B0][0]=A[w],A[w]=B0,B[B0][1]=q;
}
void tarjan(int q,int Fa)
{
	if(hu[0])return;
	z[q]=1;
	za[++za[0]]=q;za1[za[0]]=Fa;
	efo(i,q)if(!B[i][2])
	{
		B[i][2]=B[i^1][2]=1;
		if(z[B[i][1]])
		{
			hu[hu[0]=1]=B[i][1];
			for(;za[za[0]]!=B[i][1];--za[0])hu[++hu[0]]=za[za[0]];
		}else tarjan(B[i][1],i);
	}
	--za[0];
}
void dfspx()
{
	fo(q,1,n)
	{
		d[0]=0;
		efo(i,q)d[++d[0]]=-B[i][1];
		sort(d+1,d+1+d[0]);
		efo(i,q)B[i][1]=-d[d[0]],--d[0];
	}
}
int I,I1;
void dfs(int q,int fa)
{
	a[++a[0]]=q;
	efo(i,q)if(B[i][1]!=fa&&!((I==q&&B[i][1]==I1)||(I1==q&&I==B[i][1])))dfs(B[i][1],q);
}
bool OK()
{
	fo(i,1,n)if(Ans[i]!=a[i])return Ans[i]>a[i];
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int q,w;
	read(n),read(m);
	fo(i,1,m)read(q),read(w),link(q,w);
	if(m==n)
	{
		tarjan(1,0);
		dfspx();
		hu[hu[0]+1]=hu[1];
		fo(i,1,hu[0])
		{
			I=hu[i],I1=hu[i+1];
			a[0]=0;
			dfs(1,0);
			if(!Ans[0]||OK())
			{
				fo(i,0,n)Ans[i]=a[i];
			}
		}
		
	}else
	{
		dfspx();
		a[0]=0;
		dfs(1,0);
		fo(i,1,n)Ans[i]=a[i];
	}
	fo(i,1,n)printf("%d ",Ans[i]);
	printf("\n");
	return 0;
}
