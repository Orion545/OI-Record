#include <cstdio>
#include <cstring>
#include <algorithm>
//#define OVERDRIVE
using namespace std;
const int MAXV=25000;
int f[MAXV+5], a[105];
int T, n, m, i, j;
int main(){
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &T);
		#ifdef OVERDRIVE
		T=20;
		#endif
	while(T--){
		m=0;
		scanf("%d", &n);
			#ifdef OVERDRIVE
			n=100;
			#endif
		for(i=1; i<=n; i++) scanf("%d", &a[i]);
		sort(a+1, a+1+n);
		memset(f, 0, sizeof(f));
		f[0]=1;
			#ifdef OVERDRIVE
			f[0]=0;
			#endif
		for(i=1; i<=n; i++) if(!f[a[i]]){
			m++;
			for(j=a[i]; j<=MAXV; j++) f[j]|=f[j-a[i]];
//			for(i=1; i<=20; i++) printf("%d ", f[i]);
//			printf("\n");
		}
		printf("%d\n", m);
	}
	return 0;
}
