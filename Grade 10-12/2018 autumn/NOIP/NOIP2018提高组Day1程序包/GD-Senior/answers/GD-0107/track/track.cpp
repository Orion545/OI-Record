#include <cstdio>
#include <algorithm>
using namespace std;
#define mid ((L+R+1)>>1)
#define N 100050
int n,m,a[N],b[N],l[N],ln[N];
int P1(int pos) {
	int i,j,mx=1LL<<31-1;
	for (j=1;l[j]<pos && j<n;j+=2) ;
//	printf("%d\n",j);
	for (i=1;i<j;i++) if (l[i]+l[j-i]<pos) return 0;
//	printf("%d\n",(j-1)/2+n-j);
	if ((j-1)/2+n-j>=m) return 1; return 0;
}
int P2(int pos) {
	int i,len=0,cnt=0;
	for (i=1;i<=n;i++) {
		if (len>=pos) cnt++,len=0;
		len+=ln[i];
	}
	if (cnt>=m) return 1; return 0;
}
int main() {
	int p1=0,p2=0,i,L,R;
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<n;i++) {
		scanf("%d%d%d",&a[i],&b[i],&l[i]);
		if (a[i]!=1) p1=1;
		if (b[i]!=a[i]+1) p2=1;
	}
	if (!p2) {
		for (i=1;i<=n;i++) ln[a[i]]=l[i];
		L=1LL<<31-1; R=0; 
//		printf("LR:%d %d\n",L,R);
		for (i=1;i<n;i++) L=min(L,l[i]),R=R+l[i];
//		printf("LR:%d %d\n",L,R);
		for (i=1;i<=40;i++) {
//			printf("LR:%d %d\n",L,R);
			if (P2(mid)) L=mid; else R=mid-1;
		}
		printf("%d\n",L);
	}
	if (!p1) {
		sort(l+1,l+n); 
		L=1LL<<31-1; R=0; 
		for (i=1;i<n;i++) L=min(L,l[i]),R=R+l[i];
//		printf("LR:%d %d\n",L,R);
		for (i=1;i<=40;i++) {
//			printf("LR:%d %d\n",L,R);
			if (P1(mid)) L=mid; else R=mid-1;
		}
		printf("%d\n",L);
//		printf("%d\n",P1(8));
	}
}
