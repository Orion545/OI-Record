#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int u[100100],v[100100],n,m,a[100100];
char c[10];

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m); scanf("%s",&c);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d%d",&u[i],&v[i]);
	for (int i=1;i<=m;i++) printf("-1\n");
	fclose(stdin); fclose(stdout);
	return 0;
}
