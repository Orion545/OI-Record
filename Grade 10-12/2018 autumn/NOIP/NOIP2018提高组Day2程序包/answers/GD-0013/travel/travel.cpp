#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define Maxn 6000
#define Maxm 12000
using namespace std;
int n,m;
int h[Maxn],top=0;
int ans[Maxn]; char vis[Maxn];
int lns[Maxm],sln[Maxn],next[Maxm],lnc=0;
void buildline (int x,int y) {
	lns[++lnc]=y; next[lnc]=sln[x]; sln[x]=lnc;
}
void up (int r) {
	int aim=r>>1;
	if (aim==0) return;
	if (h[aim]<h[r]) return ;
	int ex=h[r]; h[r]=h[aim]; h[aim]=ex;
	up (aim);
}
void down (int r) {
	int aim=r<<1;
	if (aim>top) return ;
	if (aim<top)
	    if (h[aim]>h[aim+1]) aim++;
	if (h[aim]>h[r]) return ;
	int ex=h[r]; h[r]=h[aim]; h[aim]=ex;
	down (aim);
}
void dij () {
	memset(vis, 0 ,sizeof(vis));
	h[1]=1; top=1;
	for(int i=1;i<=n;i++) {
		int p=h[1];
		while(top>0 && vis[p])
		    h[1]=h[top], top--, down(1), p=h[1];
		ans[i]=p; vis[p]=1;
		for(int j=sln[p];j;j=next[j])
		    if (!vis[lns[j]])
		        h[++top]=lns[j], up (top);
	}
}
int main ()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	memset(sln, 0, sizeof(sln));
	for(int i=1,x,y;i<=m;i++)
	    scanf("%d%d", &x, &y),
	    buildline(x,y), buildline(y,x);
	dij ();
	for(int i=1;i<=n;i++)
	    printf("%d ", ans[i]);
	return 0;
}
