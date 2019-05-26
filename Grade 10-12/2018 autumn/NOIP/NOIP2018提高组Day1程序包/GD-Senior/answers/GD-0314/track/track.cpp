#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
const int N=50500;
int n,m,flag1,flag2;
struct edge{
	int x,y,c;
	edge(int x_=0,int y_=0,int c_=0)
	{
		x=x_,y=y_,c=c_;
	}
}e[N];
int to[N*2],nex[N*2],las[N],va[N*2];
bool cmp(edge a,edge b)
{
	return(a.c<b.c);
}
bool cmpa(edge a,edge b)
{
	return(a.c>b.c);
}
bool cmpx(edge a,edge b)
{
	return(a.x<b.x);
}
int all,tot;
void link(int x,int y,int v)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
	va[tot]=v;
}
int c0;
int check1(int m)
{
	int cnt=0,rt=0;
	int j=1;
	fd(i,n-1,1)
	{
		if(e[i].c>=m) ++rt;
		else
		{
			if(i<=j)break;
			while(i>=j&&e[j].c+e[i].c<m) ++j;
			if(i>j) ++rt,++j;
		}
	}
	return rt;
}
int check2(int m)
{
	int cnt=0,rt=0;
	fo(i,1,n-1)
	{
		cnt+=e[i].c;
		if(cnt>=m) ++rt,cnt=0;
	}
	return rt;
}
int dis[N],dp;
void run(int x,int f)
{
	if(dis[x]>dis[dp]) dp=x;
	for(int tp=las[x];tp;tp=tp[nex])	
	if(to[tp]!=f)
	{
		to[tp][dis]=dis[x]+va[tp];
		run(to[tp],x);
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,n-1)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		if(x>y) swap(x,y);
		e[++c0]=edge(x,y,c);
		all+=c;
		if(x!=1) flag1=1;
		if(y!=x+1) flag2=1;
	}
	all/=m;
	if(!flag2)
	{
		sort(e+1,e+1+n-1,cmpx);
		int ans=0,le=1,ri=all,mid;
		while(le<=ri)
		{
			mid=(le+ri)>>1;	
			if(check2(mid)>=m) ans=mid,le=mid+1;
			else ri=mid-1;
		}
		printf("%d\n",ans);
		return 0;	
	}
	if(!flag1)
	{
		sort(e+1,e+1+n-1,cmp);
		int ans=0,le=1,ri=all,mid;
		while(le<=ri)
		{
			mid=(le+ri)>>1;	
			if(check1(mid)>=m) ans=mid,le=mid+1;
			else ri=mid-1;
		}
		printf("%d\n",ans);
		return 0;	
	}
	if(m==1)
	{
		fo(i,1,n-1)
		{
			int x=e[i].x,y=e[i].y,c=e[i].c;
			link(x,y,c),link(y,x,c);
		}
		dis[dp=1]=0;run(1,0);
		dis[dp]=0;run(dp,0);
		printf("%d\n",dis[dp]);
		return 0;
	}
		sort(e+1,e+1+n-1,cmpa);
	printf("%d\n",e[1].c);
	return 0;	
}





