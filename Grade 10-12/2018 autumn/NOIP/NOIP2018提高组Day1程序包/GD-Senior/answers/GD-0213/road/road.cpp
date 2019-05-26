#include<cstdio>
using namespace std;
int a[200000],n;
long long ans;
void f(int l,int r,int x){
	if(l>r)return ;
	if(l==r){
		ans+=a[l]-x;
		return ;
	}
	int m,mi;
	m=a[l]-x;
	mi=l;
	for(int i=l+1;i<=r;++i){
		if(a[i]-x<=m){
			m=a[i]-x;
			mi=i;
		}
	}
	ans+=m;
	f(l,mi-1,x+m);
	f(mi+1,r,x+m);
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
	}
	ans=0;
	f(0,n-1,0);
	printf("%lld",ans);
	return 0;
}
