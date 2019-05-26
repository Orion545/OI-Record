#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int maxn=50010;
int n,m,cur,ans,num,star;
int M1[maxn],M2[maxn],head[maxn],kL[maxn],in[maxn];
struct adj
{
	int obj,L,next;
}e[2*maxn];

void addedge(int x,int y,int L)
{
	cur++;
	e[cur].obj=y;
	e[cur].L=L;
	e[cur].next=head[x];
	head[x]=cur;
}

void dfs(int k,int dad)
{
	for (int i=head[k];i!=-1;i=e[i].next)
	{
		int to=e[i].obj,L=e[i].L;
		if (to!=dad)
		{
			dfs(to,k);
			if (M1[to]+L>M1[k]) {M2[k]=M1[k];M1[k]=M1[to]+L;}
			else if (M1[to]+L>M2[k]) M2[k]=M1[to]+L;
		}
	}
	ans=max(ans,M1[k]+M2[k]);
}

void made1() {dfs(1,1);}

void Dfs(int k,int dad,int nL,int t)
{
	if (nL>=t) {num++;nL=0;}
	for (int i=head[k];i!=-1;i=e[i].next)
	{
		int to=e[i].obj,L=e[i].L;
		if (to!=dad) Dfs(to,k,nL+L,t);
	}
}

bool check(int k)
{
	num=0;
	Dfs(star,star,0,k);
	if (num>=m) return true;else return false;
}

void made2()
{
	
	for (int i=1;i<=n;i++) if (in[i]==1) star=i;
	int L=0,R=5e8;
	while (L+1<R)
	{
		int mid=(L+R)/2;
		if (check(mid)) L=mid;
			else R=mid;
	}
	ans=L;
}

bool okay(int k)
{
	int tail=n-1,now=0;
	for (int i=n-m*2;i<=n-1;i++)
	{
		if (kL[i]+kL[tail]>=k) {now++;tail--;}
		else break;
	}
	return now>=m;
}

void made3()
{
	sort(kL+1,kL+n);
	int L=0,R=5e8;
	while (L+1<R)
	{
		int mid=(L+R)/2;
		if (okay(mid)) L=mid;
			else R=mid;
	}
	ans=L;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	bool ok1=true,ok2=true,ok3=true;
	for (int i=1;i<=n;i++) head[i]=-1;
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d%d",&x,&y,&kL[i]);
		in[x]++;in[y]++;
		if (x!=1) ok3=false;
		addedge(x,y,kL[i]);addedge(y,x,kL[i]);
	}
	
	if (m==1) made1();
	else if (ok3) made3();
	else made2();
	
	printf("%d\n",ans);
	
	return 0;
}
