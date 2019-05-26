#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cf[100005],n,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>cf[i],sum+=(cf[i]-cf[i-1])>0?(cf[i]-cf[i-1]):0;
	cout<<sum;
}
