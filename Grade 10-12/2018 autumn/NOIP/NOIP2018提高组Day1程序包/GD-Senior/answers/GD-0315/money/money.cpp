#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int Q;
int n,a[1007];
bool vis[1007*1007],biaoshi[1007*1007];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=2*a[n];i++)	vis[i]=0;
		for(int i=1;i<=2*n;i++)	biaoshi[i]=0;
		int ans=n;
		for(int i=1;i<=n;i++){
			vis[a[i]]=1;
			for(int j=0;j<=a[n];j++)	if(vis[j])	vis[j+a[i]]=1;
			for(int j=i+1;j<=n;j++)	
				if(vis[a[j]]==1&&biaoshi[j]==0){
					ans--;
					biaoshi[j]=1;
				} 
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
