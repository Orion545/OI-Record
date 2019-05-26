#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>q;
	for (int i=1;i<=n;i++) scanf("%d",&v[i]);
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&a,&b);
		if (a>b) swap(a,b);
		w[a]=b;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(z,-1,sizeof(z));
		memset(e,-1,sizeof(e));
		z[a]=x;
		z[b]=y;
		for (int i=1;i<=n;i++)
		{
			if (z[i]==1)
		 {
		 	ans+=v[i];
		 	e[i]=1;
		 } 
		 if (e[i]) continue;
		 if (z[i]==0&&!w[i])
		 {
		 	ans+=w[i];
		 	e[w[i]]=1;
		 }
		}
		 
	}
	cout<<ans;
	return 0;
}
