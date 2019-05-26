#include <iostream>
#include <cstdio>
using namespace std;
int a[100010],p[100010];
long long ans=0;
int search(int l,int r)
{
	int pp=0;
	for (int i=l;i<=r;++i) if (p[i]==0) pp=1;
	if (pp==0) return 0;
	while (true){
		int pp=0;
		for (int i=l;i<=r;++i){
			if (a[i]==0){
				if (l<=i-1) search(l,i-1);
				if (i+1<=r) search(i+1,r);
				p[i]=1;
			}
		}
		for (int i=l;i<=r;++i) if (p[i]==0) {pp=1;break;};
		if (pp==0) break;
		for (int i=l;i<=r;++i)--a[i];
		++ans;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	search(1,n);
	cout<<ans;
	return 0;
}
