#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=5e3+2;
vector<int> lj[N];
bool ed[N],cir[N],zd=0,hs=0;
int n,i,j,m,x,y,c,bs,st[N],tp,zx,l,r;
inline void read(int &x)
{
	c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
inline void add(int x,int y)
{
	lj[x].push_back(y);
	lj[y].push_back(x);
}
void findcir(int x,int y)
{
	ed[x]=1;
	st[++tp]=x;
	int i;
	for (i=0;i<lj[x].size();i++) if (lj[x][i]!=y)
	{
		if (ed[lj[x][i]])
		{
			while (st[tp+1]!=lj[x][i]) cir[st[tp--]]=1;
			zd=1;
			return;
		}
		else
		{
			findcir(lj[x][i],x);
			if (zd) return;
		}
	}
	--tp;
}
void sol(int x)
{
	printf("%d ",x);
	ed[x]=1;
	int i;
	for (i=0;i<lj[x].size();i++) if (!ed[lj[x][i]]) sol(lj[x][i]);
}
void dfs(int x,int y)
{
	printf("%d ",x);
	int i,j;
	if (cir[x])
	{
		if ((zx<lj[x][0])||(lj[x].size()>1)&&(lj[x][0]==y)&&(zx<lj[x][1]))
		for (i=0;i<lj[x].size();i++) if ((lj[x][i]!=y)&&(cir[lj[x][i]])) j=lj[x][i];
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n);read(m);
	for (i=1;i<=m;i++)
	{
		read(x);read(y);
		add(x,y);
	}
	for (i=1;i<=n;i++) lj[i].push_back(int(2e9));
	for (i=1;i<=n;i++) sort(&lj[i][0],&lj[i][lj[i].size()-1]);
	for (i=1;i<=n;i++) lj[i].pop_back();
	if (m<n)
	{
		sol(1);
		return 0;
	}
	if (m==n) findcir(1,1);
	for (i=1;i<=n;i++) if (!cir[i])
	{
		for (j=1;j<=n;j++) printf("%d ",j);return 0;
	}
	l=lj[1][0];r=lj[1][1];
	if (l>r) swap(l,r);
	memset(ed,false,sizeof(ed));
	printf("1 ");ed[1]=1;
	for (i=2;i<=n;i++)
	{
		printf("%d ",l);
		ed[l]=1;
		if (ed[lj[l][0]]) swap(lj[l][0],lj[l][1]);
		if (lj[l][0]<=r) l=lj[l][0]; else
		{
			while (1)
			{
				printf("%d ",r);
				ed[r]=1;
				if (ed[lj[r][0]]) swap(lj[r][0],lj[r][1]);
				if (ed[lj[r][0]]) break;
				r=lj[r][0];
			}
			return 0;
		}
	}
}