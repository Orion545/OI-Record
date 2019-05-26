#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=25000;
int T,n,a[105],vis[MAX+5];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		vis[0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=MAX;j++){
				if(vis[j]&&a[i]+j<=MAX)
					vis[a[i]+j]++;
			}
		int ans=n;
		for(int i=1;i<=n;i++)
			if(vis[a[i]]>1)ans--;
		printf("%d\n",ans);
	}
	return 0;
}
