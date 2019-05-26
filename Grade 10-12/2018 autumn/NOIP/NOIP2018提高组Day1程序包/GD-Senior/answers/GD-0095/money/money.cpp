#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[110],ans,w;
bool b[25010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(;T;T--)
	{
		scanf("%d",&n);
		ans=n;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		memset(b,0,sizeof(b));
		w=1;
		for(int i=a[1];i<=a[n];i++){
			if(a[w]==i){
				if(b[i])
					ans--;
				else
					b[i]=true;
				w++;
			}
			if(b[i])
				for(int j=1;j<=n&&a[j]<=i;j++)
					b[i+a[j]]=true;
		}
		printf("%d\n",ans);
	}
	return 0;
}


