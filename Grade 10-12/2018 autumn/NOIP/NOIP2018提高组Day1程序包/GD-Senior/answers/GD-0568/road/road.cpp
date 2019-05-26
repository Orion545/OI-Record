//#define DEBUG
#include <cstdio>
#define MAXN 100000

using namespace std;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n, d, od=0, ans=0;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
	scanf("%d", &d);
	d>od ? ans+=d-od : 0;
	od = d;
    }

    printf("%d", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
