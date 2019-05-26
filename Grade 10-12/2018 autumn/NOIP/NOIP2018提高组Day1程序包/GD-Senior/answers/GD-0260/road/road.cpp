#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int maxn=100010;
int a[maxn],mx[maxn],mn[maxn];
int n,tot=0,ans=0;

void read(int &sum)
{
	char ch=getchar();int f=0;sum=0;
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	(ch=='-')&&(f=1,ch=getchar());
	while(ch>='0'&&ch<='9') sum=sum*10+ch-48,ch=getchar();
	(f)&&(sum=-sum);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(mx,0,sizeof mx);
	memset(mn,63,sizeof mn);
	read(n);
	a[0]=-1;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		if(a[i]>a[i-1]) tot++;
		(a[i]>mx[tot])&&(mx[tot]=a[i]);
		(a[i]<mn[tot])&&(mn[tot]=a[i]);
	}
	ans=mx[1];
	for(int i=2;i<=tot;i++)
		ans+=(mx[i]-mn[i-1]);
	printf("%d\n",ans);
	return 0;
}
