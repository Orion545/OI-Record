#include <iostream>
#include <cstdio>
using namespace std;

int d[100010];

int main(){
	freopen("road.in", "r", stdin);	
	freopen("road.out", "w", stdout);
	int N;
	scanf("%d", &N); 
	for (int i=0; i<N; i++) scanf("%d", &d[i]);
	int ans=d[0];
	for (int i=1; i<N; i++){
		if (d[i-1]<d[i]) ans+=d[i]-d[i-1];
	}
	printf("%d", ans);
	fclose(stdout);
	return 0;
}