#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=25005;
int t,n,a[N],f[N],flag[N],ans,mx,mo[N];
bool cmp(int a,int b){
	return a<b;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t){
		t--;
		scanf("%d",&n);
		mx=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
		sort(a+1,a+n+1,cmp);
		memset(f,0,sizeof(f));
		ans=0;
		memset(flag,0,sizeof(flag));
		f[0]=1;
		for (int i=1;i<=n;i++)
		if (!flag[i]){
			ans++;
			for (int j=a[i];j<=mx;j++)
			 if (f[j-a[i]]&&!f[j]){
			 	f[j]=1;
			 	for (int k=i+1;k<=n;k++) 
			 	 if (mo[a[k]%j]||a[k]%j==0) flag[k]=1;
			 	 			else mo[a[k]%j]=1;
			 	for (int k=i+1;k<=n;k++)
			 	 mo[a[k]%j]=0;
			 } 
		}
		printf("%d\n",ans);
	}
	return 0;
}
