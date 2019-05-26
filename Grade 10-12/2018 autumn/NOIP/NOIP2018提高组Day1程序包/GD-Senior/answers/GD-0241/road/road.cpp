#include<iostream>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
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
struct seg{
	int l,r;
	inline bool operator <(const seg &b)const{
		return r<b.l;
	}
};
set<seg>s;
int n,a[100010],rk[100010];
inline bool cmp(int l,int r){
	return a[l]<a[r];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	int i;set<seg>::iterator it;
	for(i=1;i<=n;i++){
		a[i]=read();
		rk[i]=i;
	}
	sort(rk+1,rk+n+1,cmp);
	int cur=0,ans=0,curl,curr;s.insert((seg){1,n});
	for(i=1;i<=n;i++){
		ans+=(a[rk[i]]-cur)*s.size();
		cur=a[rk[i]];
		
		it=s.lower_bound((seg){rk[i],rk[i]});
		curl=it->l;
		curr=it->r;
		s.erase(it);
		
		if(curl<rk[i]) s.insert((seg){curl,rk[i]-1});
		if(curr>rk[i]) s.insert((seg){rk[i]+1,curr});
	}
	cout<<ans<<'\n';
	return 0;
}
