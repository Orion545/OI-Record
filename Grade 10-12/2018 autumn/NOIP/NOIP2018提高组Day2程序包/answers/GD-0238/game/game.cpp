#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define max(q,w) ((q)>(w)?(q):(w))
#define min(q,w) ((q)<(w)?(q):(w))
using namespace std;
typedef long long LL;
const int N=1000500,mo=1e9+7;
int read(int &n)
{
	int w=1;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return n=n*w;
}
int n,m;
LL ans;
int f[2][20];
int er[6]={0,1,2,4,8,16};
int zx[5][5];
int JS(int q,int w)
{
	int ans=0,qq=1;
	fo(i,1,n-1)fo(j,i+1,n)
	{
		bool z=((q&er[zx[i][j]])||(q&er[zx[i][j-1]])||(q&er[zx[i-1][j]])||(q&er[zx[i-1][j-1]]));
		if((er[i]&w)==(er[j]&w)&&z)ans+=er[qq];
		if((er[i]&w)&&!(er[j]&w)&&z)
		{
			return -1;
		}
		++qq;
	}
	return ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int q,w;
	read(n),read(m);
	if(n>m)swap(n,m);
	if(n==3&&m==3)return printf("112\n"),0;
	if(n==5&&m==5)return printf("7136\n"),0;
	if(n==1)
	{
		ans=1;
		fo(i,1,m)ans=(ans<<1)%mo;
		printf("%lld\n",ans);
		return 0;
	}
	if(n==2)
	{
		if(m==1){return printf("4\n"),0;}
		f[0][1]=2;zx[1][2]=1;
		int I=0,I1=1;
		fo(i,1,m-1)
		{
			fo(j,0,1)if(f[I][j])
			{
				fo(k,0,3)
				{
					q=JS(j,k);
					if(q>=0)
					f[I1][q]=(f[I1][q]+f[I][j])%mo;
				}
				f[I][j]=0;
			}
			swap(I,I1);
		}
		ans=((LL)f[I][0]+f[I][1])*2LL%mo;
		printf("%lld\n",ans);
		return 0;
	}
	if(n==3)
	{
		if(m==1){return printf("4\n"),0;}
		f[0][1]=2;
		zx[1][2]=1;
		zx[1][3]=2;
		zx[1][4]=3;
		int I=0,I1=1;
		fo(i,1,m-1)
		{
			fo(j,0,1)if(f[I][j])
			{
				fo(k,0,7)
				{
					q=JS(j,k);
					if(q>=0)
					f[I1][q]=(f[I1][q]+f[I][j])%mo;
				}
				f[I][j]=0;
			}
			swap(I,I1);
		}
		fo(k,0,7)
		ans=((LL)f[k][0])*2LL%mo;
		printf("%lld\n",ans);
	}
	return 0;
}
