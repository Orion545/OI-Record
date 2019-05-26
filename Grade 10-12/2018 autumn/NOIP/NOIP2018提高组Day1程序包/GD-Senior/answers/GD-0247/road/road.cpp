#include<cstdio>
#define maxn 1000100
int num[maxn];
int ans=0;

void judge() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}

int min(int a,int b) {
	return a<b?a:b;
}

int solve(int l,int r) {
	if(l==r) {
		return num[l];
	}
	int mid=(l+r)/2;
	return solve(l,mid)+solve(mid+1,r)-min(num[mid],num[mid+1]);
}

int main() {
	judge();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&num[i]);
	}
	printf("%d",solve(1,n));
}

