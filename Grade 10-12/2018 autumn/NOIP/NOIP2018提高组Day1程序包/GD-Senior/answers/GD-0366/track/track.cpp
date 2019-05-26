#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

int n,m,x,y,nh;
int c[50005],v[50005];
struct dat{int x,s;};
dat t,h[50005];
vector <dat> a[50005];

int read()
{
	int re=0;int rep=0;char ch;
	while (!isdigit(ch=getchar())&&(ch^'-'));
	if (ch=='-') {rep=-1;ch=getchar();}else rep=1;
	while (isdigit(ch))
	 {
	 	re=(re<<3)+(re<<1)+(ch^48);
	 	ch=getchar();
	 }
	return re*rep;
}

void Finda(dat x)
{
	h[++nh]=x;
	int k=nh;
	while (h[k].s>h[k/2].s&&k>1)
	 {
	 	swap(h[k],h[k/2]);
	 	k/=2;
	 }
}

void Findd(int x)
{
	h[x]=h[nh--];
	while (2*x<=nh)
	 {
	 	int i=0;
	 	if (2*x==nh||h[2*x].s>h[2*x+1].s) i=2*x;
	 	 else i=2*x+1;
	 	if (h[x].s<h[i].s) swap(h[i],h[x]);else return;
	 }
}

void dij(int s)
{
	memset(h,0,sizeof(h));
	nh=1;t.x=s;t.s=0;h[1]=t;
	memset(c,0,sizeof(c));
	while (nh)
	 {
	 	t=h[1];
	 	Findd(1);
	 	if (v[t.x]) continue;
	 	v[t.x]=1;
	 	int r=a[t.x].size();
	 	for (int i=0;i<r;i++)
	 	 {
	 	 	y=a[t.x][i].x;
	 	 	if (c[y]<t.s+a[t.x][i].s&&!v[y])
	 	 	 {
	 	 	 	c[y]=t.s+a[t.x][i].s;
	 	 	 	dat x;
				x.x=y;
	 	 	 	x.s=c[y];
	 	 	 	Finda(x);
			 }
		 }
	 }
}

void work1()
{
	dij(1);
	int ma=0;int p=0;
	for (int i=1;i<=n;i++)
	 {
	 	if (c[i]>ma) {ma=c[i];p=i;}
	 }
	memset(v,0,sizeof(v));
	dij(p);
	ma=0;
	for (int i=1;i<=n;i++)
	 ma=max(ma,c[i]);
	cout<<ma;
}

int main()
{freopen("track.in","r",stdin);
freopen("track.out","w",stdout);
	cin>>n>>m;
	int p=0;
	for (int i=1;i<n;i++)
	 {
	 	x=read();y=read();
	 	t.s=read();
	 	t.x=y;
	 	a[x].push_back(t);
	 	t.x=x;
	 	a[y].push_back(t);
	 }
	if (m==1) work1();
	return 0;
}
