#include<cstdio>
#include<algorithm>
using namespace std;
int a[2000],n,t;

bool cmp(int x,int y){
	return x<y;
}

bool ss(int w,int su){
	if (su==a[w]) return true;
	for (int i=w-1;i>=1;i--)
		if (su+a[i]<=a[w])
			if (ss(w,su+a[i]))
				return true;
	return false;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		scanf("%d",&n);
		for (int j=1;j<=n;j++)
			scanf("%d",&a[j]);
		int ans=n;
		sort(a+1,a+n+1,cmp);
		for (int j=2;j<=n;j++)
			if (ss(j,0)) ans--;
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
}
