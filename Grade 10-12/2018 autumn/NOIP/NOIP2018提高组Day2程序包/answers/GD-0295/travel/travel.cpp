#define prg "travel"
#include <bitset>
#include <stdio.h>
#include <algorithm>
#define rg register
#define rt return
#define vd void
#define wh while
#define br break
typedef int cv;
#define xcv rg cv
using namespace std;
#define il inline

bitset<5003> vs,qu;
bitset<5003> mp[5003];
cv ls[5003],lsp=1;



int main()
{
	freopen(prg".in","r",stdin);
	freopen(prg".out","w",stdout);
	cv m,n,u,v;
	
	scanf("%d%d",&n,&m);
	for(xcv i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		mp[u][v]=1;
		mp[v][u]=1;
	}
	ls[1]=1,vs[1]=1;
	while(lsp<n)
	{
		for(xcv i=1;i<=n;i++)
		{
			if((vs[i]==0)&&(mp[i][ls[lsp]]==1))
			{
				qu[i]=1;
				vs[i]=1;
			}
		}
		for(xcv i=1;i<=n;i++)
		{
			if(qu[i]==1)
			{
				ls[++lsp]=i;
				qu[i]=0;
				br;
			}
		}
	}
	
	
	for(xcv i=1;i<=n;i++)printf("%d%c",ls[i]," \n"[i==n]);
	rt 0;
}
