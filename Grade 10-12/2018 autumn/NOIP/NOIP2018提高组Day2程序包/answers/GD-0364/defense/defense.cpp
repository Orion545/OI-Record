#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m,p[2010],f[2010][2];char s[20];

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
	}
	for (int i=1;i<=m;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if ((a==c+1||c==a+1)&&b==0&&d==0) {
			printf("-1\n");
			continue;
		}
		f[0][0]=f[0][1]=0;
		for (int i=1;i<=n;i++){
			f[i][1]=min(f[i-1][1],f[i-1][0])+p[i];
			f[i][0]=f[i-1][1];
			if (i==a){
				if (b==1) f[i][0]=210000000;
				else f[i][1]=210000000;
			}
			if (i==c){
				if (d==1) f[i][0]=210000000;
				else f[i][1]=210000000;
			}
		}
		printf("%d\n",min(f[n][1],f[n][0]));
	}
	return 0;
}
