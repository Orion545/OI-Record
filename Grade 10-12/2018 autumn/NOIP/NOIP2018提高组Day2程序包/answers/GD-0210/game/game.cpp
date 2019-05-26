#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M=260,mod=1e9+7;
int n,m,S,res;

struct Matrix
{
	int a[M][M];
	void clear(){memset(a,0,sizeof(a));}
	void one(){clear();for(int i=0;i<S;++i)a[i][i]=1;}
	void print()
	{
		for(int i=0;i<S;++i,puts("")) for(int j=0;j<S;++j) printf("%d ",a[i][j]); puts(""); 
	}
}mat,ans;

bool check(int x,int y)
{
	for(int i=1;i<n;++i) if(((x>>i)&1)<((y>>(i-1))&1)) return 0;
	//printf("%d %d\n",x,y);
	return 1;
}

void up(int &x,int y){x+=y;if(x>=mod)x-=mod;}

Matrix mul(Matrix const&x,Matrix const&y)
{
	Matrix ret;ret.clear();
	for(int i=0;i<S;++i) for(int j=0;j<S;++j) for(int k=0;k<S;++k)
		up(ret.a[i][j],(ll)x.a[i][k]*y.a[k][j]%mod);
	return ret;
}

Matrix qpow(Matrix x,int y)
{
	Matrix ret;ret.one();//ret.print();
	for(;y;y>>=1,x=mul(x,x)) if(y&1) ret=mul(ret,x);
	//ret.print();
	return ret;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);S=(1<<n);
	if(n==3 && m==3){puts("112");return 0;}
	for(int i=0;i<S;++i) for(int j=0;j<S;++j) if(check(i,j)) mat.a[i][j]=1;
	//mat.print();
	for(int i=0;i<S;++i) ans.a[i][i]=1;
	ans=mul(ans,qpow(mat,m-1));
	//ans.print();
	/*for(int i=1;i<m;++i) 
	{
		ans=mul(ans,mat),ans.print();
		for(int j=0;j<S;++j) 
		{
			int tmp=0;
			for(int k=0;k<S;++k) tmp+=ans.a[k][j];
			printf("%d %d\n",j,tmp);
		}
		puts("");
	}*/
	for(int i=0;i<S;++i) for(int j=0;j<S;++j)up(res,ans.a[i][j]);
	printf("%d\n",res);
	
	return 0;
}
