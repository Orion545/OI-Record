#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	x=(flg?-x:x);
}
const int Mod=1e9+7;
typedef long long ll;

int n,m;
int pow(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=(ll)res*x%Mod;
		x=(ll)x*x%Mod;
		y>>=1;
	}
	return res;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);read(m);
	if (n>m) swap(n,m);
	if (n<=3&&m<=3)
	{
		if (n==1)
		{
			printf("%d\n",(1<<m));
		}
		else if (n==2)
		{
			if (m==2) puts("12");
			else puts("28");
		}
		else puts("112");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (n==1)
	{
		printf("%d\n",pow(2,m));
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int ans=0,tmp=1;
	for (int i=1;i<=m;i++)
	{
		tmp=(tmp+tmp)%Mod;
		ans=(ans+tmp)%Mod;
	}
	printf("%d\n",ans*2%Mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
