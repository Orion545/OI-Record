#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long n,d,ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int tmp=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>d;
		if(d>tmp) ans+=d-tmp;
		tmp=d;
	}
	cout<<ans;
	return 0;
}
