#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#define inf 105
#define infm 25005
using namespace std;
int n;
int a[inf],p[inf];

int gcd(int x,int y){
	if (!y){
		return x;
	}
	return gcd(y,x%y);
}

int f[inf][infm];

bool check(int id){
	int maxv=a[id];
	memset(f,0,sizeof(f));
	/*for (int i=0;i<id;i++){
		f[i][0]=1;
	}*/
	f[0][0]=1;
	for (int i=1;i<id;i++){
		for (int j=0;j<=maxv;j++){
			if (f[i][j]){
				continue;
			}
			for (int k=0;j>=k*a[i];k++){
				f[i][j]|=f[i-1][j-a[i]*k];
				if (f[i][j]){
					break;
				}
			}
		}
	}
	return f[id-1][a[id]];
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int Task;
	scanf("%d",&Task);
	for (int T=1;T<=Task;T++){
		memset(p,0,sizeof(p));
		scanf("%d",&n);
		int maxv=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			maxv=max(maxv,a[i]);
		}
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (a[j]%a[i]==0){
					p[j]=1;
				}
				if (gcd(a[i],a[j])==1 && a[i]*a[j]-a[i]-a[j]+1>=maxv){
					maxv=a[i]*a[j]-a[i]-a[j]+1;
					for (int k=j+1;k<=n;k++){
						if (a[k]>=a[i]*a[j]-a[i]-a[j]+1){
							p[k]=1;
						}
					}
				}
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			if (a[i]<a[1]*2 || (!p[i] && !check(i))){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
16
27 29 15 28 26 8 18 21 10 22 30 20 16 25 23 7
*/
