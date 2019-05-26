#include<bits/stdc++.h>

using namespace std ;

const int N=10,M=1e6+10,mod=1e9+7;
struct Tmat{int mat[300][300];}a,b;
int n,m,f[300][300];

void add(int &x,int y)
{
	x=x+y;
	x=x>mod?x-mod:x;
	x=x<0?x+mod:x;
}

void mul(Tmat &x,Tmat y,int sz)
{
	Tmat z;
	for (int i=0;i<sz;i++)
		for (int j=0;j<sz;j++)
			z.mat[i][j]=0;
	for (int i=0;i<sz;i++)
		for (int j=0;j<sz;j++)
			for (int k=0;k<sz;k++)
				add(z.mat[i][j],1ll*x.mat[i][k]*y.mat[k][j]%mod);	
	x=z;
}

Tmat qpow(Tmat x,int y,int sz)
{
	Tmat ret;
	for (int i=0;i<sz;i++)
		for (int j=0;j<sz;j++)
			ret.mat[i][j]=0;
	for (int i=0;i<sz;i++)
		ret.mat[i][i]=1;
	for (;y;y>>=1,mul(x,x,sz))
		if (y&1) mul(ret,x,sz);
	return ret;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	cin>>n>>m;
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<(1<<n);j++)
		{
			bool ok=1;
			for (int k=0;k<n-1;k++)
				if (((i>>(k+1))&1)<((j>>k)&1)){ok=0;break;}
			f[i][j]+=ok;
		}
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<(1<<n);j++)
			a.mat[i][j]=f[i][j];
	for (int i=0;i<(1<<n);i++) b.mat[0][i]=1;
	mul(b,qpow(a,m-1,1<<n),1<<n);
	int ans=0;
	for (int i=0;i<(1<<n);i++)
		add(ans,b.mat[0][i]);
	printf("%d\n",ans);
	
	return 0;
}
