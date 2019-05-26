#include<cstring>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<cstdio>
using namespace std;

namespace mine
{
	typedef long long ll;
	
	const int MAX_N=110000;
	int z[MAX_N];
	
	int hou[MAX_N];
	struct Edge{int y,g;}e[MAX_N*2];
	int ln=0;void ins(int x,int y) {e[++ln]=(Edge){y,hou[x]};hou[x]=ln;}
	
	ll f[MAX_N][2],oth[MAX_N][2],g[MAX_N];
	ll allg[MAX_N],allf1[MAX_N];
	void add(ll &x,ll y)
	{
		x+=y;
		x=min(x,f[0][0]);
	}
	void dec(ll &x,ll y)
	{
		if(x<f[0][0])
		{
			x-=y;
			if(y>=f[0][0]) x=f[0][0];
		}
	}
	int ff[MAX_N];
	
	int a1=0,a2,b1=0,b2;
	void solve3(int x,int fa)
	{
		ff[x]=fa;
		
		f[x][0]=0;f[x][1]=z[x];
		for(int k=hou[x];k>0;k=e[k].g)
		{
			int y=e[k].y;if(y==fa) continue;
			solve3(y,x);
			
			g[y]=min(f[y][0],f[y][1]);
			add(f[x][0],f[y][1]);
			add(f[x][1],g[y]);
			
			add(allg[x],g[y]);
			add(allf1[x],f[y][1]);
		}
		if(x==a1) f[x][a2^1]=f[0][0];
		if(x==b1) f[x][b2^1]=f[0][0];
	}
	void output(ll x)
	{
		//printf("%I64d\n",x);
		printf("%lld\n",x);
	}
	void solveoth(int x,int fa)
	{
		oth[x][0]=oth[fa][1];
		add(oth[x][0],z[fa]);
		add(oth[x][0],allg[fa]);
		dec(oth[x][0],g[x]);
		
		oth[x][1]=oth[fa][0];
		add(oth[x][1],allf1[fa]);
		dec(oth[x][1],f[x][1]);
		
		//if(x==4) output(oth[x][0]);
		oth[x][1]=min(oth[x][1],oth[x][0]);
		
		for(int k=hou[x];k>0;k=e[k].g) if(e[k].y!=fa) solveoth(e[k].y,x);
	}
	void main()
	{
		freopen("defense.in","r",stdin);
		freopen("defense.out","w",stdout);

		int n,m;char type[10];
		scanf("%d%d%s",&n,&m,type);
		for(int i=1;i<=n;i++) scanf("%d",&z[i]);
		for(int i=1;i<=n-1;i++)
		{
			int x,y;scanf("%d%d",&x,&y);
			ins(x,y);ins(y,x);
		}
		
		if(type[1]=='3')//nm
		{
			for(int i=1;i<=m;i++)
			{
				scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
				memset(f,63,sizeof f);
				solve3(1,0);
				ll ans=min(f[1][0],f[1][1]);
				if(ans==f[0][0]) puts("-1");
				else output(ans);
			}
		}
		else
		{
			memset(f,63,sizeof f);
			solve3(1,0);
			memset(oth,63,sizeof oth);
			allg[0]=g[1];
			allf1[0]=f[1][1];
			
			if(type[1]=='2')//n
			{
				oth[0][0]=oth[0][1]=0;
				solveoth(1,0);
				
				while(m--)
				{
					scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
					if(ff[a1]==b1) swap(a1,b1),swap(a2,b2);
					
					ll ans;
					if(a2==0 and b2==0) ans=-1;
					else if(a2==0 and b2==1)
					{
						ans=oth[a1][0];
						add(ans,allg[a1]);
						//ans=oth[a1][0]+allg[b1];
					}
					else if(a2==1 and b2==0)
					{
						ans=oth[a1][1];
						add(ans,z[a1]);
						add(ans,allg[a1]);
						dec(ans,g[a2]);
						add(ans,f[a2][0]);
					}
					else
					{
						ans=oth[a1][1];
						add(ans,z[a1]);
						add(ans,allg[a1]);
						dec(ans,g[a2]);
						add(ans,f[a2][1]);
					}
					
					if(ans>=f[0][0]) ans=-1;
					output(ans);
				}
			}
			else//n
			{
				oth[0][0]=0;
				oth[0][1]=f[0][0];
				solveoth(1,0);
				
				while(m--)
				{
					scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
					ll ans=oth[b1][b2];
					//output(ans);
					
					add(ans,f[b1][b2]);
					if(ans>=f[0][0]) puts("-1");
					else output(ans);
				}
			}
		}
	}
}

int main()
{
	srand(time(0));
	mine::main();
}
