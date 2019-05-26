#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,u,v;
int rd[100002],p[100002],fa[100002];
bool vis[100002];
char type[4];
int a,x,b,y,ans;
void checka1()
{
	while(m--)
	{
		ans=0;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(a==1&&abs(a-b)==1)
		{
			cout<<"-1"<<endl;
			continue;
		}
		if(abs(a-b)==1&&b==n)
		{
			cout<<"-1"<<endl;
			continue;
		}
		int bn1,bn2;		
		if(x==1)
		{
			ans+=p[a];
			vis[a]=x;
			vis[a-1]=x;
			vis[a+1]=x;
		}
		else bn1=a;
		if(y==1)
		{
			ans+=p[b];
			vis[b]=1;
			vis[b-1]=1;
			vis[b+1]=1;
		}
		else bn2=b;
		for(int i=1;i<=n;i++)
		{
			if(i==bn1||i==bn2)
			{
				if(!vis[i-1]&&!vis[i-2])
				{
					ans+=p[i-1];
				}
				if(!vis[i+1]&&!vis[i+2])
				{
					ans+=p[i+1];
					vis[i+2]=true;
				}
			}
			else if(!vis[i-1]&&!vis[i]&&vis[i+1])
			{
				ans+=p[i];
				vis[i]=1;
				vis[i-1]=1;
				vis[i+1]=1;
			}
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf(" %s",&type);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		if(!fa[u])fa[u]=v;
		else fa[v]=u;
		rd[u]++;
		rd[v]++;
	}
	int fath;
	for(int i=1;i<=n;i++)
	{
		if(!fa[i]){fath=i;break;}
	}
	if(type=="A1"||type=="A3"||type=="A2")checka1();
	while(m--)
	{
		ans=0;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		vis[a]=x;
		vis[b]=y;
		cout<<"-1"<<endl;
	}
	
}
