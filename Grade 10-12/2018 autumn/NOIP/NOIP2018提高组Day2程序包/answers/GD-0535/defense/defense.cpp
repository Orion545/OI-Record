#include<bits\stdc++.h>
#define INF 1LL<<9;
using namespace std;
int f[200000][2],a[200002],yy[200002],next[200002],h[200002],tot,n,m;
string s;
void build(int l,int r)
{
	yy[++tot]=r;
	next[tot]=h[l];
	h[l]=tot;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=n-1;j++)
	{
		int x,y;
		cin>>x>>y;
		build(x,y);
		build(y,x);
	}
	while(m--)
	{
		int x,y,l,r;
		cin>>x>>y>>l>>r;
		if (s=="A3"||s=="A2"||s=="A1")
		{
			memset(f,0X3f3f3f3f,sizeof(f));
			if (1==x)
				{
					if (y==1) 
					{
						f[1][1]=a[1],f[1][0]=INF;
					}
					else f[1][0]=0,f[1][1]=INF;
				}
				else if (l==1)
				{
				if (r==1) 
					{
						f[1][1]=a[1],f[1][0]=INF;
					}
					else f[1][0]=0,f[1][1]=INF;
				}
				else
				{
					f[1][0]=0;
					f[1][1]=a[1];
				}	
			for(int j=2;j<=n;j++)
			{
				if (j==x)
				{
					if (y==1) 
					{
						f[j][1]=min(f[j-1][0],f[j-1][1]),f[j][0]=INF;
					}
					else f[j][0]=f[j-1][1],f[j][1]=INF;
				}
				else if (j==l)
				{
					if (r==1) 
					{
						f[j][1]=min(f[j-1][0],f[j-1][1]),f[j][0]=INF;
					}
					else f[j][0]=f[j-1][1],f[j][1]=INF;
				}
				else
				{
					f[j][0]=f[j-1][1];
					f[j][1]=min(f[j-1][0],f[j-1][1])+a[j];
				}	
			}
			cout<<min(f[n][0],f[n][1])<<endl;
			continue;
		}
		if (s=="B1"||s=="C1")
		{
			
		}
		if (s=="A2"||"B2")
		{
			if (y==0 && r==0)
			{
				cout<<-1<<endl;
				continue;
			}
		}
	}
}
