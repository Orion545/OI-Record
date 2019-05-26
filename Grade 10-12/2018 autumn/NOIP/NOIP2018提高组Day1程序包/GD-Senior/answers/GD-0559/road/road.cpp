#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=101000;

int a[maxn],n,ans,step;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	for(int i=n-1;i>0;--i)a[i]-=a[i-1];
	ans=0;
	for(int i=0;i<n;++i){
		if(a[i]>=0)ans+=a[i];
	}
	printf("%d\n",ans);
	return 0;
}

