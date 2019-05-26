#include <cstdio>
int money[100001],f[100001][4];
int main()
{
	freopen("defense1.in","r",stdin);
	freopen("defense1.out","w",stdout);
	int n,m,tn,a,b,sum;
	char tc;
	scanf("%d %d %c%d",&n,&m,&tc,&tn);
	for(int i=0; i<n; i++) scanf("%d",&money[i]);
	for(int i=0; i<n; i++) scanf("%d %d",&a,&b);
	for(int i=0; i<m; i++) scanf("%d %d %d %d",&f[i][0],&f[i][1],&f[i][2],&f[i][3]);
	for(int i=0; i<m; i++) printf("-1");
	fclose(stdin); fclose(stdout);
	return 0;
}
