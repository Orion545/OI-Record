#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n,a[100002],m,minn[40001],maxn[40001],l[100002],r[100002];
long long ans;

void update1(int o,int l,int r,int k,int x){
	if(l==r){maxn[o]=max(maxn[o],x);return;}
	int m=l+r>>1;
	if(m>=k)update1(o<<1,l,m,k,x);else update1(o<<1|1,m+1,r,k,x);
	maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
}

void update2(int o,int l,int r,int k,int x){
	if(l==r){minn[o]=min(minn[o],x);return;}
	int m=l+r>>1;
	if(m>=k)update2(o<<1,l,m,k,x);else update2(o<<1|1,m+1,r,k,x);
	minn[o]=min(minn[o<<1],minn[o<<1|1]);
}

int query1(int o,int l,int r,int a,int b){
	if(a>b)return 0;
	if(l==a&&r==b)return maxn[o];
	int m=l+r>>1;
	if(m>=b)return query1(o<<1,l,m,a,b);else if(m<a)return query1(o<<1|1,m+1,r,a,b);
	else return max(query1(o<<1,l,m,a,m),query1(o<<1|1,m+1,r,m+1,b));
}

int query2(int o,int l,int r,int a,int b){
	if(a>b)return n+1;
	if(l==a&&r==b)return minn[o];
	int m=l+r>>1;
	if(m>=b)return query2(o<<1,l,m,a,b);else if(m<a)return query2(o<<1|1,m+1,r,a,b);
	else return min(query2(o<<1,l,m,a,m),query2(o<<1|1,m+1,r,m+1,b));
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);for(int i=1;i<=40000;++i)minn[i]=n+1;
	for(int i=1;i<=n;++i)scanf("%d",a+i),ans+=(long long)a[i];
	for(int i=1;i<=n;++i)l[i]=query1(1,1,10000,1,a[i]),update1(1,1,10000,a[i],i);
	for(int i=n;i>=1;--i)r[i]=query2(1,1,10000,1,a[i]),update2(1,1,10000,a[i],i);
	for(int i=1;i<=n;++i)if(a[i])while(a[r[i]]==a[i])r[i]=r[r[i]];
	for(int i=1;i<=n;++i)ans-=(long long)(a[i]-max(a[l[i]],a[r[i]]))*(r[i]-l[i]-2);
	printf("%lld",ans);
}
/*
6
4 3 2 5 3 5

6
3 2 1 1 2 3

6
2 1 1 2 1 3
*/
