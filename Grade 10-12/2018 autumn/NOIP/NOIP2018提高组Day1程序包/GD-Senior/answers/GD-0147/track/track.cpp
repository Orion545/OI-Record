#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cnt=1;
int to[100000];
int head[100000];
int next[100000];
int w[100000];
int a,b,c;
int deep[100000];
int numbye[100000];
int numbson[100000];
int ye[100][100];
int what[100][100];
int maxn=-999;
int road[100][100];
int n,m;
int f[100000];
int s[100000];
int fir,second;
int bit[100000];
int tp1,tp2,tp3;
int add(int u,int v,int t)
{
	to[cnt]=v;
	w[cnt]=t;
	next[cnt]=head[u];
	head[u]=cnt++;
	to[cnt]=u;
	w[cnt]=t;
	next[cnt]=head[v];
	head[v]=cnt++;
	return 0;
}
int build(int son,int fa)
{
	deep[son]=deep[fa]+1;
	numbye[deep[son]]++;
	ye[deep[son]][numbye[deep[son]]]=son;
	if(deep[son]>=maxn)
	maxn=deep[son];
	for(int i=head[son];i;i=next[i])
	{
		int y=to[i];
		if(y==fa)
		continue;
		numbson[son]++;
		what[son][numbson[son]]=y;
		road[son][y]=w[i];
		build(y,son);
	}
	return 0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)
	{
		cin>>a>>b>>c;
		add(a,b,c);
	}
	build(1,0);
	for(int i=maxn;i>=1;i--)
	{
		 tp1=numbye[i];
		for(int j=1;j<=tp1;j++)
		{
			 tp2=ye[tp1][j];
			 fir=0;
			 second=0;
			for(int k=1;k<=numbson[tp2];k++)
			{
				tp3=what[tp2][k];	 
				if(road[tp2][tp3]+f[tp3]>=fir)
				fir=road[tp2][tp3]+f[tp3];
			}
				for(int k=1;k<=numbson[tp2];k++)
			{
				tp3=what[tp2][k];
			if(road[tp2][tp3]+f[tp3]>=second&&road[tp2][tp3]+f[tp3]!=fir)
				second=road[tp2][tp3]+f[tp3];
			}
			f[tp2]=fir;
			s[tp2]=second;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		bit[i]=f[i]+s[i];
	}
	sort(bit+1,bit+n+1);
	cout<<bit[n];
	return 0;
}
