#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int T,n,a[110];

int exgcd(int aa,int b,int &x,int &y){
	if (b==0){
		x=1;y=0;
		return aa;
	}
	int r=exgcd(b,aa%b,x,y);
	int t=x;x=y;y=t-(aa/b)*y;
	return r;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if (n==2){
			int x=min(a[1],a[2]),y=max(a[1],a[2]);
			if (y%x==0) printf("1\n");else printf("2\n");
			continue;
		}
		if (n==3){
			for (int i=1;i<=2;i++)
				for (int j=i+1;j<=3;j++)
					if (a[i]>a[j]){
						int t=a[i];a[i]=a[j];a[j]=t;
					}
			int x=a[1],y=a[2],z=a[3];
			if (y%x==0&&z%x==0){
				printf("1\n");
				continue;
			}
			if (y%x==0||z%x==0||z%y==0){
				printf("2\n");
				continue;
			}
			if (z<x+y){
				printf("3\n");
				continue;
			}
			int aa=x,b=y,c=z;x=y=z=0;
			int d;
			d=exgcd(aa,b,x,y);
			if (c%d!=0){
				printf("3\n");
				continue;
			}
			x*=(c/d),y*=(c/d);
			if (x>0&&y>0){
				printf("2\n");
				continue;
			}
			if (x>0&&y<0){
				while (y<0)
					y+=(aa/d),x-=(b/d);
				if (x>0) printf("2\n");else printf("3\n");
				continue;
			}
			else{
				while (x<0)
					x+=(b/d),y-=(aa/d);
				if (y>0) printf("2\n");else printf("3\n");
				continue;
			}
		}
	}
	return 0;
}
