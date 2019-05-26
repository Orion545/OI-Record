#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,l[50010],r[50010],d[50010];

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool bo=true;
	for (int i=1;i<=n-1;i++) {
		scanf("%d%d%d",&l[i],&r[i],&d[i]);
		if (l[i]!=1) bo=false;
	}
	if (bo) {
		sort(d+1,d+n+1);
		printf("%d\n",d[n-m+1]);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
