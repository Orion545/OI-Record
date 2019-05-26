#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int T,n;
int a[105];
bool f[105];
queue <int> q;
int max_(int x,int y){
	if (x>y) return x; else return y;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for (int u=1;u<=T;++u){
		scanf("%d",&n);
		memset(f,1,sizeof(f));
		int max_=0;
		for (int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			max_=max(max_,a[i]);
		}
		sort(a+1,a+n+1);
		f[a[1]]=0;
		q.push(a[1]);
		for (int i=2;i<=a[n]/a[1];++i) f[a[1]*i]=0;
		for (int i=2;i<=n;++i){//枚举第几个来筛 
			if (f[a[i]]) q.push(a[i]); else continue;
			for (int k=1;k<=a[n]/a[i];++k) f[a[i]*k]=0;
			int min_=a[n]-a[i];
			for (int j=a[1];j<=min_;++j){
				if (!f[j]){
					for (int k=1;k<=(a[n]-j)/a[i];++k){
						f[j+a[i]*k]=0;
					}
				}
			}
		}
		int ans=q.size();
		while (!q.empty()){
			int b=q.front(); q.pop();
			//printf("%d ",b);
		}
		printf("%d\n",ans);
	}
}
