#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x)
{
	if(x<0)putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
inline int gcd(int a,int b)
{
	if(a==0)return b;
	else return gcd(b%a,a);
}
int a[110][110];
inline int Guass(int equ,int var)
{
	int h,l;
	for(h=1,l=1;h<=equ,l<=var;h++,l++)
	{
		int mx=0;
		for(int i=h;i<=equ;i++)if((mx==0 && abs(a[i][l])>0) || (abs(a[i][l])<abs(a[mx][l]) && abs(a[i][l])>0))mx=i;
		if(mx==0){h--;continue;}
		if(mx!=h)for(int i=l;i<=var;i++)swap(a[h][i],a[mx][i]);
		for(int i=h+1;i<=equ;i++)
		{
			if(abs(a[i][l])>0)
			{
				int t=a[i][l]/gcd(a[h][l],a[i][l]);
				a[i][l]=0;
				for(int j=l+1;j<=var;j++)
				{
					if(t==1)a[i][j]=0;
					else a[i][j]=-a[h][j]*t;
				}
			}
		}
	}
	return h-1;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)
		{
			a[i][1]=read();
			for(int j=2;j<=n;j++)a[i][j]=a[i][1];
		}
		if(n<=2)
		{
			if(a[1][1]>a[1][2])swap(a[1][1],a[1][2]);
			if(a[1][2]%a[1][1]==0)printf("1\n");
			else printf("2\n");
		}
		printf("%d\n",Guass(n,n));
	}
	return 0;
}
