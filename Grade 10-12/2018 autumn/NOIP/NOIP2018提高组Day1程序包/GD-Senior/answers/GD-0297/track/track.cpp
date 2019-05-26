#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,x,y,z,L,R,M,tot,len,d[100000],pnt,gx[100000],Le[100000],Ri[100000],l,r,q[100000],rt,fa[100000],GX[100000],dis[100000];
vector<int> f[100000],g[100000];
bool k1,k2,v[100000],u[100000];

void dfs(int k)
{
	for(int i=0;i<f[k].size();i++)if(!v[f[k][i]])
	{
		v[f[k][i]]=true;
		dis[f[k][i]]=dis[k]+g[k][i];
		dfs(f[k][i]);
	}
}

int main()
{
	k1=true;
	k2=true;
	ios::sync_with_stdio(false);
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y>>z;
		if(x!=1)k1=false;
		if(y!=x+1)k2=false;
		f[x].push_back(y);
		g[x].push_back(z);
		f[y].push_back(x);
		g[y].push_back(z);
	}
	if(m==1)
	{
		v[1]=true;
		dfs(1);
		int ppp=1;
		for(int i=1;i<=n;i++)if(dis[i]>dis[ppp])ppp=i;
		for(int i=1;i<=n;i++)dis[i]=0;
		for(int i=1;i<=n;i++)v[i]=false;
		v[ppp]=true;
		dfs(ppp);
		for(int i=1;i<=n;i++)if(dis[i]>dis[ppp])ppp=i;
		printf("%d\n",dis[ppp]);
	}

		else if(k1)
		{
			L=1;
			R=1000000000;
			while(L<R)
			{	
			M=(L+R)/2+1;
			//printf("kzzl\n");
			
			tot=0;
			for(int i=2;i<=n;i++)d[i]=g[i][0];
			sort(d+2,d+1+n);
			pnt=2;
			for(int i=n;i>=2;i--)
			{
				if(d[i]>=M)tot++;
				if(i<=pnt)break;
				else 
				{
					while(d[pnt]+d[i]<M)
					{
						pnt++;
						if(pnt>=i-1)break;
					}
					if(d[pnt]+d[i]>=M)tot++;
				}
			}
			if(tot>=m)L=M;
			else R=M-1;
			}
			cout<<L<<"\n";
		}
		
		else if(k2)
		{
			L=1;
			R=1000000000;
			while(L<R)
			{	
			M=(L+R)/2+1;
			//printf("kzzl\n");
			
			for(int i=1;i<n;i++)for(int j=0;j<f[i].size();j++)if(f[i][j]==i+1)d[i]=g[i][j];
			tot=0;
			len=0;
			for(int i=1;i<n;i++)
			{
				len+=d[i];
				if(len>=M)
				{
					tot++;
					len=0;
				}
			}
			if(tot>=m)L=M;
			else R=M-1;
			}
			cout<<L<<"\n";
		}
		
		else printf("IG niubi\n");

}
