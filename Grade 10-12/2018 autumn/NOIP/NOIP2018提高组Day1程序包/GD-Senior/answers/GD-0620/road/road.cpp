#include <iostream>
#include <cstdio>
using namespace std;
int n;
long long i,j,ans;
int a[100001],now;//ջ
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(now=0;now<n;now++) cin>>a[now];
	while(now>=0) {
		int minn=0x7fffffff;
		while(!a[now] && now>=0) now--;
		if(now<0) break;
		for(i=now;i>=0 && a[i];i--)	{
			if(minn>a[i]) minn=a[i];
			if(!a[i]) break;
		}
		ans+=minn;
		for(j=now;j>=i+1;j--) a[j]=a[j]-minn;
	}
	cout<<ans;
	return 0;
}
