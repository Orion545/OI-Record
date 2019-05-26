#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;
const int N=110;
const int A=25010;
int n;
int a[N],maxa;
bitset<A> s;
void readData(){
	scanf("%d",&n);
	maxa=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxa=max(maxa,a[i]);
	}
}
void solve(){
	sort(a+1,a+1+n);
	s[0]=1;
	for(int i=1;i<=maxa;i++) s[i]=0;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!s[a[i]]){
			ans++;
			for(int x=1;a[i]*x<=maxa;x<<=1)
				s|=s<<(a[i]*x);
		}
	printf("%d\n",ans);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		readData();
		solve();
	}
	return 0;
}
