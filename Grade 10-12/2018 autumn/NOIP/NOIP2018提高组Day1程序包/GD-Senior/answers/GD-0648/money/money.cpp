#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int readq(){
	int j=0,op=1;
	char c=getchar();
	while ((c<'0'||c>'9')&&c!='-') c=getchar();
	if (c=='-'){
		op=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9'){
		j=(j<<3)+(j<<1)+(c^48);
		c=getchar();
	}
	return op*j;
}
#define M 25005
#define N 110
int p[M],q[M],T;
int n,a[N],limit,ans;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=readq();
	while (T--){
		p[0]=T+100;
		n=readq();
		for (int i=1;i<=n;i++){
			a[i]=readq();
			limit=max(limit,a[i]);
		}
		for (int j=0;j<=limit;j++) q[j]=0;
		for (int i=1,j;i<=n;i++)
			for (j=0;j+a[i]<=limit;j++)
				if (p[j]==T+100){
					p[j+a[i]]=T+100;
					q[j+a[i]]++;
				}
		ans=n;
		for (int i=1;i<=n;i++)
			if (q[a[i]]>1) ans--;
		printf("%d\n",ans);
	}
	return 0;
}
