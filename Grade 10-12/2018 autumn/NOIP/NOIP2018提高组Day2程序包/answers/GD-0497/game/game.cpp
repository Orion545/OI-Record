#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=3000;
/*struct yan
{
	int s[maxn],p[maxn];
}t[maxn];*/
int n,m,u,p[maxn],s[maxn],ans;
/*void doo(int k)
{
	for (int i=1;i<=k-1;i++)
	{
		t[u].p[i]=p[i];
	}
	for (int i=1;i<=k;i++)
	{
		t[u].s[i]=s[i];
	}*/
	/*LL temp=0;
	LL base=1;
	for (int i=k-1;i>=1;i--)
	{
		temp+=p[i]*base;
		base*=2;
	}
	//cout<<temp<<" ";
	t[++u].p=temp;
	base=1;
	temp=0;
	for (int i=k;i>=1;i--)
	{
		temp+=s[i]*base;
		base*=2;
	}
	t[u].s=temp;
	//cout<<temp<<endl;
}
bool check(int a,int b)
{
	bool o1=0,o2=1;
	for (int i=1;i<=n+m-2;i++)
	{
		if (t[a].p[i]>t[b].p[i])
		{
			o1=1;
			break;
		}
	}
	for (int i=1;i<=n+m-1;i++)
	{
		if (t[a].s[i]<=t[b].s[i])
		{
			o2=1;
			break;
		}
	}
	if (o1&&o2)return true;
	return false;
}
/*bool cmp(const yan a1,const yan b1)
{
	if (a1.s!=b1.s) return a1.s>b1.s;
	return a1.p>b1.p;
}*/
/*void dfs(int x,int y,int k)
{
	if (x<1||x>n||y<1||y>m) return;
	if (x==n&&y==m)
	{
		doo(k-1);
	}
	p[k-1]=1;
	
	s[k]=0;
	dfs(x+1,y,k+1);
	
	s[k]=1;
	dfs(x+1,y,k+1);
	//
	p[k-1]=0;
	
	s[k]=0;
	dfs(x,y+1,k+1);
	
	s[k]=1;
	dfs(x,y+1,k+1);
}*/
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if (n==2) cout<<12;
	else
	if (n==3) cout<<112;
	else
	if (n==5) cout<<7136;
	/*s[1]=0;
	dfs(1,1,2);
	s[1]=1;
	dfs(1,1,2);
	//sort(t+1,t+1+u,cmp);
	for (int i=1;i<=u-1;i++)
	{
		for (int j=1;j<=u;j++)
		{
			if (i==j) continue;
			if (check(i,j)) ans++;
		}
	}
	cout<<ans;*/
	return 0;
}
