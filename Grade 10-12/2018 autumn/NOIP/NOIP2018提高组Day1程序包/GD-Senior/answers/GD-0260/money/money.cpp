#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=110;
int t,n,a[maxn],b[maxn],tot;
bool tf=false;

void read(int &sum)
{
	char ch=getchar();int f=0;sum=0;
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	(ch=='-')&&(f=1,ch=getchar());
	while(ch>='0'&&ch<='9') sum=sum*10+ch-48,ch=getchar();
	(f)&&(sum=-sum);
}
void dfs(int k)
{
	if(k==0)
	{
		tf=true;
		return;
	}
	for(int i=tot;i>=1;i--)
	{
		if(b[i]>k) continue;
		dfs(k-b[i]);
		if(tf) return;
	}
	return;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);
		for(int i=1;i<=n;i++)
			read(a[i]);
		sort(a+1,a+1+n);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]%a[i]==0)
				{
					a[j]=a[n];
					n--;j--;
				}
		if(n<3)
		{
			printf("%d\n",n);
			continue;
		}
		sort(a+1,a+1+n);
		b[1]=a[1];b[2]=a[2];tot=2;
		for(int i=3;i<=n;i++)
		{
			tf=false;
			dfs(a[i]);
			if(!tf) b[++tot]=a[i];
		}
		printf("%d\n",tot);
	}
	return 0;
}
