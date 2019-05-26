#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,d[100100],a=0,m[100100],ans=0;
int main() {
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	int i,j;
	cin>>n;a=n;
	for(i=1;i<=n;i++) {
		scanf("%d",&d[i]);
	}
	int mi=10111,q;bool ff=false;
	while(!ff) {
		for(i=1;i<=n;i++)if(d[i]!=0){	q=i;mi=d[i];i=n;	}
	for(i=q;i<=n;i++) {
		if(d[i]==0||i==n) {
			ans+=mi;
			for(j=q;j<=i;j++)d[j]-=mi;
			i=n;
		}else {
			mi=min(mi,d[i]);
		}
	}
	ff=true;for(i=1;i<=n;i++) {
		if(d[i]!=0) {
			ff=false;i=n;
		}
	}
	}
	cout<<ans<<endl;
	return 0;
}
//freopen(".in","r",stdin);freopen(".out","w",stdout);
