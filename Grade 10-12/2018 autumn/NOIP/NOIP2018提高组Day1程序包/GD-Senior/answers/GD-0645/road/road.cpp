#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define fo(i,j,l) for(int i=j;i<=l;++i)
#define fd(i,j,l) for(int i=j;i>=l;--i)

using namespace std;
typedef long long ll;
const ll N=1e5+100;

int a[N];
int n;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n)scanf("%d",&a[i]);
	ll ans=0;
	a[0]=0;
	fo(i,1,n)if(a[i]>a[i-1])ans=ans+a[i]-a[i-1];
	cout<<ans;
}
