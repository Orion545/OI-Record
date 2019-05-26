#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int ML=100100;

int a[ML],p[ML],f[ML];

bool cmP(int i,int j) { return a[i]<a[j]; }

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n; scanf("%d",&n);
	
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),p[i]=i;
	
	sort(p+1,p+n+1,cmP); a[0]=p[0]=0;
	
	f[0]=f[n+1]=1;
	
	long long ans=0;
	
	for (int i=1,wid=1; i<=n; i++)
	 ans+=1LL*wid*(a[p[i]]-a[p[i-1]]),
	 wid+=1-f[p[i]-1]-f[p[i]+1],
	 f[p[i]]=1;
	
	cout<<ans;
	
	return 0;
}
