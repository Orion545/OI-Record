#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<set>
using namespace std;

namespace mine
{
	typedef long long ll;
	
	const int MAX_N=51000;
	int hou[MAX_N];
	struct Edge{int y,c,g;}e[MAX_N*2];
	int ln=0;void ins(int x,int y,int c) {e[++ln]=(Edge){y,c,hou[x]};hou[x]=ln;}
	
	int f[MAX_N];//num
	ll g[MAX_N];//mxlen 
	
	ll mid;
	multiset<ll> now[MAX_N];//O(n)
	void dp(int x,int fa)
	{
		now[x].clear();
		f[x]=0;
		for(int k=hou[x];k>0;k=e[k].g)
		{
			int y=e[k].y;if(y==fa) continue;
			dp(y,x);f[x]+=f[y];
			
			g[y]+=e[k].c;
			if(g[y]>=mid) f[x]++;
			else now[x].insert(g[y]);
		}
		ll mx=0;
		while(now[x].size())
		{
			multiset<ll>::iterator tmp=now[x].begin();
			//multiset<ll>::iterator tmp=--now[x].end(); error! make waste
			ll a=*tmp;now[x].erase(tmp);
			
			multiset<ll>::iterator it=now[x].lower_bound(mid-a);
			if(it==now[x].end()) mx=max(mx,a);
			else
			{
				f[x]++;
				now[x].erase(it);
			}
		}
		g[x]=mx;
		
		//if(mx>=mid) puts("error");
		//printf("x=%d %d %I64d\n",x,f[x],g[x]);
	}
	//可以不开ll
	void main()
	{
		freopen("track.in","r",stdin);
		freopen("track.out","w",stdout);
		
		memset(hou,0,sizeof hou);
		
		int n,m;scanf("%d%d",&n,&m);
		for(int i=1;i<=n-1;i++)
		{
			int x,y,c;scanf("%d%d%d",&x,&y,&c);
			ins(x,y,c);ins(y,x,c);
		}
		
		ll l=1,r=1ll<<40,ans=-1;
		while(l<=r)
		{
			mid=(l+r)/2;
			dp(1,0);
			if(f[1]>=m) ans=mid,l=mid+1;
			else r=mid-1;
		}
		
		cout<<ans;
	}
}

int main()
{
	srand(time(0));
	mine::main();
}
