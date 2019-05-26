#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#define Maxn 50010
#define Maxl 400000
#define Maxans 2100000000
using namespace std;
int n,m,sp,ep;
int res[Maxn],fth[Maxn],fp[Maxn],f[Maxn],top; char vis[Maxn];
int lns[Maxl],sln[Maxn],next[Maxl],wv[Maxl],lnc=0; char use[Maxl];
void buildline (int x,int y,int z,int ins) {
	lns[++lnc]=y; next[lnc]=sln[x]; sln[x]=lnc; wv[lnc]=z; use[lnc]=ins;
}
void spfa () {
	memset(vis, 0, sizeof(vis));
	memset(res, -1, sizeof(res));
	for(int i=0;i<=n+1;i++) fth[i]=i;
	vis[sp]=1; f[1]=sp; top=1; res[sp]=0;
	for(int i=1,p=f[1];i<=top;vis[i]=0,i++,p=f[i])
	    if (p!=ep)
		    for(int j=sln[p],q=lns[sln[p]];j;j=next[j],q=lns[j])
		        if (use[j] && q!=0 && fth[p]!=q)
		    	    if (res[p]+wv[j]>res[q]) {
		    	    	res[q]=res[p]+wv[j], fth[q]=p, fp[q]=j;
		    	    	if (!vis[q]) vis[q]=1, f[++top]=q;
		    	    }
}
int main ()
{
	freopen("track.in", "r", stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	memset(sln, 0, sizeof(sln));
	for(int i=1,x,y,z;i<n;i++)
	    scanf("%d%d%d", &x, &y, &z),
	    buildline(x,y,z,1), buildline(y,x,z,1);
	for(int i=1;i<=n;i++)
	    buildline(0,i,0,1), buildline(i,0,0,0),
	    buildline(i,n+1,0,1), buildline(n+1,i,0,0);
	sp=0; ep=n+1; int ans=Maxans;
	for(int i=1;i<=m;i++) {
		spfa ();
		for(int j=ep,x=fp[ep];j;j=fth[j],x=fp[j])
			use[x]=0, use[(x%2)?(x+1):(x-1)]=1;
		ans = res[ep]<ans ? res[ep] : ans;
	}
	printf("%d", ans);
	return 0;
}
