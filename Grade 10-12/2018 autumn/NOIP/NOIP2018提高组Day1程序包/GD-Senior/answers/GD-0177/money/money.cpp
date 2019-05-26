#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, a[30000];
bool num[30000];

int main(){
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--){
		memset(num, 0, sizeof(num));
		scanf("%d", &N);
		for (int i=0; i<N; i++) scanf("%d", &a[i]);
		sort(a, a+N);
		if (a[0]==1) {
			printf("1"); cout<<endl;
			continue;
		}
		int ans=N;
		for (int i=0; i<N; i++){
			if (num[a[i]]) {
				ans--;
				continue;
			}
			for (int j=a[0]; j<=a[N-1]; j++) if (num[j]){
				for (int k=1; j+a[i]*k<=a[N-1]; k++) num[j+a[i]*k]=1;
			}
			for (int j=1; a[i]*j<=a[N-1]; j++) num[a[i]*j]=1;
		}
		printf("%d", ans); cout<<endl;
	}
	fclose(stdout);
	return 0;
}