#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,z[5010],ss,dd,pd=0;
int next[10010],head[5010],to[10010],tot=0;
struct bian{
	int x;
	int y;
}b[10010];
void jb(int x,int y)
{
	next[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
}
bool cmp(bian a,bian b)
{
	if(a.x!=b.x)return a.x<b.x;
	return a.y>b.y;
}
void search(int s)
{
	z[s]=1;printf("%d ",s);
	int ls=head[s];
	while(ls!=-1)
	{
		int v=to[ls];
		if(!z[v])
		{
			if(n==m&&v>dd&&pd==0)
			{
				z[dd]=1;
				pd=1;
				search(dd);
			}
			else{
				z[v]=1;
				search(v);
			}
		}
		ls=next[ls];
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(head,-1,sizeof(head));	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i].x,&b[i].y);
		b[i+m].x=b[i].y;
		b[i+m].y=b[i].x;
	}
	sort(b+1,b+2*m+1,cmp);
	for(int i=1;i<=2*m;i++)
	{
		jb(b[i].x,b[i].y);
	}
	if(n==m)
	{
		ss=b[2].y;
		dd=b[1].y;
	}
	search(1);
}
