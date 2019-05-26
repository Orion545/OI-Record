#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define Maxn 300
#define Maxm 80000
using namespace std;
bool cmp (int x,int y) {
	return x<y;
}
int a[Maxn],f[Maxm];
char v[Maxm],ans[Maxm];
int main ()
{
	freopen("money.in", "r", stdin);
	freopen("money.out","w",stdout);
	int T;
	for(cin>>T;T>0;T--)
	{
		int n; cin>>n;
		if (n==2) {
			int x,y;
			scanf("%d%d", &x, &y);
			if (x%y==0 || y%x==0)
			    printf("1\n");
			else printf("2\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		    scanf("%d", &a[i]);
		sort(a+1, a+n+1, cmp);
		memset(v, 0, sizeof(v));
		for(int i=1;i<=n;i++)
		    v[a[i]]=1, f[i]=a[i], ans[a[i]]=1;
		for(int i=1,k=n;i<=k;i++)
		    for(int j=1,x=f[i]+a[j];j<=n && x<=a[n];j++,x=f[i]+a[j])
		        if (ans[a[j]]) {
		        	if (!v[x]) v[x]=1, f[++k]=x;
		        	if (ans[x]) ans[x]=0;
		        }
		int res=0;
		for(int i=1;i<=n;i++)
		    if (ans[a[i]]) res++;
		printf("%d", res); cout<<endl;
	}
	return 0;
}
