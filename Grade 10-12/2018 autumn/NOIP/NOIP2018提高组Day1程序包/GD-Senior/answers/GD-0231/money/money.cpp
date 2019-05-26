#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[110],n,ans,maxa;
bool f[110000];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;scanf("%d",&T);
	while (T--){
		ans=0;
		scanf("%d",&n);
		maxa=1000;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			while (a[i]>1000)a[i]-=a[1];
		}
		sort(a+1,a+n+1);
		memset(f,false,sizeof(f));
		f[0]=true;
		for (int i=1;i<=n;i++){
			if (f[a[i]]==false){
				ans++;
				for (int t=1;;t++){
					if (t*a[i]>maxa)break;
					for (int j=maxa;j>=0;j--){
						if (f[j])f[j+a[i]]=true;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

