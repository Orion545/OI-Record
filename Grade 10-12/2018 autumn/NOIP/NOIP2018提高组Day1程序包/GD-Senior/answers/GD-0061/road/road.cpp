#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>

using namespace std;

inline int read()
{
	int ch=getchar(),f=1;
	int ans=0;
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-')f=0;
	for(;ch>='0'&&ch<='9';ch=getchar())
		ans=ans*10+(ch^'0');
	return f?ans:-ans;
}

const int maxn=200005;

int n;
int a[maxn];
int mn[maxn][20];
int pos[maxn][20];
int mi[maxn];
int query(int &ans,int l,int r)
{
	int len=r-l+1;
	//ans=min(mn[l][mi[len]],mn[r-(1<<mi[len])][mi[len]]);
	if(mn[l][mi[len]]<mn[r-(1<<mi[len])+1][mi[len]]||(mn[l][mi[len]]==mn[r-(1<<mi[len])+1][mi[len]]&&pos[l][mi[len]]<pos[r-(1<<mi[len])+1][mi[len]]))
	{
		ans=mn[l][mi[len]];
		return pos[l][mi[len]];
	}
	else
	{
		ans=mn[r-(1<<mi[len])+1][mi[len]];
		return pos[r-(1<<mi[len])+1][mi[len]];
	}
}
long long ans=0;
void dfs(int l,int r,int dep)
{
	if(l>r)return;
	if(l==r)
	{
		ans+=a[l]-dep;
		return;
	}
	int m;
	int ps=query(m,l,r);
	ans+=(m-dep);
	dfs(l,ps-1,m);
	dfs(ps+1,r,m);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	memset(mn,0x3f,sizeof mn);
	for(int i=1;i<=n;++i)
		mn[i][0]=a[i]=read();
	for(int i=0;i<=20&&(1<<i)<=n;++i)
		mi[(1<<i)]=i;
	for(int i=1;i<=n;++i)
		mi[i]=max(mi[i],mi[i-1]);
		//printf("%d,%d\n",i,mi[i]);
	for(int i=1;i<=n;++i)
		pos[i][0]=i;
	for(int i=1;i<=18;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(  mn[j][i-1]<mn[j+(1<<(i-1))][i-1]  ||  (mn[j][i-1]==mn[j+(1<<(i-1))][i-1]  &&  pos[j][i-1]<pos[j+(1<<(i-1))][i-1]  )  )
			{
				mn[j][i]=mn[j][i-1];
				pos[j][i]=pos[j][i-1];
			}
			else
			{
				mn[j][i]=mn[j+(1<<(i-1))][i-1];
				pos[j][i]=pos[j+(1<<(i-1))][i-1];
			}
		}
	}
	dfs(1,n,0);
	printf("%lld\n",ans);
	return 0;
}

/*


6
4 3 2 5 3 5



*/
