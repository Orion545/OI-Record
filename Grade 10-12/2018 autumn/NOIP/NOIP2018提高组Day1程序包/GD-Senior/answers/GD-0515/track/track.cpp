#include<iostream>
#include<stdio.h>
#include<string.h>
#include<set>
#define N 120000
using namespace std;
int tot,Next[N],v[N],w[N],h[N],f[N];
int ans,n,m;
multiset<int>S[N];
int add(int x,int y,int z){
	tot++;
	Next[tot]=h[x];
	v[tot]=y;
	w[tot]=z;
	h[x]=tot;
}
int dfs(int x,int fa,int O){
	for(int i=h[x];i;i=Next[i]){
		if(v[i]==fa)continue;
		f[v[i]]=w[i];
		dfs(v[i],x,O);
		S[x].insert(f[v[i]]);
	}
	int bns=0;
	int X,Y;
	while(!S[x].empty()){
		X=*S[x].begin();
		S[x].erase(S[x].begin());
		multiset<int>::iterator it;
		it=S[x].lower_bound(O-X);
		if(it==S[x].end())Y=-1000000000;
		else Y=*it;
		if(X+Y<O){
			bns=max(X,bns);
		}else{
			S[x].erase(it);
			ans++;
		}
	}
	if(f[x]+bns>=O){
		f[x]=0;
		bns=0;
		ans++;
	}
	f[x]+=bns;
}
int check(int x){
//	printf("%d\n",x);
	memset(f,0,sizeof(f));
	ans=0;
	dfs(1,0,x);
	return ans>=m;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	int l=0,r=1000000000;
	while(r-l>=3){
		int mid=(0LL+l+r)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	for(int i=r;i>=l;i--){
		if(check(i)){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
