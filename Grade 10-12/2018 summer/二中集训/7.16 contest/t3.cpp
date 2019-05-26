#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<map>
#include<queue>
#define mp make_pair
#define ll long long
#define GET(A) a[A]+lazy[A]
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
int ch[30000010][2],pos[30000010];ll a[30000010],lazy[30000010],cnt;
void update(ll cur,ll p,ll add){
	if(~p) a[ch[cur][p]]+=add;
	cout<<"		update "<<cur<<' '<<p<<' '<<add<<' '<<GET(ch[cur][0])<<' '<<GET(ch[cur][1])<<'\n';
	if(GET(ch[cur][0])>GET(ch[cur][1])) a[cur]=GET(ch[cur][0]),pos[cur]=pos[ch[cur][0]];
	else{
		if(GET(ch[cur][0])<GET(ch[cur][1])) a[cur]=GET(ch[cur][1]),pos[cur]=pos[ch[cur][1]];
		else a[cur]=GET(ch[cur][1]),pos[cur]=max(pos[ch[cur][1]],pos[ch[cur][0]]);	
	}
	cout<<"		finish update "<<cur<<' '<<a[cur]<<'\n';
	if(~p) a[ch[cur][p]]-=add;
}
ll build(ll l,ll r){
	ll mid=(l+r)>>1,cur=++cnt;
	if(l==r){pos[cur]=l;return cur;}
	ch[cur][0]=build(l,mid);ch[cur][1]=build(mid+1,r);
	update(cur,-1,0);return cur;
}
ll insert(ll l,ll r,ll ql,ll qr,ll pre,ll val){
	ll mid=(l+r)>>1,cur=++cnt;
	cout<<"	insert "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<cur<<' '<<pre<<' '<<val<<' '<<'\n';
	assert(ql<=qr);
	ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
	a[cur]=a[pre];lazy[cur]=lazy[pre];pos[cur]=pos[pre];
	if(l==ql&&r==qr){lazy[cur]+=val;/*cout<<"		bottom "<<a[cur]<<'\n';*/return cur;}
	if(mid>=qr){
		ch[cur][0]=insert(l,mid,ql,qr,ch[pre][0],val);
		update(cur,-1,0);
	}
	else{
		if(mid<ql){
			ch[cur][1]=insert(mid+1,r,ql,qr,ch[pre][1],val);
			update(cur,-1,0);
		}
		else{
			ch[cur][0]=insert(l,mid,ql,mid,ch[pre][0],val);
			ch[cur][1]=insert(mid+1,r,mid+1,qr,ch[pre][1],val);
			update(cur,-1,0);
		} 
	}
	return cur;
} 
pair<ll,ll> query(ll l,ll r,ll ql,ll qr,ll cur,ll tadd){
	cout<<"	query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<cur<<' '<<tadd<<' '<<a[cur]<<' '<<lazy[cur]<<'\n';
	assert(ql<=qr);
	ll mid=(l+r)>>1;pair<ll,ll>re,t1,t2;
	if(l==ql&&r==qr) return mp(a[cur]+lazy[cur]+tadd,pos[cur]);
	if(mid>=qr) re=query(l,mid,ql,qr,ch[cur][0],tadd+lazy[cur]);
	else{
		if(mid<ql) re=query(mid+1,r,ql,qr,ch[cur][1],tadd+lazy[cur]);
		else{
			t1=query(l,mid,ql,mid,ch[cur][0],tadd+lazy[cur]);
			t2=max(re,query(mid+1,r,mid+1,qr,ch[cur][1],tadd+lazy[cur]));
			if(t1.first>=t2.first) re=t1;
			else re=t2;
		}
	}
	cout<<"	query return "<<l<<' '<<r<<' '<<re.first<<' '<<re.second<<'\n';
	return re;
}
struct node{
	ll val,rt,l,r,mid;
};
inline bool operator <(node l,node r){
	return l.val<r.val;
}
priority_queue<node>q;
ll n,k,rt[100010],x[100010],pre[100010],first[100010],cntm;map<ll,ll>m;
int main(){
	n=read();k=read();ll i,t1;pair<ll,ll>tmp;node u;
	rt[0]=build(1,n);
	for(i=1;i<=n;i++){
		t1=read();if(!m[t1]) m[t1]=++cntm;
		pre[i]=first[m[t1]];first[m[t1]]=i;
		x[i]=t1;
//		cout<<"finish read "<<i<<"\n";
	}
//	cout<<"finish read in\n";
	for(i=1;i<=n;i++){
		rt[i]=insert(1,n,pre[i]+1,i,rt[i-1],x[i]);
		tmp=query(1,n,1,i,rt[i],0);
		cout<<"get return "<<tmp.first<<' '<<tmp.second<<'\n';
		q.push((node){tmp.first,rt[i],1,i,tmp.second});
	}
	while(--k){
		u=q.top();q.pop();
//		cout<<"get top "<<u.l<<' '<<u.mid<<' '<<u.r<<' '<<u.val<<'\n';
		if(u.mid>u.l){
			tmp=query(1,n,u.l,u.mid-1,u.rt,0);
			q.push((node){tmp.first,u.rt,u.l,u.mid-1,tmp.second});
		}
		if(u.mid<u.r){
			tmp=query(1,n,u.mid+1,u.r,u.rt,0);
			q.push((node){tmp.first,u.rt,u.mid+1,u.r,tmp.second});
		}
	}
	printf("%lld\n",q.top().val);
} 
/*
7 5
3 -2 1 2 2 1 3

8 5
-1 -1 -1 -1 -1 -1 -1 -1

*/
