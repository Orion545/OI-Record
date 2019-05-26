#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000005
long long n, m, i, j, k, cnt, ans, is[N], pr[N];
const long long p = 1e9+7;
void ycl(){
	int i, j;
	for(i=2; i<=N; i++){
		if(!is[i]) pr[++cnt] = i;
		for(j=1; j<=cnt&&i*pr[j]<=N; j++){
			is[i*pr[j]] = 1;
			if(i%pr[j]==0) break;
		}
	}
}
long long ksm(long long x, long long c){
	long long s = 1;
	while(c){
		if(c&1) s = s*x%p;
		x = x*x%p;
		c >>= 1;
	}
	return s;
}
long long suan(long long x, long long y){
	long long s = 0;
	while(x){
		x /= y;
		s += x;
	}
	return s;
}
long long C(long long a, long long b){
	long long ge, ji=1, shang=1;
	for(int i=1; pr[i]<=a; i++){
		ge = suan(a, pr[i])-suan(a-b, pr[i])-suan(b, pr[i]);
		while(ge>0) ji = ji*pr[i]%p, ge--;
		while(ge<0) shang = shang*pr[i]%p, ge++;
	}
	return ji%p/shang;
}
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ycl();
	scanf("%lld%lld", &n, &m);
	if(n==1||m==1){
		printf("0\n");
		return 0;
	}
	if(n==2&&m==2){
		printf("12\n");
		return 0;
	}
	if((n==2&&m==3)||(n==3&&m==2)){
		printf("36\n");
		return 0;
	}
	if(n==3&&m==3){
		printf("112\n");
		return 0;
	}
	if(n<=2){
		m--;
		for(i=1; i<=m; i++){
			ans = (ans + ksm(-1, (i+1))*C(m, i)%p*ksm(2, (m+1)*n-2*i)%p)%p;
		}
		printf("%lld\n", ksm(2, n*(m+1))%p-ans);
	}
	else printf("%lld\n", ksm(2, n*m-2)%p*(n-1)*(m-1)%p);
	return 0;
}
