#include<bits/stdc++.h>
using namespace std;
long long typedef LL;
const int MAXN=5E4+5;
int n,m,cur,cnt,sum;
int Head[MAXN];
bool Vis[MAXN];
LL Dis[MAXN];
struct wyy
{
	int to,next,va;
}Edge[2*MAXN];
void Add(int from,int to,int va)
{
	Edge[++cur].to=to;
	Edge[cur].next=Head[from];
	Edge[cur].va=va;
	Head[from]=cur;
	
	Edge[++cur].to=from;
	Edge[cur].next=Head[to];
	Edge[cur].va=va;
	Head[to]=cur;
}
void Dfs(int x)
{
	Vis[x]=true;
	for(int h=Head[x];h!=-1;h=Edge[h].next)
	{
		int y=Edge[h].to;
		if(Vis[y]==true)	continue;
		Dis[y]=Dis[x]+Edge[h].va;
		Dfs(y);
	}
}
bool Check(LL len)
{
	int now=0,num=0;
	for(int i=1;i<=2*(n-1);i+=2)
	{
		now+=Edge[i].va;
		if(now>=len)	
		{
			now=0;
			num++;
		}
	}
	if(num>=m)	return true;
	else	return false;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(Head,-1,sizeof(Head));
	for(int i=1;i<n;i++)
	{
		int x,y,va;
		scanf("%d%d%d",&x,&y,&va);
		if(x==1)	cnt++;
		sum+=va;
		Add(x,y,va);//SHUANG
	}
	if(m==1)	
	{
		Dis[1]=0;Dfs(1);
		LL maxa=-1;	int id=-1;
		for(int i=1;i<=n;i++)	
		{
			if(Dis[i]>maxa)
			{
				maxa=Dis[i];
				id=i;
			}
		}
		memset(Vis,0,sizeof(Vis));//初始化 
		Dis[id]=0;Dfs(id);maxa=-1;
		for(int i=1;i<=n;i++)	maxa=max(maxa,Dis[i]);
		printf("%lld\n",maxa);
	}
	else
	{
		if(cnt==(n-1))//a[i]==1
		{
			//计算匹配个数：是否大于等于 
			
		}
		else
		{
			LL lo=0,hi=sum+1;
			while(lo+1<hi)
			{
				LL mid=(lo+hi)/2;
				if(Check(mid)==true)	lo=mid;
				else	hi=mid;	
			}
			printf("%lld\n",lo);
		}
	}
	return 0;
}
