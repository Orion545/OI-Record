#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct V{int to;int next;}e[1000000];
int head[100005],cur,n,m,w[100005],ans;
bool f[100005];
string type;
bool pd()
{
	for (int i=1;i<=n;i++)
	 if (!f[i] && (!f[i-1] && !f[i+1])) return false;
	return true; 
}
void add(int a,int b)
{
	e[cur].to=b;
	e[cur].next=head[a];
	head[a]=cur++;
}
void work(int p,int a,int x,int b,int y)
{
	int s=0;
	memset(f,false,sizeof(f));
	for (int i=1;i<=n;i++)
	if (p & (1<<(i-1)))
	{
		if ((i==a && x==0) || (i==b && y==0)) return ;
		s+=w[i];
		f[i]=true;
	}else if ((i==a && x==1) || (i==b && y==1)) return ;
	if (pd()) ans=min(ans,s);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;
	memset(head,-1,sizeof(head));
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	if (type[0]=='A' && n<=20)
	{
		for (;m>0;m--)
		{
			int a,x,b,y;
			scanf("%d%d%d%d",&a,&x,&b,&y);
			ans=2147483647;
			for (int i=0;i<(1<<n);i++)
			{
				work(i,a,x,b,y);
			}
			if (ans!=2147483647) printf("%d\n",ans);else printf("-1\n");
		}
	}
	return 0;
}
