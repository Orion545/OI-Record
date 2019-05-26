#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>
#define INF 2147483647
using namespace std;
int a[110],jud[25100],Min,Max;
bool _cmp(int a,int b)
{
	return a<b;
}
typedef long long ll;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (;t--;)
	 {
	 	int n;
	 	
	 	scanf("%d",&n);
	 	int ans=n;
	 	for (int i=1;i<=n;i++)
	 	 scanf("%d",&a[i]);
	 	sort(a+1,a+n+1,_cmp);
	 	Min=a[1]; Max=a[n];
	 	memset(jud,0,sizeof jud);
		for (int i=1;i<=n;i++)
		 {
		 	if (jud[a[i]]) {ans--; continue;}
		 	bool flag=true;
		 	for (int j=Min;j<=a[i]-1;j++)
		 	 if (jud[j] && jud[a[i]-j]) {flag=false; break;}
		 	if (!flag) {ans--;jud[a[i]]=1;continue;}
		 	for (int j=1;j<=Max/a[i];j++)
		 	 jud[a[i]*j]=1;
		 }
		printf("%d\n",ans);
		 
		 
	 }
	return 0;
}
