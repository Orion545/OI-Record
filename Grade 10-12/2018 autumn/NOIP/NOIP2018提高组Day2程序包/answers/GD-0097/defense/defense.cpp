#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int head[200002],fir,a,b,c,v[100001],vis[100001],poi;
char gg[5];
struct node{
	int to,nxt;
}e[200002];
void add(int x,int y)
{
	fir++;
	e[fir].to=y;
	e[fir].nxt=head[x];
	head[x]=fir;
}
int find(int x,int ti)
{
	poi++;if(poi==a) return 0;
	int tot=1000000;
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int hh=e[i].to;
		if(vis[hh]) continue;
		if(ti)
		{
			tot=min(tot,find(hh,1)+v[hh]);
			tot=min(tot,find(hh,0));
		}
		if(!ti) tot=find(hh,1)+v[hh];
	}
	if(tot==1000000)	return 0;
	else return tot;
}
int fin(int x,int y)
{
	vis[x]=vis[y]=1;
	int tot=100000,sum=100000;
	for(int i=head[x];i;i=e[i].nxt)
	{
		memset(vis,0,sizeof(vis));
		tot=min(find(e[i].to,1)+v[e[i].to],tot);
	}
	for(int i=head[y];i;i=e[i].nxt)
	{
		memset(vis,0,sizeof(vis));
		sum=min(find(e[i].to,1)+v[e[i].to],sum);
	}
	return sum+tot;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>a>>b;cin>>gg;
	for(int i=1;i<=a;i++) cin>>v[i];
	for(int i=1;i<=a;i++)
	{
		int x,y;cin>>x>>y;add(x,y);add(y,x);
	}
	
	if(gg[1]==2)
	{
		for(int i=1;i<=b;i++)
		{	
			poi=0;
			memset(vis,0,sizeof(vis));
			int x,y,z,w;cin>>x>>z>>y>>w;
			if(z==w&&z==1) cout<<"-1"<<endl;
			if(z==1) cout<<find(x,1)<<endl;
			if(w==1) cout<<find(y,1)<<endl;
			if(z==w&&z==0) 
			{
				cout<<fin(x,y)<<endl;
			}
		}
		return 0;		
	}
	return 0;
}
