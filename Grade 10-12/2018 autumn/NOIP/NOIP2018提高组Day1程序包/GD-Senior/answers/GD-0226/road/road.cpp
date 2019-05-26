#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
int n;
ll a[200000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	a[0]=0;
	ll cnt=0;
	ll min_n=a[0],max_n=a[0];
	bool b=0;//0up 1down
	for(int i=1;i<=n;i++){
		if(b==0){
			if(a[i]>=a[i-1]){
				max_n=a[i];
				if(i==n){
					cnt+=(max_n-min_n);
				}
			}
			else{
				cnt+=(max_n-min_n);
				b=1;
			}
		}
		else{
			if(a[i]>a[i-1]){
				min_n=a[i-1];
				max_n=a[i];
				b=0;
				if(i==n)
					cnt+=(max_n-min_n);
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
