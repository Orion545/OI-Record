#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll n,m,q,ask;
struct node{
	ll type,w,pos;
	inline bool operator <(const node &b){
		if(pos!=b.pos) return pos<b.pos;
		return type<b.type;
	}
}a[1500010],t[1500010];
ll ans[1500010];
void cdq(ll l,ll r){
	if(l==r) return;
	ll mid=(l+r)>>1,i=l,j=mid+1,p=l,sum=0;
	cdq(l,mid);cdq(mid+1,r);
	while(i<=mid&&j<=r){
		if(a[i]<a[j]){
			if(a[i].type==1) sum+=a[i].w;
			t[p++]=a[i++];
		}
		else{
			if(a[j].type==2) 
			ans[a[j].w]-=sum;
			else if(a[j].type==3) ans[a[j].w]+=sum;
			t[p++]=a[j++];
		}
	}
	while(i<=mid) sum+=a[i].w,t[p++]=a[i++];
	while(j<=r){
		if(a[j].type==2) ans[a[j].w]-=sum;
		else if(a[j].type==3) ans[a[j].w]+=sum;
		t[p++]=a[j++];
	}
	for(i=l;i<=r;i++) a[i]=t[i];
	
}
int main(){
	n=read();m=read();q=ask=0;ll i,t1,t2,t3;
	for(i=1;i<=n;i++){
		t1=read();q++;
		a[q].type=1;a[q].w=t1;a[q].pos=i;
	}
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		if(t1==2){
			q++;ask++;
			a[q].type=2;a[q].w=ask;a[q].pos=t2-1;
			q++;
			a[q].type=3;a[q].w=ask;a[q].pos=t3;
		}
		else{
			q++;
			a[q].type=1;a[q].w=t3;a[q].pos=t2;
		}
	}
	cdq(1,q);
	for(i=1;i<=ask;i++) printf("%lld\n",ans[i]);
}
