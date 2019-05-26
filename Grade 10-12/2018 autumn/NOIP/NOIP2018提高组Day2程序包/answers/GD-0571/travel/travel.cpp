#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m,n,a[5100][5100],x,y,sz[5100],stac[5100],inde=0,QAQ,linshi[5100],qwq;
bool bj[5100];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(sz,0,sizeof(sz));
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		sz[x]++;
		sz[y]++;
		a[x][sz[x]]=y;
		a[y][sz[y]]=x;
	}
	int now=1;
	memset(bj,true,sizeof(bj));
	printf("1 ");
	for(int i=1; i<=n; i++) sort(a[i]+1,a[i]+sz[i]+1);
	if(m==n-1)
	while(true)
	{
		int p=now;
		qwq=0;
		bj[now]=false;
		bool bjj=true;
		for(int i=1; i<=sz[p]; i++)
		{
			if(bj[a[p][i]])
			{
				if(!bjj)
				{
					qwq++;
					linshi[qwq]=a[p][i];
				}
				if(bjj)	
				{
					printf("%d ",a[p][i]);
					now=a[p][i];
					bjj=false;
				}
			}
		}
		while(qwq)
		{
			inde++;
			stac[inde]=linshi[qwq];
			qwq--;
		}
		if(bjj)
		{
			while(!bj[stac[inde]]) inde--;
			now=stac[inde];
			inde--;
			if(inde<0) return 0;
			printf("%d ",now);
		}
	}
}
