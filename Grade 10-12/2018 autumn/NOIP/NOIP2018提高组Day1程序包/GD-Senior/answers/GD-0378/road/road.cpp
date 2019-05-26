#include<iostream>
#include<cstdio>
#define MAXN 100005
using namespace std;
int a[MAXN];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++) {
		if(a[i]>0) {
			int t=a[i],p=i;
			ans+=t;
			while(a[p]>0&&p<=n) {
				if(a[p]>=t) a[p]-=t;
				else {
					t=a[p];a[p]=0;
				} 
				p++;
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
