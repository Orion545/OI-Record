#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=3e4+5;
int a[maxn],bz[maxn];
int n,i,t,j,k,l,x,y,z,num,ans;
int main(){
	freopen("money.in","r",stdin);freopen("money.out","w",stdout);
	scanf("%d",&num);
	while (num--){
		scanf("%d",&n);
		for (i=1;i<=n;i++)scanf("%d",&a[i]);ans=0;
		sort(a+1,a+n+1);memset(bz,0,sizeof(bz));bz[0]=1;
		for (i=1;i<=n;i++){
			if (bz[a[i]]) continue;
			ans++;
			for (j=0;j<=a[n]-a[i];j++) 
				if (bz[j]) bz[j+a[i]]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
