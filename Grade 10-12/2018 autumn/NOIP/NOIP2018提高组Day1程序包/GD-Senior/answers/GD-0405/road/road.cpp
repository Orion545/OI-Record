#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll n,d[10005],ans=0;;
void fen(ll l,ll r,ll *a)
{   
    
    if(l>r)
    return;
    int min=1e9;
    ll pos=0;
	for(ll i=l;i<=r;i++)
	{
		if(a[i]<min)
	{
		min=a[i];
		pos=i;
		
	}
}
	ans+=min;
	for(ll i=l;i<=r;i++)
	  a[i]-=min;
	fen(l,pos-1,a);
	fen(pos+1,r,a);

}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	ll sum=0;
	for(ll i=1;i<=n;i++)
	  scanf("%lld",&d[i]);
	  fen(1,n,d);
	printf("%d",ans);	
    fclose(stdin);
	fclose(stdout);
	return 0;
}
