#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define fo(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
void read(int &x){
	char ch=' '; x=0;
	while(ch<'0' || ch>'9') ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar()) x=x*10+ch-'0';
}
const int N=1e5+10;
int n,a[N];
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	fo(i,1,n) read(a[i]),ans+=max(0,a[i-1]-a[i]);
	ans+=(ll)a[n];
	printf("%lld\n",ans);

}
