#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
inline ll lread()
{
	ll x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
const int N=5e4+10;
const int M=5e4+10;
const int INF=0x3f3f3f3f;
struct edge
{
	int x,y,c,next;
}a[M*2]; int len,last[N];
void ins(int x,int y,int c)
{
	a[++len].x=x;a[len].y=y;a[len].c=c;
	a[len].next=last[x];last[x]=len;
}
int n,m;
ll dep[N],mx,mxfr;
bool flag;
void dfs(int x,int fa,int fr)
{
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y==fa) continue;
		dep[y]=dep[x]+a[k].c;
		if(mx<dep[y])
		{
			mx=dep[y];
			if(!flag) mxfr=fr;
		}
		dfs(y,x,fr);
	}
}
struct qq
{
	int x,y,c;
}e[M];
bool cmp(qq a,qq b){return a.c<b.c;}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	len=0; memset(last,0,sizeof(last));
	bool bk=true;
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read(),c=read();
		if(x!=1) bk=false;
		e[i]=(qq){x,y,c};
	}
	if(m==1)
	{
		for(int i=1;i<n;i++)
		{
			ins(e[i].x,e[i].y,e[i].c);
			ins(e[i].y,e[i].x,e[i].c);	
		}
		dep[1]=0; mx=mxfr=0; flag=false;
		for(int k=last[1];k;k=a[k].next)
		{
			int y=a[k].y;
			dep[y]=dep[1]+a[k].c;
			dfs(y,1,y);	
		}
	//	cout<<mx<<' '<<mxfr<<endl;
		ll ans=mx; dep[1]=mx=0; flag=true;
		for(int k=last[1];k;k=a[k].next)
		{
			int y=a[k].y;
			if(y==mxfr) continue;
			dep[y]=dep[1]+a[k].c;
			dfs(y,1,y);	
		}
		
	//	cout<<mx<<endl;
		ans+=mx;
		printf("%lld\n",ans);
		return 0;	
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			ins(e[i].x,e[i].y,e[i].c);
			ins(e[i].y,e[i].x,e[i].c);	
		}
		dep[1]=0; mx=mxfr=0; flag=false;
		for(int k=last[1];k;k=a[k].next)
		{
			int y=a[k].y;
			dep[y]=dep[1]+a[k].c;
			dfs(y,1,y);	
		}
		printf("%lld\n",mx);
		return 0;
	}
	/*
	if(bk)
	{
		sort(e+1,e+n,cmp);
		int mn=INF;
		if(m<=(n-1)/2)
		{
			int tot=0;
			for(int i=1;i<=(n-1)/2;i++)
			{
				mn=min(mn,e[i].c+e[n-i+1].c);
				tot++; if(tot==m) break;
			}
		}
		else
		{
				
		}
		return 0;
	}*/
}
