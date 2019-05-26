#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<cstring>
#include<string>
#define ll long long int
#define INF 0x3f3f3f3f 
#define MAXN 100005
using namespace std;

ll n;
ll d[MAXN];
ll ansn=0;
int cur=1;

inline ll lowbit(int x){
	return x&(-x);
}

inline void add(ll x,ll k){
	while(x<=n){
		d[x]+=k;
		x+=lowbit(x);
	}
}

inline ll query(ll x){
	ll ans=0;
	while(x>0){
		ans+=d[x];
		x-=lowbit(x);
	}
	return ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int now,last=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&now);
		add(i,now-last);
		last=now;
	}
	//for(int i=1;i<=n;i++)printf("%d ",query(i));
	ll l,r,mid,ans,num=INF;
	while(cur<=n){
		l=cur,r=n;
		while(l<=r){
			mid=(l+r)>>1;
			if(query(mid)>0){
				ans=mid;
				num=min(query(mid),num);
				l=mid+1;
			}
			else r=mid-1;
		}
		add(cur,-num);
		add(ans+1,num);
		ansn+=num;
		while(query(cur)==0){
			cur++;
		}
		//for(int i=1;i<=n;i++) printf("%d ",query(i));
		//printf("\n");
	}
	printf("%lld",ansn);
}
