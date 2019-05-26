#include <bits/stdc++.h>
#define N 100010

using namespace std;
int a[N],b[N];

void read(int &x){
	int y=0;char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(!(c<'0' || c>'9')) y=y*10+c-'0',c=getchar();
	x=y;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,i,j;
	long long ans=0;
	read(n);
	for(i=1;i<=n;++i) read(a[i]);
	for(i=1;i<=n;++i){
		int x=-1,y,l,r;
		for(j=1;j<=n;++j){
			if( a[j] && (x==-1 || x>a[j]) ){
				x=a[j];
				y=j;
			}
		}
		if(x==-1) break;
		a[y]-=x;
		l=y-1,r=y+1;
		while(a[l] && l>0) a[l]-=x,l--;
		while(a[r] && r<=n) a[r]-=x,r++;
		ans+=x;
	}
	printf("%lld",ans);
}
