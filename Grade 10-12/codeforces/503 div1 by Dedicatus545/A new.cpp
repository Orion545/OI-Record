#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<queue>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,p[3010],c[3010];
priority_queue<ll,vector<ll>,greater<ll> >q[3010]; 
ll t[3010],cnt;
int main(){
	n=read();m=read();ll i,lim=0,ans=1e15,tmp,ori=0,cur;
	for(i=1;i<=n;i++){
		p[i]=read(),c[i]=read();
		if(p[i]==1) lim++,ori++;
	}
	for(;lim<=n;lim++){
//		cout<<"lim "<<lim<<'\n';
		tmp=0;cur=ori;
		for(i=1;i<=n;i++){
			if(p[i]!=1) q[p[i]].push(c[i]);
		}
		for(i=2;i<=m;i++) while(q[i].size()>=lim&&q[i].size()) tmp+=q[i].top(),q[i].pop(),cur++;
		cnt=0;
		for(i=2;i<=m;i++) while(q[i].size()) t[++cnt]=q[i].top(),q[i].pop();
		sort(t+1,t+cnt+1);cnt=1;
		while(cur<lim) tmp+=t[cnt++],cur++;
		ans=min(ans,tmp);
	}
	cout<<ans<<'\n';
}

