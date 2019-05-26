#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,i,j,x,y,used;
int l[10005],next[10005],last[5005],tot;
int c[5005],z[5005],in[5005];
int bz[5005];
int to[5005][5005];
int bzz[500005];

void link(int x,int y)
{
	tot++;
	l[tot]=y;
	next[tot]=last[x];
	last[x]=tot;
}

void dg(int x,int xx)
{
	for (int i=last[x];i>=1;i=next[i])
	{
		if (c[0]!=0) return;
		if ((l[i]!=xx))
		{
			if (bz[l[i]]==1)
			{
				for (int j=z[0];j>=1;j--)
				{
					c[++c[0]]=z[j];
					in[c[c[0]]]=c[0];
					if (z[j]==l[i]) return;
				}
			}
			else
			{
				z[++z[0]]=l[i];
				bz[l[i]]=1;
				dg(l[i],x);
			}
		}
	}
	z[0]--;
}

void find(int x)
{
	printf("%d ",x);
	for (int i=last[x];i>=1;i=next[i])
	{
		if (bz[l[i]]!=1)
		{
			to[x][++to[x][0]]=l[i];
		}
	}
	sort(to[x]+1,to[x]+1+to[x][0]);
	for (int i=1;i<=to[x][0];i++)
	{
		bz[to[x][i]]=1;
		find(to[x][i]);
	}
}

int pd(int x)
{
	int mi=99999;
	for (int i=last[x];i>=1;i=next[i])
	{
		if (bz[l[i]]==0) mi=min(mi,l[i]);
	}
	return mi;
}

void findd(int x)
{
	int y,xx;
//	printf("%d ",x);
	for (int i=last[x];i>=1;i=next[i])
	{
		if (bz[l[i]]!=1)
		{
			to[x][++to[x][0]]=l[i];
		}
	}
	sort(to[x]+1,to[x]+1+to[x][0]);
	
	if ((in[x]>=1)&&(used==0)&&(x!=z[z[0]]))
	{
		y=n+1;
		if (bz[c[in[x]+1]]==1)
		for (int i=in[x]+1;i<=z[0];i++)
		{
			if (bz[c[i]]==1)
			{
				if (pd(c[i])<y)
				{
					y=min(y,pd(c[i]));
					xx=c[i];
					break;
				}
			}
		}
		if (bz[c[in[x]-1]]==1)
		for (int i=in[x]-1;i>=1;i--)
		{
			if (bz[c[i]]==1)
			{
				if (pd(c[i])<y)
				{
					y=min(y,pd(c[i]));
					xx=c[i];
					break;
				}
			}
		}
		if (y!=n+1)
		{
			if ((to[x][0]==0)||(y<to[x][1]))
			{
				used=1;
				findd(xx);
				findd(z[z[0]]);
				return;
			}
		}
	}
	
	for (int i=1;i<=to[x][0];i++)
	{
		if (bz[to[x][i]]==1) continue;
		bz[to[x][i]]=1;
		printf("%d ",to[x][i]);
		findd(to[x][i]);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		link(x,y);
		link(y,x);
	}
	
	if (m==n-1)
	{
		bz[1]=1;
		find(1);
		return 0;
	}
	if (m==n)
	{
		bz[1]=1;
		z[1]=1;
		z[0]=1;
		dg(1,0);
		memset(bz,0,sizeof(bz));
		printf("1 ");
		bz[1]=1;
		findd(1);
		return 0;
	}
}
