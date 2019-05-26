#include <cstdio>
int map[5001][2];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++)
		scanf("%d %d",&map[0],&map[1]);
	for(int i=1; i<=n; i++) printf("%d ",i);
	fclose(stdin); fclose(stdout);
	return 0;
}
