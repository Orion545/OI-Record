#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define fo(i,a,b) for(i=a;i<=b;i++)

using namespace std;

const int maxn=25005;

int f[maxn*2];
int a[105];
int i,j,k,l,m,n,x,y,t,ans,mx;

int cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t>0){
		t--;
		scanf("%d",&n); mx=0;
		fo(i,1,n){
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		memset(f,0,sizeof(f));
		sort(a+1,a+n+1,cmp);
		ans=0; f[0]=1;
		fo(i,1,n) if (f[a[i]]==0){
			fo(j,0,mx) if (f[j]==1) f[j+a[i]]=1;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
