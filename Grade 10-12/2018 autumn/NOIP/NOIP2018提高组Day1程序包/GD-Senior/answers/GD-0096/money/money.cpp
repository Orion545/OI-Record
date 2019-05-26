#include<cstdio>
#include<cstring>
using namespace std;
const int max=26000;
bool bk[61000],bz[61000];int a[1100];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int ans=0;
		memset(bk,false,sizeof(bk));
		memset(bz,true,sizeof(bz));
		bk[0]=true;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=max;j++){
				if(bk[j]){
					if(bk[j+a[i]]) bz[j+a[i]]=false;
					else bk[j+a[i]]=true;
				}
			}
		}
		for(int i=1;i<=n;i++) if(bz[a[i]]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
