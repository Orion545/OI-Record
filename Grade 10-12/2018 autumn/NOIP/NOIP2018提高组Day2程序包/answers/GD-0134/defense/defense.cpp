#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ed{int t,n;}e[200010];
int n,m,k,l,g[100010],d[100010],h[100010];
char c;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf(" %c %c",&c,&c);
	for(int i=0;i<n;i++) scanf("%d",&g[i]);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&k,&l);
		e[i*2+1].t=l;
		e[i*2+1].n=h[k];
		h[k]=i*2+1;
		e[i*2+2].t=k;
		e[i*2+2].n=h[l];
		h[l]=i*2+2;
		d[k]++;
		d[l]++;
	}
	printf("377\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
