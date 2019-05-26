#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[501],d[10001],cnt,n;
bool check[501];

void work(int x){
	int k=a[n]/a[x]+1;
	for(int i=0;1<<i<k;i++){
		d[++cnt]=a[x]*(1<<i);
		k-=(1<<i);
		//printf("%d %d\n",cnt,d[cnt]);
	}
	d[++cnt]=a[x]*k;
	//printf("%d %d\n",cnt,d[cnt]);
}

void dfs(int x,int y,int t){	
	while(y>a[t])t++;
	if(y==a[t]){
		check[t]=true;
		t++;
	}
	if(t>n)return;
	for(int i=x;i<=cnt;i++){
		dfs(i+1,y+d[i],t);
	}
	return;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		cnt=0;
		memset(d,0,sizeof(d));
		memset(check,false,sizeof(check));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		work(1);
		for(int i=2;i<=n;i++){
			if(check[i])continue;
			dfs(1,0,i);
			if(!check[i])work(i);
		}
		int ans=0;
		for(int i=1;i<=n;i++)if(check[i])ans++;
		printf("%d\n",n-ans);
	}
	return 0;
}
