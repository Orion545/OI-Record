#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define maxn 5000

using namespace std;

struct edge_type
{
	int from,to;
};
edge_type e[maxn<<1];
int head[maxn],cnt_e[maxn];

int n,m;
int u,v;

bool flag[maxn];

bool instack[maxn],sign;
int stack[maxn],first,point;
int large[maxn];

bool cmp(edge_type x,edge_type y)
{
	return (x.from<y.from||(x.from==y.from&&x.to<y.to));
}

void dfs0(int x)
{
	int i;
	
	flag[x]=true;
	
	if (n!=m) printf("%d ",x);
	large[x]=x;
	for(i=head[x];i<head[x]+cnt_e[x];i++)
	{
		if (!flag[e[i].to]&&!instack[e[i].to]) dfs0(e[i].to);
		if (large[x]<large[e[i].to]) large[x]=large[e[i].to];
	}
}

void dfs1(int x,int pre)
{
	int i;
	
	flag[x]=true;
	
	if (!sign)
	{
		stack[++stack[0]]=x;
		instack[x]=true;
	}
	
	for(i=head[x];i<head[x]+cnt_e[x];i++)
		if (!flag[e[i].to]&&!sign)
		{
			dfs1(e[i].to,x);
			if (sign) return;
		} else if (instack[e[i].to]&&e[i].to!=pre)
		{
			first=e[i].to;
			sign=true;
			return;
		}
	
	if (!sign)
	{
		stack[0]--;
		instack[x]=false;
	}
}

void dfs2(int x)
{
	int i;
	
	flag[x]=true;
	
	printf("%d ",x);
	for(i=head[x];i<head[x]+cnt_e[x];i++)
		if (!flag[e[i].to])
		{
			if (!instack[e[i].to]) dfs2(e[i].to);
			else if (large[e[i].to]<point) dfs2(e[i].to);
			else 
			{
				point=n+9;
				continue;
			}
		}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&e[i*2-1].from,&e[i*2-1].to);
		e[i*2].to=e[i*2-1].from;
		e[i*2].from=e[i*2-1].to;
	}
	
	sort(e+1,e+(m*2),cmp);
	for(i=1;i<=m*2;i++)
	{
		if (e[i].from!=e[i-1].from) head[e[i].from]=i;
		cnt_e[e[i].from]++;
	}
	
	memset(flag,false,sizeof(flag));
	if (m==n-1) dfs0(1);
	else 
	{
		dfs1(1,0);
		for(i=1;i<=stack[0];i++)
		{
			if (stack[i]==first) break;
			instack[stack[i]]=false;
		}
		for(j=1;i<=stack[0];j++,i++) stack[j]=stack[i];
		stack[0]=j-1;
		
		memset(flag,false,sizeof(flag));
		for(i=1;i<=stack[0];i++) dfs0(stack[i]);
		
		for(j=0,i=head[first];i<head[first]+cnt_e[first];i++)
		{
			if (instack[e[i].to]) j++;
			if (j==2) break;
		}
		point=e[i].to;
		
		memset(flag,false,sizeof(flag));
		dfs2(1);
	}
	return 0;
}
