#include<bits\stdc++.h>
using namespace std;
bool vis[100002],nb;
int ma[100002],a[10002],maxx,n,tot,T,mid;
void lai(int x,int num)
{
	if (x==mid+1) return; 
	int tmp=0;
	while(num+ma[x]*tmp<=maxx)
	{
		vis[num+ma[x]*tmp]=1;
		lai(x+1,num+ma[x]*tmp);
		tmp++;
	}
}
void dfs(int x,int num)
{
	if (x==n+1 && num!=0) return;  
	if (num==0)
	{
		memset(vis,0,sizeof(vis));
		lai(1,0);
		bool p=0;
		for(int i=1;i<=n;i++) if (!vis[a[i]])
		{
			p=1;
			break;
		}
		if (!p) nb=1;
		return;
	} 
	ma[++tot]=a[x];
	dfs(x+1,num-1);
	tot--;
	dfs(x+1,num);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i),maxx=max(maxx,a[i]);
		int l=0,r=n+1;
		while(r-l>1)
		{
			
			mid=(l+r)/2;
			nb=0;
			dfs(1,mid);
			if (nb) r=mid;
			else l=mid;
		}
		printf("%d\n",r);
	}
}
