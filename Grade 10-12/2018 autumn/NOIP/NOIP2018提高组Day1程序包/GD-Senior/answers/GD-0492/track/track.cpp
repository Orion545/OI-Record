#include<cstdio>
using namespace std;
#define INF 0x3f3f3f3f
int dst[50002],head[50002],ePoint,line[150002],check[50002];
struct edge{
	int next,to,val;
} eEdge[100002];
void add(int from,int to,int value)
{
	eEdge[++ePoint].next=head[from];
	eEdge[ePoint].to=to;
	eEdge[ePoint].val=value;
	head[from]=ePoint;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int iA,iB,n,m,a,b,c,first=0,last=1,maxinum=0,out=0;
	scanf("%d %d",&n,&m);
	for(iA=1;iA<n;iA++)
	{
		scanf("%d %d %d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
		for(iA=1;iA<=n;iA++)
		{
			for(iB=1;iB<=n;iB++)
			{
				dst[iB]=INF;
			}
			line[0]=iA;dst[iA]=0;first=0;last=1;
			do
			{
				for(iB=head[line[first]];iB;iB=eEdge[iB].next)
				{
					int jie=eEdge[iB].to;
					if(dst[line[first]]+eEdge[iB].val<dst[jie])
					{
						dst[jie]=dst[line[first]]+eEdge[iB].val;
						if(!check[jie])
						{
							check[jie]=true;
							line[last++]=jie;
						}
					}
				}
				check[line[first++]]=false;
			}while(first<last);
			for(iB=1;iB<=n;iB++)
				maxinum=(maxinum>dst[iB])?maxinum:dst[iB];
		}
	printf("%d",maxinum);
	return 0;
}
