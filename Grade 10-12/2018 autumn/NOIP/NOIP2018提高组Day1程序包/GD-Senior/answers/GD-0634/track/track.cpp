#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,boo,a[50005],b[50005],c[50005];
int l,r,ans,Mid,i,j,k,tmp;

int check(int x){
	i=n-m,j=k=n-m+1;
	for (; j<=n; j++){
		tmp=c[j];
		while (tmp<x){
			if (i<1) return 0;
			tmp+=c[i],i--;
		}
	}
	return 1;
}

int check_(int x){
	k=0,tmp=0;
	for (i=1; i<=n; i++){
		tmp+=c[i];
		if (tmp>=x) tmp=0,k++;
	}
	return k>=m;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1; i<n; i++) scanf("%d%d%d",&a[i],&b[i],&c[i]),boo|=(a[i]!=1);
	if (!boo){
		sort(c+1,c+n);
		if (m==n-1){printf("%d",c[n]); return 0;}
		if (m==1){printf("%d",c[n]+c[n-1]); return 0;}
		for (l=1,r=500000000,Mid=(l+r)>>1; l<r; Mid=(l+r)>>1){
			boo=check(Mid);
			if (boo){ans=Mid,l=Mid+1; continue;}
			r=Mid;
		}
		printf("%d",ans);
		return 0;
	}
	for (l=1,r=500000000,Mid=(l+r)>>1; l<r; Mid=(l+r)>>1){
		boo=check_(Mid);
		if (boo){ans=Mid,l=Mid+1; continue;}
		r=Mid;
	}
	printf("%d",ans);
	return 0;
}
