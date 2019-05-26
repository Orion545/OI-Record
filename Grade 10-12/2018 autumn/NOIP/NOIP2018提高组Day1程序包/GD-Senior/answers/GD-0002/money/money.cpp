#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t,n;
int a[110];
bool v[25010];
int q[25010],tt;
int ma;
inline char cn()
{
	static char buf[1000010],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
void read(int &x)
{
	x=0;char ch=cn();
	while(ch<'0'||ch>'9')ch=cn();
	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=cn();
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);
		ma=tt=0;
		q[++tt]=0;
		for(int i=1;i<=n;i++)
		read(a[i]),ma=a[i]>ma?a[i]:ma;
		sort(a+1,a+n+1);
		if(a[1]==1)
		{
			printf("1\n");
			continue;
		}
		int ans=n;
		for(int i=1;i<=n;i++)
		{
			if(v[a[i]])ans--;
			else
			{
				for(int j=tt;j>=1;j--)
				{
					int p=q[j]+a[i];
					while((p<=ma)&&(!v[p]))v[p]=true,q[++tt]=p,p+=a[i];
				}
			}
		}
		for(int i=1;i<=tt;i++)
		v[q[i]]=false;
		printf("%d\n",ans);
	}
}
