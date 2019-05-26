#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,g,a[300001],next[300001],head[300001],to[300001];
long long jj=10000*20000;
char gg;bool pan[300001];
int home[300001];long long f[300001][4];
bool end=0;string lj;
int xx1,yy1,xx2,yy2;
//1是我没有被取到 2是我驻扎了 3是我取到了没驻扎 
void dfs(int root)
{
	long long u=0,u1=0,u2=0,cha=jj,qu=0;
	pan[root]=1;
	for(int i=head[root];i;i=next[i])
	{
		if(!pan[to[i]])
		{
			dfs(to[i]);
			u+=f[to[i]][3];
			u1+=min(min(f[to[i]][1],f[to[i]][3]),f[to[i]][2]);
			u2+=min(f[to[i]][2],f[to[i]][3]);
			if(f[to[i]][2]<f[to[i]][3])qu=1;
			else
			cha=min(cha,f[to[i]][2]-f[to[i]][3]);
		}
	}
	f[root][1]=u;
	f[root][2]=a[root]+u1;
	f[root][3]=u2;
	if(qu==0)f[root][3]+=cha;
	if(xx1==root||xx2==root)
	{
		if(xx1==root)
		{
			if(yy1)
			{
			f[root][1]=f[root][3]=jj;
			}else
			{
			f[root][2]=jj;
			}
		}else
		{
			if(yy2)
			{
				f[root][1]=f[root][3]=jj;
			}else
			{
			f[root][2]=jj;
			}
		}
	}
	return;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>lj;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
	int x,y;scanf("%d %d",&x,&y);
	next[i]=head[x];head[x]=i;to[i]=y;
	next[i+n]=head[y];head[y]=i+n;to[i+n]=x;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>xx1>>yy1>>xx2>>yy2;end=0;
		for(int j=1;j<=n;j++)
		f[j][1]=f[j][2]=f[j][3]=jj;
		memset(pan,0,sizeof(pan));
		dfs(1);
		long long ans=min(f[1][2],f[1][3]);
		if(ans<jj)
		cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}return 0;
}
