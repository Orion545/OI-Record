#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
int a[233333];
int minm,n,t;
int vis[233333],f[233333];
int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
int ex_gcd(int a,int b,int &x,int &y){
	if(!b){
		x=1;
		y=0;
		return a;
	}
	int d=ex_gcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
int inv(int a,int b){
	int x,y;
	ex_gcd(a,b,x,y);
	y%=a;
	y+=a;
	y%=a;
	return y;
}
int can(int a,int b,int c){
	if(c%a==0||c%b==0)return 1;
	int g=gcd(a,b);
	if(c%g)return 0;
	a/=g,b/=g,c/=g;
	int y=inv(a,b%a);
	y*=(c%a);
	y%=a;
	return y*b<=c;
}
int solve1(){
	int ans=0;
	memset(f,0,sizeof(f));
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		for(int j=a[i-1]+1;j<=a[i];++j){
			for(int k=1;k<=j;++k)f[j]|=f[k]&&f[j-k];
		}
		ans+=!f[a[i]];
		f[a[i]]=1;
	}
	return ans;
}
signed main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int maxn=0;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			maxn=max(maxn,a[i]);
		}
		if(maxn<=1000){
			cout<<solve1()<<endl;
			continue;
		}
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)for(int k=1;k<=n;++k){
			if(k==i||k==j)continue;
			vis[k]|=can(a[i],a[j],a[k]);
		}
		int m=n;
		for(int i=1;i<=n;++i){
			m-=vis[i];
		}
		cout<<m<<endl;
	}
}
