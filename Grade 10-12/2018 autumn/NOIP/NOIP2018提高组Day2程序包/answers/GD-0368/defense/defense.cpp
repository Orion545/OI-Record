#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;

int nex[200001],b[200001],final[100001],bz[100001][2],fa[100001],n,m;

long long f[100001][2],p[100001];

char ch[2];

long long min(long long x,long long y){
	return x>y?y:x;
}

void dg(int t)
{
	for(int j=final[t];j;j=nex[j])
	{
		if(b[j]==fa[t])continue;
		
		fa[b[j]]=t;
		dg(b[j]);
	}
}

void dp(int t)
{
	f[t][0]=0;f[t][1]=p[t];
	for(int j=final[t];j;j=nex[j])
	{
		if(b[j]==fa[t])continue;
		
		dp(b[j]);
		
		f[t][0]+=f[b[j]][1];
		f[t][1]+=min(f[b[j]][1],f[b[j]][0]);
	}
	if(bz[t][0])f[t][0]=1e14;
	if(bz[t][1])f[t][1]=1e14;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d%d%s",&n,&m,ch);
	
	for(int i=1;i<=n;i++)
		scanf("%lld",&p[i]);
	
	memset(final,0,sizeof(final));
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&b[i+n-1],&b[i]);
		
		nex[i+n-1]=final[b[i]];
		final[b[i]]=i+n-1;
		nex[i]=final[b[i+n-1]];
		final[b[i+n-1]]=i;
	}
	
	dg(1);
	
	memset(bz,0,sizeof(bz));
	for(int i=1;i<=m;i++)
	{
		int u,x,v,y;
		scanf("%d%d%d%d",&u,&x,&v,&y);
		
		if((!x)&&(!y)&&((fa[u]==v)||(fa[v]==u)))
		{
			printf("-1\n");
			continue;
		}
		
		bz[u][x^1]=bz[v][y^1]=1;
		dp(1);
		bz[u][x^1]=bz[v][y^1]=0;
		
		printf("%lld\n",min(f[1][1],f[1][0]));
	}
}
