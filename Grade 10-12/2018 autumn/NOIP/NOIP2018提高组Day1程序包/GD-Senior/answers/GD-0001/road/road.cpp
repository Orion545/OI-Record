#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,d[100007],rmq[100007][23],head[100007],cnt,l[100007],r[100007],lg[100007];

struct EDGE
{
	int to,last;
}e[400007];

inline void add(const int& u,const int& v)
{
	e[cnt].to=v;
	e[cnt].last=head[u];
	head[u]=cnt++;
}

inline int RMQ(const int& l,const int& r)
{
	int k=lg[r-l+1]-1;
	return min(rmq[l][k],rmq[r-(1 << k)+1][k]);
}

inline int DFS_GET_ANS(int L,int R,int m,int p)
{
	if(L>R) return 0;
	if(r[L]==R && l[R]==L) return m-p;
	int right=R,ex=m-p;
	for(int i=head[m];i!=-1;i=e[i].last)
	{
		if(e[i].to>=L && e[i].to<=R) 
		{
			ex+=DFS_GET_ANS(e[i].to+1,right,RMQ(e[i].to+1,right),m);
			right=e[i].to-1;
		}
	}
	return ex+DFS_GET_ANS(L,right,RMQ(L,right),m);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]); add(d[i],i); rmq[i][0]=d[i];
	}
	for(int i=1,x=-1;i<=n;i++)
	{
		if(d[i]!=x) {l[i]=i; x=d[i];}
		else l[i]=l[i-1];
	}
	for(int i=n,x=-1;i>=1;i--)
	{
		if(d[i]!=x) {r[i]=i; x=d[i];}
		else r[i]=r[i+1];
	}
	for(int j=1;(1 << j)<=n;j++) for(int i=1;i<=n;i++)
	{
		rmq[i][j]=min(rmq[i][j-1],rmq[i+(1 << (j-1))][j-1]);
	}
	printf("%d",DFS_GET_ANS(1,n,RMQ(1,n),0));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//6 4 3 2 5 3 5
