#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a,b,head[100005],vis[50005],fir,tt[50005],tot,las[50005],ru[5005],tw,g[5];
struct node{
	int to,nxt;
}e[100005];
void add(int x,int y)
{
	fir++;
	e[fir].to=y;
	e[fir].nxt=head[x];
	head[x]=fir;
}
void find(int x)
{
	tot++;tt[tot]=x;
	vis[x]=1;
	if(tot==a) return ;
	int mn=10000,mmn=100000;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(vis[v]==0)
		{
			mn=min(mn,v);las[mn]=x;
		}
	}
	int ff=0;
	if(g[1]==mn||g[2]==mn) ff=1;
	if(mn!=10000&&ff==0) {find(mn);return ;}
	int s=x;
	while(mn==10000)
	{
		s=las[s];
		for(int j=head[s];j;j=e[j].nxt)
		{
			int v=e[j].to;
			if(vis[v]==0)
			{
				mn=min(mn,e[j].to);las[e[j].to]=s;
			}	
		}			
	}
	if(ff==1) 
	{
		for(int i=1;i<tot;i++)
		for(int j=head[tt[i]];j;j=e[j].nxt)
		{
			if(vis[e[j].to]==0) mn=min(e[j].to,mn);
		}
	}
	find(mn);
	return ;
}
void findd(int x)
{
	tot++;tt[tot]=x;
	vis[x]=1;
	if(tot==a) return ;
	int mn=10000,mmn=100000;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(vis[v]==0)
		mn=min(mn,v);
	}
	for(int i=1;i<tot;i++)
	{
		int yy=tt[i];
		for(int j=head[yy];j;j=e[j].nxt)
		{
			int v=e[j].to;
			if(vis[v]==0)
			mn=min(mn,e[j].to);
		}
	}
	findd(mn);
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b;fir=0;
	for(int i=1;i<=a;i++) ru[i]=vis[i]=tt[i]=0;
	for(int i=1;i<=b;i++)
	{
		int x,y;cin>>x>>y;ru[x]++;ru[y]++;
		if(ru[x]==3) {tw++;g[tw]=x;}
		if(ru[y]==3) {tw++;g[tw]=y;}
		add(x,y);add(y,x);
	}
	for(int i=1;i<=a;i++) vis[i]=tt[i]=0;
	tot=0;
	int mm=10000,mmm=100000;
	if(b==a-1)
	{
		find(1);
		for(int i=1;i<tot;i++) cout<<tt[i]<<" ";
		cout<<tt[tot]<<endl;
		return 0;		
	}
	if(b==a)
	{
		findd(1);
		for(int i=1;i<tot;i++) cout<<tt[i]<<" ";
		cout<<tt[tot]<<endl;
		return 0;
	}
	return 0;
}
