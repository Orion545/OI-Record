#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=50010;
int n,m,a,b,l[N],h[N],cnt=0,dep[1001],f[1001][15],w[1001][15],v[1001];
bool pf1=1,pf2=1;
struct emm{
	int from,to,dis;
}qwq[N*2];

bool cmp(int a,int b){return a>b;}

int read()
{
	char c=getchar();int x=0,f=1;
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}

void add(int from,int to,int dis)
{
	qwq[++cnt].from=h[from];
	qwq[cnt].to=to;qwq[cnt].dis=dis;
	h[from]=cnt;
}

void dfs(int x,int fa,int dst)
{
	v[x]=1;f[x][0]=fa;w[x][0]=dst;dep[x]=dep[fa]+1;
	for(int i=h[x];i;i=qwq[i].from)
	{
		int y=qwq[i].to;
		if(v[y]||y==fa)continue;
		dfs(y,x,qwq[i].dis);
	}
}

int lca(int x,int y)
{
	if(dep[x]>dep[y])swap(x,y);
	int ans=0;
	for(int i=10;i>=0;i--)
	if(dep[f[y][i]]>=dep[x]){ans+=w[y][i];y=f[y][i];}
	if(x==y)return ans;
	for(int i=10;i>=0;i--)
	if(f[x][i]!=f[y][i]){ans=ans+w[y][i]+w[x][i];x=f[x][i];y=f[y][i];}
	return ans+w[x][0]+w[y][0];
}

void emmm()
{
	int ll;
	for(int i=1;i<n;i++)
	{
		a=read();b=read();ll=read();
		if(a==b)continue;
		add(a,b,ll);add(b,a,ll);
	}
	dfs(1,0,0);
	for(int j=1;j<=10;j++)
	for(int i=1;i<=n;i++)
	{
		f[i][j]=f[f[i][j-1]][j-1];
		w[i][j]=w[i][j-1]+w[f[i][j-1]][j-1];
	}
	int q[1001],qh=0;
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)q[++qh]=lca(i,j);
	sort(q+1,q+1+qh,cmp);
	printf("%d",q[m]);
}

void pfpf()
{
	sort(l+1,l+n);
	int q[N],qh=0,st=(n-1-m)/2;
	for(int i=1;i<n;i=i+2)q[++qh]=l[i]+l[i+1];
	if(n%2==0)q[++qh]=l[n/2+1];
	sort(q+1,q+1+qh,cmp);
	printf("%d",q[m]);
}

void nmn()
{
	int s[N],d[N];
	for(int i=1;i<n;i++)s[i]=s[i-1]+l[i],d[i]=l[i];
	for(int k=2;k<=m;k++)
	for(int i=k-1;i<n;i++)
	for(int j=1;j<i;j--)d[i]=max(d[i],d[j]+s[i]-s[j]);
	printf("%d",d[n-1]);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	if(m==1){emmm();return 0;}
	for(int i=1;i<n;i++)
	{
		a=read();b=read();l[i]=read();
		add(a,b,l[i]);add(b,a,l[i]);
		if(a!=1)pf1=0;
		if(b!=a+1)pf2=0;
	}
	if(m==n-1){sort(l+1,l+n);printf("%d",l[1]);return 0;}
	if(pf1){pfpf();return 0;}
	if(pf2){nmn();return 0;}
}
