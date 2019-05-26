#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int mod=1e9+7;
int n,m,k,sl,fh,ans;
struct node
{
	int s[300][300];
}f,g;
node operator *(node a,node b)
{
	node c;
	for(int i=0;i<(1<<n);++i)
		for(int j=0;j<(1<<n);++j)
			c.s[i][j]=0;
	for(int i=0;i<(1<<n);++i)
		for(int j=0;j<(1<<n);++j)
			for(int k=0;k<(1<<n);++k)
				c.s[i][j]=(c.s[i][j]+1ll*a.s[i][k]*b.s[k][j])%mod;
	return c;
}
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
bool check(int x,int y)
{
	int p,q;
	y>>=1;x&=k;
	while(x||y)
	{
		p=x&1;q=y&1;
		if(p>q) return 0;
		x>>=1;y>>=1;
	}
	return 1;
}
void pow(int p)
{
	for(int i=0;i<(1<<n);++i) g.s[i][i]=1;
	while(p)
	{
		if(p&1) g=g*f;
		f=f*f;p>>=1;
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=rd();m=rd();k=(1<<(n-1))-1;
	for(int i=0;i<(1<<n);++i)
	{
		for(int j=0;j<(1<<n);++j)
			if(check(i,j))
				f.s[i][j]++;
	}
//	for(int i=0;i<(1<<n);++i,puts(""))
//		for(int j=0;j<(1<<n);++j)
//			printf("%d ",f.s[i][j]);
	pow(m);
//	for(int i=0;i<(1<<n);++i,puts(""))
//		for(int j=0;j<(1<<n);++j)
//			printf("%d ",g.s[i][j]);
	for(int i=0;i<(1<<n);++i) ans=(ans+g.s[0][i])%mod;
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
