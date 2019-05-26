#include<cstdio>
using namespace std;

#define INF 0x3f3f3f3f

bool check[5002];
int head[5002],line[5002],map[5002][5002],from[5002],p;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n,a,b,iA,iB,iC,i,mini,cun,cun2;
	scanf("%d %d",&n,&m);
	for(iA=1;iA<=m;iA++)
	{
		scanf("%d %d",&a,&b);
		map[a][++map[a][0]]=b;
		map[b][++map[b][0]]=a;
	}
	check[1]=true;
	line[0]=1;
	for(iA=1;iA<=n;iA++) from[iA]=iA;
	for(i=1;i<n;i++)
	{
		mini=INF;
		for(iA=0;iA<=p;iA++)
		{
			for(iB=1;iB<=map[line[iA]][0];iB++)
				if(!check[map[line[iA]][iB]] && mini>line[iA]-map[line[iA]][iB])
				{
					mini=line[iA]-map[line[iA]][iB];
					cun=map[line[iA]][iB];
					cun2=line[iA];
				}
		}
		from[from[cun]]=from[cun2];
		for(iA=1;iA<=n;iA++)
			if(from[iA]!=from[from[iA]])from[iA]=from[from[iA]];
		line[++p]=cun;
		check[cun]=true;
	}
	for(iA=0;iA<n;iA++)
		printf("%d ",line[iA]);
	return 0;
}
