#include<cstdio>
#include<algorithm>

using namespace std;

struct hh1{
	int v,c,nex;
}e[60010];
struct hh{
	int u,v,c;
}edge[60010];
int head[60010];
int tot=0,n,m,sum=0;

void add(int u,int v,int c)
{
	e[++tot].v=v;
	e[tot].c=c;
	e[tot].nex=head[u];
	head[u]=tot;
}

bool cmp(hh x,hh y)
{
	return x.u<y.u;
}

bool cmp1(hh x,hh y)
{
	return x.c>y.c;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	bool check=true,check1=true;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].c);
		sum+=edge[i].c;
		if(edge[i].u>edge[i].v)
			swap(edge[i].u,edge[i].v);
		if(edge[i].u+1!=edge[i].v)
			check=false;
		if(edge[i].u!=1)
			check1=false;
		add(edge[i].u,edge[i].v,edge[i].c);
		add(edge[i].v,edge[i].u,edge[i].c);
	}
	if(check)
	{
		int ans=sum;
		sort(edge+1,edge+n+1,cmp);
		int p=0;
		for(int i=1;i<n;i++)
			if(p<=sum/m&&p+edge[i].c>=sum/m)
			{
				if(sum/m-p>p+edge[i].c-sum/m)
					ans=min(ans,p+edge[i].c);
				else
					ans=min(ans,p);
				p=0;
			}
		printf("%d\n",ans);
	}
	if(check1)
	{
		sort(edge+1,edge+n+1,cmp1);
		printf("%d\n",edge[m].c);
	}
}
