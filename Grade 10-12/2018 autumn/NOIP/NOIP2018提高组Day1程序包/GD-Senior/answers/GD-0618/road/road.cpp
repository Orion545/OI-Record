#include <iostream>
#include <cstdio>
using namespace std;
int n,a[100010],d[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	a[0]=0;d[0]=0;
	for(register int i=1,k;i<=n;i++){
		cin>>d[i];
		if(d[i-1]>=d[i]) a[i]=a[i-1];
		else{
			k=d[i]-d[i-1];
			a[i]=a[i-1]+k;
		}
	}
	cout<<a[n];
	return 0;
}
