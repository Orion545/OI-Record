#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int n,m,cur,Son[MAXN][MAXN];
int Head[MAXN],Num[MAXN];
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
	scanf("%d%d",&n,&m);
	memset(Head,-1,sizeof(Head));
	for(int i=1;i<=m;i++)	
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y);
	}
}
void Dfs(int x,int fa)
{
	printf("%d ",x);
	for(int h=Head[x];h!=-1;h=Edge[h].next)
	{
		int y=Edge[h].to;
		if(y==fa)	continue;
		Son[x][++Num[x]]=y;
	}
	sort(Son[x]+1,Son[x]+1+Num[x]);
	for(int i=1;i<=Num[x];i++)
	{
		int y=Son[x][i];
		Dfs(y,x);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ÏÈÂëÊ÷¡£
	Read();
	if(m==n-1)	Dfs(1,0);
	//else	CalcCir(); 
	return 0;
}
