#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T,m;
int a[50000];
int tag[50000];
bool vis[50000];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	int n,cnt,k;
	while(T--){
		memset(tag,0,sizeof(tag));
		scanf("%d",&n);
		m=0;cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			tag[a[i]]++;
			m=max(m,a[i]);
		}
		if(n==2){
			if(a[1]>a[2])swap(a[1],a[2]);
			if(a[2]%a[1]==0)
				printf("1\n");
			else printf("2\n");
			continue;
		}
		
		for(int i=1;i<=m;i++)
			if(tag[i]&&(!vis[i])){
				cnt+=tag[i]-1;
				tag[i]=1;
				k=i+i;
				while(k<=m){
					cnt+=tag[k];
					tag[k]=0;
					vis[k]=1;
					k+=i;
				}
			}
		cout<<n-cnt<<endl;
	}
	return 0;
}
