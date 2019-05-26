#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
inline int read()
{
	int f=1,x=0;
	char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return f*x;
}
bool v[110000];
int a[1100];
int b[1100];
int c[1100];
int pr[110000];
bool sy[110000];
int m;
int len;int blen,clen;
/*void pre()
{
	memset(v,true,sizeof(v));
	len=0;
	for(int i=2;i<=30000;i++)
	{
		if(v[i])pr[++len]=i;
		for(int j=1;j<=len&&i*pr[j]<=30000;j++)
		{
			if(pr[j]>i)break;
			v[i*pr[j]]=false;
		}
	}
}
*/
void check(int x)
{
	int now=1;
	bool bk=false;
	while(1)
	{
		bool bkk=false;
		for(int i=1;i<=blen;i++)
		{
			if(x==i)continue;
			int s=b[x]-now*b[i];
			if(s>0)bkk=true;
			if(s<0)break;
			if(bk==true)break;
			for(int j=x-1;j>=1;j--)
			{
				if(b[j]>s)continue;
				if(s%b[j]==0){bk=true;m--;v[x]=true;break;}
			}
		}
		if(bk==true)break;
		if(bkk==false)break;
		now++;
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t=read();
	while(t--)
	{
		blen=0;
		int n=read();
		m=n;
		clen=0;
		memset(v,false,sizeof(v));
		memset(sy,true,sizeof(sy));
		bool bk=false;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]==1)bk=true;
		}
		sort(a+1,a+n+1);
		if(bk==true){printf("1\n");continue;}
		for(int i=1;i<=n;i++)
		{
			if(sy[i]==false)continue;
			for(int j=i-1;j>=1;j--)
			{
				if(sy[j]==false)continue;
				if(a[i]%a[j]==0){m--;sy[i]=false;break;}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(sy[i]==false)continue;
			b[++blen]=a[i];
		}
		sort(b+1,b+blen+1);
		for(int i=blen;i>=1;i--)
		{
			check(i);
		}
		printf("%d\n",m);
	}
	return 0;
}
//2 4 3 19 10 6 5 11 29 13 19 17
// 1 9 20 25 21 22 14 23 12 13 24
// 1 8 13 11 19 16 3 15 20 17
// 1 54 74 36 49 81 57 76 93 50 45 69 75 83 59 98 70 80 54 37 92 84 91 58 11 16 96 94 38 55 97 73 46 72 47 51 44 89 90 31 100 99 39 82 65 87 41 79 86 34 95 63 52 12 88 53


