#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;
int d[100527];
int f[100527];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		f[i]=d[i]-d[i-1];
		if(f[i]>0) ans+=f[i];
	}
	printf("%lld",ans);
}
