#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=5000+5;
struct miaow
{
	int f,t,l;
	int bj;
	miaow(int f=0,int t=0,int l=0,int bj=0):f(f),t(t),l(l),bj(bj){}
}imap[N*2];
int str[N]={0},imc=2;
void jb(int f,int t)
{
	imap[imc]=miaow(f,t,str[f],0);
	str[f]=imc++;
	imap[imc]=miaow(t,f,str[t],0);
	str[t]=imc++;
}
int n,m;

vector<int> so[N];
void dfs(int o,int fa)
{
	for(int i=str[o];i;i=imap[i].l)
	{
		int t=imap[i].t;
		if(t==fa)continue;
		so[o].push_back(t);
		dfs(t,o);
	}
	sort(so[o].begin(),so[o].end());
}

int ans1[N],ac1=1;
void dfs1(int o)
{
	ans1[ac1++]=o;
	for(int i=0;i<so[o].size();i++)
	{
		dfs1(so[o][i]);
	}
}
void solve1()
{
	dfs(1,0);
	dfs1(1);
	for(int i=1;i<=n;i++)
	{
		cout<<ans1[i]<<" ";
	}
}

int sy[N]={0};
int sta[N]={0},sta2[N]={0};
int hh[N],hc=0;
bool dfs2(int o,int fa,int d)
{
	if(sy[o])
	{
		//cout<<o<<endl;
		int x=d-1;
		while(sta2[x]!=o)
		{
			hh[hc++]=sta[x];
			--x;
		}
		hh[hc++]=sta[x];
		return true;
	}
	sy[o]=1;
	for(int i=str[o];i;i=imap[i].l)
	{
		int t=imap[i].t;
		if(t==fa)continue;
		sta[d]=i;
		sta2[d+1]=t;
		if(dfs2(t,o,d+1))return true;
	}
	return false;
}

void dfs3(int o,int fa)
{
	for(int i=str[o];i;i=imap[i].l)
	{
		if(imap[i].bj)continue;
		int t=imap[i].t;
		if(t==fa)continue;
		so[o].push_back(t);
		dfs3(t,o);
	}
	sort(so[o].begin(),so[o].end());
}
int ans2[N],ac2=1,kx=0;
bool dfs4(int o)
{
	//++ac2;
	if(kx)
	{
		ans2[ac2]=o;
	}
	else if(ans2[ac2]<o)return false;
	else if(ans2[ac2]>o)
	{
		kx=1;
		ans2[ac2]=o;
	}
	++ac2;
	for(int i=0;i<so[o].size();i++)
	{
		if(!dfs4(so[o][i]))return false;
	}
	return true;
}
void solve2()
{
	sta2[1]=1;
	dfs2(1,0,1);
	for(int i=1;i<=n;i++)
	{
		ans2[i]=1e6;
	}
	for(int i=0;i<hc;i++)
	{
		kx=0;
		ac2=1;
		imap[hh[i]].bj=1;
		imap[hh[i]^1].bj=1;
		for(int j=1;j<=n;j++)
		{
			so[j].clear();
		}
		dfs3(1,0);
		dfs4(1);
		imap[hh[i]].bj=0;
		imap[hh[i]^1].bj=0;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans2[i]<<" ";
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int f,t;
		cin>>f>>t;
		jb(f,t);
	}
	if(m==n-1)solve1();
	else solve2();
	cout<<endl;
	return 0;
}
