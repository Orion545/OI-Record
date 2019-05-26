#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

#define N (100+5)
#define A (25000+5)

using namespace std;

int t,a[N];
int f[A];
bool cmp(const int&a,const int&b){
	return a<b;
}
void sub(){
	int i,ans,am,n,j;
	memset(f,0,sizeof f);
	f[0]=1;
	ans=0;
	am=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]>am) am=a[i];
	}
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=n;i++)
		if (!f[a[i]]) {
			ans++;
			for (j=0;j<=am-a[i];j++) if (f[j]) f[j+a[i]]=1;
		}
	printf("%d\n",ans);
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int i;
	scanf("%d",&t);
	for (i=1;i<=t;i++)sub();
	return 0;
}
