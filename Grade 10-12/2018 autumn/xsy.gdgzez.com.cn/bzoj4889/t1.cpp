#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cassert>
#include<queue>
#define ll long long
#define MOD 1000000007
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
int n,m;
struct ele{
	int num;ll val;
	ele(){num=val=0;}
	ele(int nn,ll vv){num=nn,val=vv;}
	inline ele operator +(const ele &b){return ele(num+b.num,val+b.val);}
};
namespace ctrl{
	int cnt;queue<int>q;
	int newnode(){
		if(!q.empty()){int tmp=q.front();q.pop();return tmp;}
		else return ++cnt;
	}
	void del(int num){
		q.push(num);
	}
}
//inner
namespace seg{
	ll a[8000010];int num[8000010],ch[8000010][2];
	int pos,f,ql,qr;ll val;
	void insert(int &cur,const int l,const int r){
		if(!cur) cur=ctrl::newnode();
		num[cur]+=f;(a[cur]+=val*f)%=MOD;
//		cout<<"	lower insert "<<l<<' '<<r<<' '<<pos<<' '<<f<<' '<<val<<' '<<num[cur]<<' '<<a[cur]<<'\n';
		assert((num[cur]==0)==(a[cur]==0));
		if(l==r){
			if(!num[cur]&&!a[cur]){
				ch[cur][0]=ch[cur][1]=0;
				ctrl::del(cur);
				cur=0;
			}
			return;
		}
		int mid=(l+r)>>1;
		if(mid>=pos) insert(ch[cur][0],l,mid);
		else insert(ch[cur][1],mid+1,r);
		if(!num[cur]&&!a[cur]){
			ch[cur][0]=ch[cur][1]=0;
			ctrl::del(cur);
			cur=0;
		}
	}
	ele query(const int cur,const int l,const int r){
//		cout<<"	lower query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num[cur]<<' '<<a[cur]<<'\n';
		if(!cur) return ele(0,0);
		if(l>=ql&&r<=qr) return ele(num[cur],a[cur]);
		const int mid=(l+r)>>1;ele re;
		if(mid>=ql) re=re+query(ch[cur][0],l,mid);
		if(mid<qr) re=re+query(ch[cur][1],mid+1,r);
		return re;
	}
}
//outer
namespace SEG{
	int root[400010];
	int pos,val,page,f,ql,qr,qx,qy;
	void insert(const int l,const int r,const int num){
//		cout<<"upper insert "<<l<<' '<<r<<' '<<pos<<' '<<val<<' '<<page<<' '<<f<<'\n';
		seg::val=page;seg::pos=val;seg::f=f;
		seg::insert(root[num],1,n);
		if(l==r) return;
		int mid=(l+r)>>1;
		if(mid>=pos) insert(l,mid,num<<1);
		else insert(mid+1,r,num<<1|1);
	}
	ele query(const int l,const int r,const int num){
//		cout<<"upper query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<qx<<' '<<qy<<'\n';
		if(l>=ql&&r<=qr){
			seg::ql=qx;seg::qr=qy;
			return seg::query(root[num],1,n);
		}
		const int mid=(l+r)>>1;ele re;
		if(mid>=ql) re=re+query(l,mid,num<<1);
		if(mid<qr) re=re+query(mid+1,r,num<<1|1);
		re.val%=MOD;
//		cout<<"finish upper query "<<l<<' '<<r<<' '<<re.num<<' '<<re.val<<'\n';
		return re;
	}
}
int rk[100010];ll ans,v[100010];
int main(){
	using namespace SEG;
	n=read();m=read();int i,t1,t2,minn,maxn;ele tmp;
	for(i=1;i<=n;i++){
		rk[i]=read();v[i]=read();
		ql=1;qr=i-1;qx=rk[i]+1;qy=n;
		if(qr>=ql&&qy>=qx){
			tmp=query(1,n,1);
			(ans+=(tmp.val+(ll)tmp.num*v[i])%MOD)%=MOD;
		}
		pos=i;val=rk[i];page=v[i];f=1;
		insert(1,n,1);
	}
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		if(t1>t2) swap(t1,t2);
		if(t1==t2){printf("%lld\n",ans);continue;}
		minn=min(rk[t1],rk[t2]);
		maxn=max(rk[t1],rk[t2]);
		(ans+=((minn==rk[t1])?1:-1)*(v[t1]+v[t2]))%=MOD;
		
		ql=t1;qr=t2;qx=minn+1,qy=maxn-1;
		if(qy>=qx){
			tmp=query(1,n,1);
			(ans+=((minn==rk[t1])?1:-1)*((tmp.val*2ll+(v[t1]+v[t2])*(ll)tmp.num)%MOD))%=MOD;
		}

		ql=t1;qr=t2;qx=1;qy=minn-1;
		if(qy>=qx){
			tmp=query(1,n,1);
			(ans+=(ll)tmp.num*(v[t2]-v[t1])%MOD)%=MOD;
		}
		ql=t1;qr=t2;qx=maxn+1,qy=n;
		if(qy>=qx){
			tmp=query(1,n,1);
			(ans+=(ll)tmp.num*(v[t1]-v[t2])%MOD)%=MOD;
		}

		if(ans<0) ans+=MOD;

		pos=t1;val=rk[t1];page=v[t1];f=-1;
//		cout<<"****	del t1 "<<t1<<' '<<rk[t1]<<' '<<v[t1]<<' '<<f<<'\n';
		insert(1,n,1);
		pos=t2;val=rk[t2];page=v[t2];f=-1;
		insert(1,n,1);

		swap(rk[t1],rk[t2]);swap(v[t1],v[t2]);

		pos=t1;val=rk[t1];page=v[t1];f=1;
		insert(1,n,1);
		pos=t2;val=rk[t2];page=v[t2];f=1;
		insert(1,n,1);

		printf("%lld\n",ans);
	}
}
