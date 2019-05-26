#include<iostream>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,m,st,en,pf[5001][5001],pl[5001],pfa[5001],ans[5001],ann[5001],bj[5001],rd[5001],pd,prd, hh,hhh, bjj[5001],bjjj[5001];
inline void dfs(int p,int f,int now)
{//cout<<p<<" "<<f<<" "<<now<<"  ";for(int x=1;x<=now;++x)cout<<ann[x]<<" ";cout<<"pd="<<pd<<endl;
	pfa[p]=f;//if(!(hh==2&&hhh==84))cout<<p<<" "<<f<<" "<<now<<endl;
	if(now==n)
	{
		for(int x=1;x<=n;++x)
		    ans[x]=ann[x];//for(int x=1;x<=n;++x)cout<<ans[x]<<" ";cout<<endl;
		pd=0;//cout<<++gx<<endl;
		prd=0;
		return;
	}
	for(int x=1;x<=pl[p]&&(ans[now+1]>=pf[p][x]||pd);++x)
	    if(!bj[pf[p][x]]&&!(hh==p&&hhh==pf[p][x]||hh==pf[p][x]&&hhh==p))
	    {
	    	bj[pf[p][x]]=1;
	    	ann[now+1]=pf[p][x];
	    	prd=0;
	    	pd=max(pd,int(ans[now+1]>pf[p][x]));
	    	dfs(pf[p][x],p,now+1);
	    	bj[pf[p][x]]=0;
	    }
	if(rd[p]==1)
	    prd=1;
	if(f&&prd)
		dfs(f,pfa[f],now);
	return;
}
/*inline void dfs1(int p,int f,int now)
{//cout<<" "<<p<<" "<<now<<endl;
	for(int x=1;x<=pl[p]&&!pd;++x)
	{
		if(bjj[pf[p][x]]&&pf[p][x]!=f)
		{//cout<<pf[p][x];
			pd=1;
			bjj[pf[p][x]]=n*2;
			bjjj[p]=1;
			return;
		}
		if(!bjj[pf[p][x]])
		{
			bjj[pf[p][x]]=1;
	    dfs1(pf[p][x],p,now+1);
	    if(pd==1)
	    {
	    	bjjj[p]=1;
	    	if(bjj[p]==n*2);
	    	    pd=2;
	    	return;
	    }
	    bjj[pf[p][x]]=0;
		}
	    
	}
	return;
}*/
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);//cout<<n<<" "<<m<<endl;
	memset(ans,0x3f,sizeof ans);
	for(int x=1;x<=m;++x)
	{//cout<<x<<endl;
		scanf("%d%d",&st,&en);
		pf[st][++pl[st]]=en;
		pf[en][++pl[en]]=st;
		++rd[en];
		++rd[st];
	}
	for(int x=1;x<=n;++x)
	    sort(pf[x]+1,pf[x]+pl[x]+1);
	bj[0]=2;
	bj[1]=1;
	ans[1]=ann[1]=1;
	if(m==n-1)
	    dfs(1,0,1);
	else
	{
		//bjj[1]=1;
		//dfs1(1,0,0);//for(int x=1;x<=n;++x)cout<<bjjj[x]<<" ";cout<<endl;
		for(int x=1;x<=n;++x)
	        for(int y=x+1;y<=n;++y)
	            for(int z=1;z<=pl[x];++z)
	                if(pf[x][z]==y)
	                {//cout<<x<<" "<<y<<endl;
	                    pd=prd=0;
	                	hh=x;
	                	hhh=y;
	                	--rd[x];
	                	--rd[y];
	                	dfs(1,0,1);
	                	++rd[x];
	                	++rd[y];
	                }
	}
	for(int x=1;x<=n;++x)
	    printf("%d ",ans[x]);
	return 0;
}
