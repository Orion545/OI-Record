#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;
const int mx=50005;
int n,m;
int hd[mx],node[mx*2],nt[mx*2],len[mx*2],fp=0;

void con(int x,int y,int z)
{
	node[fp]=y;
	nt[fp]=hd[x];
	hd[x]=fp;
	len[fp]=z;
	fp++;
}

inline int read()
{
	char ch=0;
	int w=0,x=0;
	while(!isdigit(ch)) w|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return w?-x:x;
}

int f[mx],g[mx];
int size[mx];
int t1[mx],tlen=0,del[mx];

int calcs(int x,int pos)
{
	int p=tlen-1,ans=0;
	for(int i=0;i<p;i++)
	{
		if(i==pos) continue;
		if(p==pos)
		{
			p--;
			if(i>=p) break;
		}
//		cerr<<i<<" "<<p<<" "<<t1[i]<<" "<<t1[p]<<endl;
		if(t1[i]+t1[p]<x) continue;
		p--; ans++;
	}
	return ans;
}

int calc(int x,int &Max)
{
	sort(t1,t1+tlen);
	int ans=calcs(x,tlen);
//	cerr<<ans<<endl;
	int l=-1,r=tlen,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		int tmp=calcs(x,mid);
		if(tmp>=ans) ans=tmp,l=mid;
		else r=mid;
	}
	Max=l;
	return ans;
}

void dfs(int u,int fat,int x,int l)
{
	if(!u) return ;
	int v;
	size[u]=1;
	for(int i=hd[u];i!=-1;i=nt[i])
	{
		v=node[i];
		if(!v || v==fat) continue;
		dfs(v,u,x,len[i]);
		size[u]+=size[v];
	}
	
	tlen=0;
	f[u]=g[u]=0;
	for(int i=hd[u];i!=-1;i=nt[i])
	{
		v=node[i];
		if(!v || v==fat) continue;
		t1[tlen++]=f[v];
		g[u]+=g[v];
	}
	g[u]+=calc(x,f[u]);
	if(f[u]!=-1) f[u]=t1[f[u]];
	else f[u]=0;
	f[u]+=l;
	if(f[u]>=x) f[u]=0,g[u]++;
/*	cerr<<u<<": "<<f[u]<<" "<<g[u]<<endl;
	for(int i=0;i<tlen;i++) cerr<<t1[i]<<" ";
	cerr<<endl;
*/	
	return ;	
}


bool check(int x)
{
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	dfs(1,0,x,0);
	if(g[1]>=m) return 1;
	return 0;
}

void solve()
{
/*	t1[0]=4,t1[1]=7,t1[2]=10;
	tlen=3;
	int tmp; 
	cerr<<calc(15,tmp)<<" ";
	cerr<<t1[tmp]<<endl;
	return ;
	cerr<<check(15)<<endl;
	return ;
*/	int l=0,r=500000001,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%d\n",l);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	memset(hd,-1,sizeof hd);
	n=read(),m=read();
	int x,y,z;
	for(int i=0;i<n-1;i++)
	{
		x=read(),y=read(),z=read();
		con(x,y,z),con(y,x,z);
	}
	
	solve();
	
	return 0;
}
