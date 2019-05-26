#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=110,MAXA=25010;

int n,mx;
int a[MAXN];
bool v[MAXA];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int Case;scanf("%d",&Case);
	while(Case--)
	{
		scanf("%d",&n);
		mx=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
		sort(a+1,a+n+1);
		memset(v,false,sizeof(v));v[0]=true;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!v[a[i]])//debug v[i]
			{
				ans++;
				for(int j=a[i];j<=mx;j++)//debug v[j]=true;
					if(v[j-a[i]]) v[j]=true;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

