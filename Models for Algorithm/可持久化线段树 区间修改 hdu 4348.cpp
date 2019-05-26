#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lld long long
using namespace std;
lld x[100010],a[3000010];
int n,m,cnt,times,l[3000010],r[3000010],lazy[3000010],rt[100010];
void update(int ll,int rr,int x){
	a[x]=a[l[x]]+a[r[x]]+(lld)(rr-ll+1)*lazy[x];
}
void build(int &now,int ll,int rr){
	int mid=(ll+rr)>>1;
	now=++cnt;
	lazy[now]=0;a[now]=0;
	if(ll==rr){
		a[now]=x[ll];return;
	}
	build(l[now],ll,mid);build(r[now],mid+1,rr);
	update(ll,rr,now);
}
void change(int &now,int pre,int ll,int rr,int ql,int qr,int d){
	int mid=(ll+rr)>>1;
	now=++cnt;
//	cout<<"change "<<now<<ends<<pre<<ends<<ll<<ends<<rr<<ends<<ql<<ends<<qr<<endl;
	a[now]=a[pre];l[now]=l[pre];r[now]=r[pre];lazy[now]=lazy[pre];
	if(ll==ql&&rr==qr){
		a[now]+=(lld)(rr-ll+1)*d;lazy[now]+=d;return;
	}
	if(qr<=mid) change(l[now],l[pre],ll,mid,ql,qr,d);
	else{
		if(ql>mid) change(r[now],r[pre],mid+1,rr,ql,qr,d);
		else{
			change(l[now],l[pre],ll,mid,ql,mid,d);
			change(r[now],r[pre],mid+1,rr,mid+1,qr,d);
		}
	}
	update(ll,rr,now);
}
lld query(int now,int ll,int rr,int ql,int qr){
//	cout<<"query "<<now<<ends<<ll<<ends<<rr<<ends<<ql<<ends<<qr<<endl;
//	if(now==0) system("pause");
	int mid=(ll+rr)>>1;lld ans=(lld)(qr-ql+1)*lazy[now];
	if(ll==ql&&rr==qr) return a[now];
	if(qr<=mid) ans+=query(l[now],ll,mid,ql,qr);
	else{
		if(ql>mid) ans+=query(r[now],mid+1,rr,ql,qr);
		else ans+=query(l[now],ll,mid,ql,mid)+query(r[now],mid+1,rr,mid+1,qr);
	}
	return ans;
}
int main(){
	int i,t1,t2,t4;lld t3;char s[10];
	bool f=0;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(f) puts("");
		else f=1;
		memset(x,0,sizeof(x));memset(a,0,sizeof(a));
		memset(l,0,sizeof(l));memset(r,0,sizeof(r));
		memset(rt,0,sizeof(rt));memset(lazy,0,sizeof(lazy));
		cnt=0;times=0;
		for(i=1;i<=n;i++) scanf("%lld",&x[i]);
		build(rt[0],1,n);
		for(i=1;i<=m;i++){
			scanf("%s",s);
			if(s[0]=='C'){
				scanf("%d%d%lld",&t1,&t2,&t3);
				change(rt[times+1],rt[times],1,n,t1,t2,t3);
				times++;
			}
			if(s[0]=='Q'){
				scanf("%d%d",&t1,&t2);
				printf("%lld\n",query(rt[times],1,n,t1,t2));
			}
			if(s[0]=='H'){
				scanf("%d%d%d",&t1,&t2,&t4);
				printf("%lld\n",query(rt[t4],1,n,t1,t2));
			}
			if(s[0]=='B') scanf("%d",&times);
		}
	}
}
