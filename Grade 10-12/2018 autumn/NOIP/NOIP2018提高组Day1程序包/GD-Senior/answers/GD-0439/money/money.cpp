#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[110],b[110],cnt,t[25010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		memset(t,0,sizeof(t));
		cnt=0;
		scanf("%d",&n);t[0]=1;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			int flag=!t[a[i]];
			for(int j=1;j<=cnt;j++) if(a[i]%b[j]==0) flag=0;
			if(flag==0) continue;
			b[++cnt]=a[i];
			for(int j=0;j<b[cnt];j++)
			{
				int k=j;
				for(;!t[k];k+=b[cnt]);
				for(;k<=25000;k+=b[cnt])t[k]=1;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
