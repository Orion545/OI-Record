#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,x,y,nh,p,pp,num,numc;
int h[5005],b[5005],c[5005][5005],v[5005],vc[5005];
vector <int> a[5005];

void Finda(int x)
{
	h[++nh]=x;
	int k=nh;
	while (h[k]<h[k/2]&&k>1)
	 {
	 	swap(h[k],h[k/2]);
	 	k/=2;
	 }
}

void Findd(int x)
{
	h[x]=h[nh--];
	int i=0;
	while (2*x<=nh)
	 {
	 	if (2*x==nh||h[2*x]<h[2*x+1]) i=2*x;
	 	 else i=2*x+1;
	 	if (h[x]>h[i]) {swap(h[x],h[i]);x=i;}else return;
	 }
}

void dfs(int x)
{
	v[x]=1;
	b[++num]=x;
	int r=a[x].size();
	for (int i=0;i<r;i++)
	 {
	 	if (!v[a[x][i]])
	 	 {
	 	 	Finda(a[x][i]);
		 }
	 }
	while (nh) 
	 {
	 	y=h[1];
		Findd(1);
		c[x][++c[x][0]]=y;
	 }
	for (int i=1;i<=c[x][0];i++)
	 dfs(c[x][i]);
}

void Find(int x,int u)
{
	v[x]=1;
	int r=a[x].size();
	for (int i=0;i<r;i++)
	 {
	 	if (!v[a[x][i]]) Find(a[x][i],x);
	 	 else if (a[x][i]!=u) {p=a[x][i];vc[x]=1;return;}
		if (p&&!pp) {vc[x]=1;if (p==x) pp=1;return;}
	 }
}

int main()
{freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	 {
	 	scanf("%d%d",&x,&y);
	 	a[x].push_back(y);
	 	a[y].push_back(x);
	 }
	//Find(1,1);
	memset(v,0,sizeof(v));
	dfs(1);
	for (int i=1;i<=num;i++)
	 {
	 	printf("%d ",b[i]);
	 }
	return 0;
}
