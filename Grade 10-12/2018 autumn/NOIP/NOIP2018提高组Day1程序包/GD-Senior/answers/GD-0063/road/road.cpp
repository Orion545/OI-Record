#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,a[200001];long long ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++)
    {
    if(a[i]>a[i-1])
    ans+=a[i]-a[i-1];
    }
    cout<<ans<<endl;
    return 0;
}
