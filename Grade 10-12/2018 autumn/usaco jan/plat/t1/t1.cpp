#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<set>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
namespace seg{
	int a[1200010];
	void build(int l,int r,int num){
		if(l==r){a[num]=1e9;return;}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);
		build(mid+1,r,num<<1|1);
		a[num]=1e9;
	}
	void change(int l,int r,int num,int pos,int val){
//		cout<<"	change "<<l<<' '<<r<<' '<<pos<<' '<<val<<'\n';
		if(l==r){a[num]=val;return;}
		int mid=(l+r)>>1;
		if(mid>=pos) change(l,mid,num<<1,pos,val);
		else change(mid+1,r,num<<1|1,pos,val);
		a[num]=min(a[num<<1],a[num<<1|1]);
	}
	int query(int l,int r,int num,int val){
//		cout<<"	query "<<l<<' '<<r<<' '<<val<<' '<<a[num]<<'\n';
		if(a[num]>val) return 0;
		if(l==r) return l;
		int mid=(l+r)>>1,re;
		re=query(l,mid,num<<1,val);
		if(re==0) return query(mid+1,r,num<<1|1,val);
	}
}
int n,m,a[300010],pre[300010],dp[300010];
char str[300010];
multiset<int>s[300010];
int main(){
	freopen("redistricting.in","r",stdin);
	freopen("redistricting.out","w",stdout);
	n=read();m=read();int i,j,t1,t2;
	seg::build(1,n+1,1);
	multiset<int>::iterator it;
	scanf("%s",str);
	for(i=0;i<n;i++){
		a[i+1]=((str[i]=='H')?1:-1);
		pre[i+1]=pre[i]+a[i+1];
	}
	dp[0]=0;
	s[0].insert(pre[0]);
	seg::change(1,n+1,1,dp[0]+1,0);
	/*
	for(i=1;i<=n;i++){
		dp[i]=1e9;
		for(j=max(0,i-m);j<i;j++){
			if(pre[i]-1>=pre[j]) dp[i]=min(dp[i],dp[j]);
			else dp[i]=min(dp[i],dp[j]+1);
		}
		cout<<i<<' '<<dp[i]<<'\n';
//		assert(dp[i]>=dp[i-1]);
	}
	*/
	for(i=1;i<=n;i++){
		t1=seg::query(1,n+1,1,n);
		t2=seg::query(1,n+1,1,pre[i]-1)-1;
		if(t2==-1) t2=1e9;
		dp[i]=min(t1,t2);

		if(s[dp[i]].size()) j=*(s[dp[i]].begin());
		else j=1e9;
		s[dp[i]].insert(pre[i]);
		if((*(s[dp[i]].begin()))<j) seg::change(1,n+1,1,dp[i]+1,*(s[dp[i]].begin()));

		if(i-m>=0){
//			cout<<"time to erase "<<i-m<<' '<<dp[i-m]<<' '<<pre[i-m]<<'\n';
			if(s[dp[i-m]].size()) j=*(s[dp[i-m]].begin());
			else j=1e9;
			it=s[dp[i-m]].find(pre[i-m]);
			s[dp[i-m]].erase(it);
//			cout<<"finish erase, comparing "<<j<<' '<<(*(s[dp[i-m]].begin()))<<'\n';
			if(!s[dp[i-m]].size()) seg::change(1,n+1,1,dp[i-m]+1,1e9);
			else if((*(s[dp[i-m]].begin()))>j) seg::change(1,n+1,1,dp[i-m]+1,*(s[dp[i-m]].begin()));
		}
//		cout<<"get dp "<<i<<' '<<dp[i]<<'\n';
	}
	cout<<dp[n]<<'\n';
}
