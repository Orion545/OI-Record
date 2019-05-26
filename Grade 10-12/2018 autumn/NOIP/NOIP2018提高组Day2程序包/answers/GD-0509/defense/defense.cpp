#include<bits/stdc++.h>
using namespace std;
int t1,t2,q,a,b,x,y,w[100010],dep[100010];
long long ji[100010],ou[100010]
int n,m,f[100010];
char c;
struct nw
{
	int s,n;
}nx[200020];
int u[100010],h[100010],ct;
void add(int x,int v)
{
	u[x]++;
	nx[++ct].s=v;
	nx[ct].n=h[x];
	h[x]=ct;
}
void dfs(int x)
{
	if(dep[x]%2)ji[x]+=w[x];
	else ou[x]+=w[x];
	for(int i=h[x];i;i=nx[i].n)
		if(nx[i].s!=f[x])
		{
			f[nx[i].s]=x;
			dep[nx[i].s]=dep[x]+1;
			dfs(f[nx[i].s]);
			if(dep[x]%2)ji[x]+=ji[nx[i].s];
			else ou[x]+=ou[nx[i].s];
		}
}
int main()
{
	freopen("defense.in","r".stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(c<'A'||c>'C')c=getchar();
	t1=c-'A'+1;c=getchar();
	t2=c-'0';
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dep[1]=1;
	dfs(1);
	while(m--)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(x==y==0&&(f[a]==b||f[b]==a))
		{
			printf("-1\n");
			continue;
		}
	}
}
