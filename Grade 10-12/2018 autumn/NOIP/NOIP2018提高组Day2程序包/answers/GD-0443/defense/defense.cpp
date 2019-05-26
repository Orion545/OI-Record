#include<bits/stdc++.h>
using namespace std;
long long typedef LL;
const int MAXN=1e5+5;
const LL inf=1ll<<60;
int n,q,cur;
int Head[MAXN],A[MAXN];
char S[5];
LL f[MAXN][5];
struct wyy
{
	int to,next;
}Edge[MAXN*2];
void Add(int from,int to)
{
	Edge[++cur].to=to;
	Edge[cur].next=Head[from];
	Head[from]=cur;
	
	Edge[++cur].to=from;
	Edge[cur].next=Head[to];
	Head[to]=cur;
}
void Read()
{
	scanf("%d%d%s",&n,&q,S+1);
	for(int i=1;i<=n;i++)	scanf("%d",&A[i]);
	memset(Head,-1,sizeof(Head));
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y);//double
	}
}
void Dfs(int x,int fa,int a,int aType,int b,int bType)
{
	LL sum0=0,sum1=0;
	for(int h=Head[x];h!=-1;h=Edge[h].next)
	{
		int y=Edge[h].to;LL now=inf;
		if(y==fa)	continue;
		
		Dfs(y,x,a,aType,b,bType);
		
		if(sum0!=-1)
		{
			if(f[y][1]==-1)	sum0=-1;
			else	sum0+=f[y][1];
		}
		if(sum1!=-1)
		{
			if(f[y][0]!=-1)	now=f[y][0];
			if(f[y][1]!=-1)	now=min(now,f[y][1]);
			if(now==inf)	sum1=-1;
			else	sum1+=now;
		}
	}
	if((x==a&&aType==1)||(x==b&&bType==1)||sum0==-1)	f[x][0]=-1;
	else	f[x][0]=sum0;
	if((x==a&&aType==0)||(x==b&&bType==0)||sum1==-1)	f[x][1]=-1;
	else	f[x][1]=sum1+A[x];
}
void CalcSim()
{
	for(int i=1;i<=q;i++)
	{
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		Dfs(a,0,a,x,b,y);		
		printf("%lld\n",f[a][x]);
	}
}
void CalcDif()
{
	//if(S[1]=='A'&&S[2]=='1')	
//	{
		Dfs(1,0,1,1,1,1);
		for(int i=1;i<=q;i++)	
		{
			int a,x,b,y;
			scanf("%d%d%d%d",&a,&x,&b,&y);
			printf("%lld\n",f[a][x]);
		}		
	//}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	Read();	
	if(n<=2000)	CalcSim();
	else	CalcDif();
	return 0;
}
