#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

const int N=5005;

int n,m,c[N],a1[N],a2[N],t1,c1,tp,sta[N],bx,by;
bool ins[N];
std::vector<int> vec[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){x=x*10+ch-'0';ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void get_cir(int x,int fa)
{
	sta[++tp]=x;ins[x]=1;
	for (int i=0;i<vec[x].size();i++)
	{
		int to=vec[x][i];
		if (to==fa) continue;
		if (ins[to])
		{
			int p=tp;
			while (sta[p]!=to) c[++c1]=sta[p],p--;
			c[++c1]=to;
		}
		else get_cir(to,x);
	}
	tp--;ins[x]=0;
}

void dfs(int x,int fa)
{
	a1[++t1]=x;
	for (int i=0;i<vec[x].size();i++)
	{
		int to=vec[x][i];
		if (to==fa||to==bx&&x==by||to==by&&x==bx) continue;
		dfs(to,x);
	}
}

void upd()
{
	for (int i=1;i<=n;i++)
		if (a1[i]>a2[i]) return;
		else if (a1[i]<a2[i]) break;
	for (int i=1;i<=n;i++) a2[i]=a1[i];
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		vec[x].pb(y);vec[y].pb(x);
	}
	for (int i=1;i<=n;i++) std::sort(vec[i].begin(),vec[i].end());
	if (m==n-1)
	{
		dfs(1,0);
		for (int i=1;i<=n;i++)
			if (i<n) printf("%d ",a1[i]);
			else printf("%d\n",a1[i]);
	}
	else
	{
		get_cir(1,0);
		c[c1+1]=c[1];
		a2[1]=n+1;
		for (int i=1;i<=c1;i++)
		{
			bx=c[i],by=c[i+1];
			t1=0;dfs(1,0);
			upd();
		}
		for (int i=1;i<=n;i++)
			if (i<n) printf("%d ",a2[i]);
			else printf("%d\n",a2[i]);
	}
	return 0;
}
