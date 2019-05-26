#include<iostream>
#include<sstream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
int n,m, pf[50001],pe[100001],pn[100001],pw[100001],pd,ans;
inline void dfs(int p,int f,int now,int ann)
{
	ans=max(ans,ann);
	for(int x=pf[p];x;x=pn[x])
	    if(pe[x]!=f)
	        dfs(pe[x],p,now+1,ann+pw[x]);
	return;
}
using namespace std;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int x=1,s,e,w;x<n;++x)
	{
		scanf("%d%d%d",&s,&e,&w);
		pn[x]=pf[s];
		pe[pf[s]=x]=e;
		pw[x]=pw[x+n]=w;
		pn[x+n]=pf[e];
		pe[pf[e]=x+n]=s;
		if(s!=1&&e!=1)
		    pd=1;
	}
	if(!pd)
	{
		sort(pw+1,pw+n,greater<int>());
		for(int x=1;x<=m;++x)
		    ans+=pw[x];
	}
	else if(m==1)
		for(int x=1;x<=n;++x)
		    dfs(x,0,0,0);
	printf("%d",ans);
	return 0;
}
