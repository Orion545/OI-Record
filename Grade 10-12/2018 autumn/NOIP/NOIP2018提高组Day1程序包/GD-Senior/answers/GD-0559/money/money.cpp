#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxp=30000;

int T,n,ans,a[110],cur[30000];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(cur,0,sizeof(cur));
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		sort(a,a+n);
		ans=1;
		for(int i=a[0];i<maxp;i+=a[0])cur[i]=1;
		for(int i=1;i<n;++i){
			if(!cur[a[i]]){
				++ans;
				cur[a[i]]=1;
				for(int j=a[0];j<maxp-a[i];++j)
				if(cur[j])cur[j+a[i]]=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

