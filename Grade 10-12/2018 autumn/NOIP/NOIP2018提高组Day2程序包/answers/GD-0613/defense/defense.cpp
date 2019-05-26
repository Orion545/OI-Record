#include<cstdio>
#include<iostream>

using namespace std;

#define N 100005

int n,m,i,j,l,r,ztl,ztr,typ,cou;
int first[N],next[N],a[N],ri[N],gt[N];
long long f[N][2],ans;

void read(int &x)
{
	char c=getchar();
	x=0;
	while (c<'0'||c>'9')
	{
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}

void add(int l,int r)
{
	cou++;
	next[cou]=first[l]; first[l]=cou;
	ri[cou]=r;
}

void dfs(int now,int fa)
{
	if (ri[first[now]]==fa&&next[first[now]]==0)
	{
		f[now][0]=0;
		f[now][1]=a[now];
		if (gt[now]==1) f[now][1]=1e10+5;
		if (gt[now]==2) f[now][0]=1e10+5;
		return;
	}
	int i;
	for (i=first[now]; i>0; i=next[i])
	{
		if (ri[i]!=fa)
		{
			dfs(ri[i],now);
			f[now][1]+=std::min(f[ri[i]][0],f[ri[i]][1]);
			f[now][0]+=f[ri[i]][1];
		}
	}
	f[now][1]+=a[now];
	if (gt[now]==1) f[now][1]=1e10+5;
	if (gt[now]==2) f[now][0]=1e10+5;
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(n); read(m); read(typ);
	for (i=1; i<=n; i++) read(a[i]);
	for (i=1; i<n; i++)
	{
		read(l); read(r);
		add(l,r);
		add(r,l);
	}
	for (i=1; i<=m; i++)
	{
		read(l); read(ztl);
		read(r); read(ztr);
		gt[l]=ztl+1; gt[r]=ztr+1;
		memset(f,0,sizeof(f));
		dfs(1,0);
		gt[l]=0; gt[r]=0;
		ans=std::min(f[1][0],f[1][1]);
		if (ans>1e10) printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
