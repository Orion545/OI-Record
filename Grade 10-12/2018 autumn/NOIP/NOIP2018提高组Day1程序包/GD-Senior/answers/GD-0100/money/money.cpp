#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9+7;
int n,a[110],c[25010],p;
bool f[25010],f1[25010];
int vis[25010],tim=0;
bool cmp(int a,int b) {return a>b;}
int gcd(int a,int b) {return a==0?b:gcd(b%a,a);}
void solve(int *c,bool *f,int *a,int n)
{
	/*p=a[1];c[0]=1;
	for(int i=1;i<p;i++) c[i]=inf;
	//for(int i=0;i<p;i++) printf("%d ",c[i]);printf("\n");
	for(int i=2;i<=n;i++) change(a[i],c);*/
	for(int i=0;i<=10000;i++) f[i]=false;
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=10000-a[i];j++) if(f[j]) f[j+a[i]]=true;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n==1) {printf("1\n");continue;}
		int d=a[1];
		for(int i=2;i<=n;i++) d=gcd(d,a[i]);
		for(int i=1;i<=n;i++) a[i]/=d;
		if(n==2)
		{
			if(a[1]==1||a[2]==1) {printf("1\n");continue;}
			printf("2\n");continue;
		}
		for(int i=1;i<=n;i++) if(a[i]==1) {printf("1\n");break;}
		sort(a+1,a+n+1,cmp);
		solve(c,f,a,n);
		bool flag=false;
		for(int i=2;i<=30;i++)
			for(int j=2;j<=30;j++)
			{
				int d=gcd(i,j);
				if(d!=1) continue;
				a[1]=i;a[2]=j;
				bool ty=true;
				solve(c,f1,a,2);
				for(int k=0;k<=10000;k++) if(f[k]!=f1[k]) ty=false;
				if(ty) flag=true;
			}
		if(flag) printf("2\n");
		else printf("%d\n",n);
		//for(int i=0;i<p;i++) printf("%d ",c[i]);
		//printf("\n");
	}
}
