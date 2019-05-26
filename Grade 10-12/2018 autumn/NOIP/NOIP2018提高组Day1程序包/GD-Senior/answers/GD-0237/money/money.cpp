#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
const int N=105,lim=25005;
int a[N];
bool bz[lim];
inline int read()
{
	int X=0,w=0; char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w?-X:X;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--)
	{
		int n=read(),ans=0;
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+1+n);
		memset(bz,false,sizeof(bz));
		bz[0]=true;
		for(int i=1;i<=n;i++)
		{
			int num=a[i];
			if(!bz[num])
			{
				ans++;
				for(int j=0;j<lim;j++)
					if(bz[j])
					{
						int k=j+num;
						while(k<lim && !bz[k]) bz[k]=true,k+=num;
					}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
