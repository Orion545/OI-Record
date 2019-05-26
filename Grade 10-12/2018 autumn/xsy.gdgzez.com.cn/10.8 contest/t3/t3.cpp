#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#define lc(cur) ((l+r)|(l!=r))
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
int flag;
struct MIN{int minn,sec_minn,cnt,delta;};/*{{{*/
struct MAX{int maxn,sec_maxn,cnt,delta;};
MIN operator +(MIN a,MIN b){
	assert(flag);
	MIN ans;
	ans.cnt=ans.delta=0;
	ans.minn=min(a.minn,b.minn);
	ans.sec_minn=min(a.sec_minn,b.sec_minn);
	if(a.minn!=ans.minn) ans.sec_minn=min(ans.sec_minn,a.minn);
	else ans.cnt+=a.cnt;
	if(b.minn!=ans.minn) ans.sec_minn=min(ans.sec_minn,b.minn);
	else ans.cnt+=b.cnt;
	return ans;
}
MAX operator +(MAX a,MAX b){
	assert(flag);
	MAX ans;
	ans.cnt=ans.delta=0;
	ans.maxn=max(a.maxn,b.maxn);
	ans.sec_maxn=max(a.sec_maxn,b.sec_maxn);
	if(a.maxn!=ans.maxn) ans.sec_maxn=max(ans.sec_maxn,a.maxn);
	else ans.cnt+=a.cnt;
	if(b.maxn!=ans.maxn) ans.sec_maxn=max(ans.sec_maxn,b.maxn);
	else ans.cnt+=b.cnt;
	return ans;
}/*}}}*/
namespace seg{
	int lc[1100010],rc[1100010],lazy[1100010];
	ll sum[1100010];
	MIN minn[1100010];MAX maxn[1100010];
	int n,siz=0,root=0,val[1000010];
	void update(int cur){
		assert(cur<=siz);
		assert(cur);
		if(lc[cur]==0) return;
		flag=1;
		sum[cur]=sum[lc[cur]]+sum[rc[cur]];
		minn[cur]=minn[lc[cur]]+minn[rc[cur]];
		maxn[cur]=maxn[lc[cur]]+maxn[rc[cur]];
		flag=0;
	}
	void build(int &cur,int l,int r){/*{{{*/
		cur=++siz;
//		cout<<"build "<<cur<<' '<<l<<' '<<r<<'\n';
		if(l==r){
			sum[cur]=val[l];
			minn[cur]=(MIN){val[l],(int)2e9,1,0};
			maxn[cur]=(MAX){val[l],(int)-2e9,1,0};
			return;
		}
		int mid=(l+r)>>1;
		build(lc[cur],l,mid);
		build(rc[cur],mid+1,r);
		update(cur);
	}/*}}}*/
	void addmax(int l,int r,int cur,ll val){/*{{{*/
		assert(cur<=siz);
		assert(cur);
//		cout<<"addmax "<<cur<<' '<<maxn[cur].maxn<<' '<<minn[cur].minn<<' '<<minn[cur].sec_minn<<' '<<val<<'\n';
		if(maxn[cur].maxn==minn[cur].minn){
			maxn[cur].maxn+=val;
			minn[cur].minn+=val;
			lazy[cur]+=val;
			sum[cur]+=val*(ll)(r-l+1);
			return;
		}
		if(maxn[cur].maxn==minn[cur].sec_minn){
			assert(l!=r);
			maxn[cur].maxn+=val;
			maxn[cur].delta+=val;
			if(lc[cur]) minn[cur].sec_minn+=val;
			sum[cur]+=val*(ll)maxn[cur].cnt;
			return;
		}
		maxn[cur].maxn+=val;
		maxn[cur].delta+=val;
		sum[cur]+=val*(ll)maxn[cur].cnt;
	}
	void addmin(int l,int r,int cur,ll val){
		assert(cur<=siz);
		assert(cur);
//		cout<<"addmin "<<cur<<' '<<minn[cur].minn<<' '<<maxn[cur].maxn<<' '<<maxn[cur].sec_maxn<<' '<<val<<'\n';
		if(maxn[cur].maxn==minn[cur].minn){
			minn[cur].minn+=val;
			maxn[cur].maxn+=val;
			lazy[cur]+=val;
			sum[cur]+=val*(ll)(r-l+1);
			return;
		}
		if(minn[cur].minn==maxn[cur].sec_maxn){
			minn[cur].minn+=val;
			minn[cur].delta+=val;
			if(lc[cur]) maxn[cur].sec_maxn+=val;
			sum[cur]+=val*(ll)minn[cur].cnt;
			return;
		}
		minn[cur].minn+=val;
		minn[cur].delta+=val;
		sum[cur]+=val*(ll)minn[cur].cnt;
	}/*}}}*/
	void push(int l,int r,int cur){/*{{{*/
		assert(cur<=siz);
		assert(cur);
		if(!lc[cur]) return;
		int mid=(l+r)>>1;
		if(maxn[cur].delta){
			ll tmp=maxn[cur].delta;
			if(maxn[lc[cur]].maxn==maxn[rc[cur]].maxn){
				addmax(l,mid,lc[cur],tmp);
				addmax(mid+1,r,rc[cur],tmp);
			}
			else{
				if(maxn[lc[cur]].maxn>maxn[rc[cur]].maxn) addmax(l,mid,lc[cur],tmp);
				else addmax(mid+1,r,rc[cur],tmp);
			}
			maxn[cur].delta=0;
		}
		if(minn[cur].delta){
			ll tmp=minn[cur].delta;
			if(minn[lc[cur]].minn==minn[rc[cur]].minn){
				addmin(l,mid,lc[cur],tmp);
				addmin(mid+1,r,rc[cur],tmp);
			}
			else{
				if(minn[lc[cur]].minn<minn[rc[cur]].minn) addmin(l,mid,lc[cur],tmp);
				else addmin(mid+1,r,rc[cur],tmp);
			}
			minn[cur].delta=0;
		}
		if(lazy[cur]){
			ll tmp=lazy[cur];
			int ch=lc[cur],mid=(l+r)>>1;
			maxn[ch].maxn+=tmp;
			if(lc[ch]) maxn[ch].sec_maxn+=tmp;
			minn[ch].minn+=tmp;
			if(lc[ch]) minn[ch].sec_minn+=tmp;
			lazy[ch]+=tmp;
			sum[ch]+=(ll)(mid-l+1)*tmp;
			ch=rc[cur];
			maxn[ch].maxn+=tmp;
			if(lc[ch]) maxn[ch].sec_maxn+=tmp;
			minn[ch].minn+=tmp;
			if(lc[ch]) minn[ch].sec_minn+=tmp;
			lazy[ch]+=tmp;
			sum[ch]+=(ll)(r-mid)*tmp;
			lazy[cur]=0;
		}
	}/*}}}*/
	void add(int cur,int l,int r,int ql,int qr,ll val){/*{{{*/
		assert(cur<=siz);
		assert(cur);
		if(l>=ql&&r<=qr){
			maxn[cur].maxn+=val;
			if(lc[cur]) maxn[cur].sec_maxn+=val;
			minn[cur].minn+=val;
			if(lc[cur]) minn[cur].sec_minn+=val;
			lazy[cur]+=val;
			sum[cur]+=val*(ll)(r-l+1);
			return;
		}
		int mid=(l+r)>>1;
		push(l,r,cur);
		if(mid>=ql) add(lc[cur],l,mid,ql,qr,val);
		if(mid<qr) add(rc[cur],mid+1,r,ql,qr,val);
//		assert(lazy[cur]==0&&maxn[cur].delta==0&&minn[cur].delta==0);
		update(cur);
	}/*}}}*/
	void chmax(int cur,int l,int r,ll val){/*{{{*/
		assert(cur<=siz);
		assert(cur);
		if(minn[cur].minn>=val) return;
		if(minn[cur].sec_minn>val){
			addmin(l,r,cur,val-minn[cur].minn);
			return;
		}
		int mid=(l+r)>>1;
		push(l,r,cur);
		chmax(lc[cur],l,mid,val);
		chmax(rc[cur],mid+1,r,val);
//		assert(lazy[cur]==0&&maxn[cur].delta==0&&minn[cur].delta==0);
		update(cur);
	}
	void findmax(int cur,int l,int r,int ql,int qr,ll val){
		assert(cur<=siz);
		assert(cur);
		if(minn[cur].minn>=val) return;
		if(l>=ql&&r<=qr){
			chmax(cur,l,r,val);
			return;
		}
		push(l,r,cur);
		int mid=(l+r)>>1;
		if(mid>=ql) findmax(lc[cur],l,mid,ql,qr,val);
		if(mid<qr) findmax(rc[cur],mid+1,r,ql,qr,val);
//		assert(lazy[cur]==0&&maxn[cur].delta==0&&minn[cur].delta==0);
		update(cur);
	}/*}}}*/
	void chmin(int cur,int l,int r,ll val){/*{{{*/
//		cout<<"chmin "<<cur<<' '<<l<<' '<<r<<' '<<val<<endl;
		assert(cur<=siz);
		assert(cur);
		if(lc[cur]==0){
//			cout<<"	leaf "<<maxn[cur].maxn<<' '<<maxn[cur].sec_maxn<<endl;
			assert(maxn[cur].maxn==minn[cur].minn);
			assert(rc[cur]==0);
			assert(maxn[cur].sec_maxn==-2e9);
		}
		if(maxn[cur].maxn<=val) return;
		if(maxn[cur].sec_maxn<val){
			addmax(l,r,cur,val-maxn[cur].maxn);
			return;
		}
		push(l,r,cur);
		int mid=(l+r)>>1;
		chmin(lc[cur],l,mid,val);
		chmin(rc[cur],mid+1,r,val);
//		assert(lazy[cur]==0&&maxn[cur].delta==0&&minn[cur].delta==0);
		update(cur);
	}
	void findmin(int cur,int l,int r,int ql,int qr,ll val){
		assert(cur<=siz);
		assert(cur);
		if(maxn[cur].maxn<=val) return;
		if(l>=ql&&r<=qr){
			chmin(cur,l,r,val);
			return;
		}
		push(l,r,cur);
		int mid=(l+r)>>1;
		if(mid>=ql) findmin(lc[cur],l,mid,ql,qr,val);
		if(mid<qr) findmin(rc[cur],mid+1,r,ql,qr,val);
//		assert(lazy[cur]==0&&maxn[cur].delta==0&&minn[cur].delta==0);
		update(cur);
	}/*}}}*/
	ll qsum(int cur,int l,int r,int ql,int qr){/*{{{*/
		assert(cur<=siz);
		assert(cur);
		if(l>=ql&&r<=qr) return sum[cur];
		push(l,r,cur);
		int mid=(l+r)>>1;ll re=0;
		if(mid>=ql) re+=qsum(lc[cur],l,mid,ql,qr);
		if(mid<qr) re+=qsum(rc[cur],mid+1,r,ql,qr);
//		assert(lazy[cur]==0&&maxn[cur].delta==0&&minn[cur].delta==0);
		return re;
	}
	int qmax(int cur,int l,int r,int ql,int qr){
		assert(cur<=siz);
		assert(cur);
//		cout<<"qmax "<<cur<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<maxn[cur].maxn<<'\n';
		if(l>=ql&&r<=qr) return maxn[cur].maxn;
		push(l,r,cur);
		int mid=(l+r)>>1,re=-2e9;
		if(mid>=ql) re=max(re,qmax(lc[cur],l,mid,ql,qr));
		if(mid<qr) re=max(re,qmax(rc[cur],mid+1,r,ql,qr));
//		assert(lazy[cur]==0&&maxn[cur].delta==0&&minn[cur].delta==0);
		return re;
	}
	int qmin(int cur,int l,int r,int ql,int qr){
		assert(cur<=siz);
		assert(cur);
//		cout<<"qmin "<<cur<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<minn[cur].minn<<'\n';
		if(l>=ql&&r<=qr) return minn[cur].minn;
		push(l,r,cur);
		int mid=(l+r)>>1,re=2e9;
		if(mid>=ql) re=min(re,qmin(lc[cur],l,mid,ql,qr));
		if(mid<qr) re=min(re,qmin(rc[cur],mid+1,r,ql,qr));
//		assert(lazy[cur]==0&&maxn[cur].delta==0&&minn[cur].delta==0);
		return re;
	}/*}}}*/
}
int main(){
	using namespace seg;
	n=read();int i,t1,t2,t3,t4;
	for(i=1;i<=n;i++) val[i]=read();
	build(root,1,n);
	if(siz>1100000){
		cout<<siz<<endl;
		assert(0);
	}
	assert(siz<=1100000);
	int Q=read();
	while(Q--){
		t4=read();t1=read();t2=read();
		if(t4<=3) t3=read();
		if(t4==1) add(root,1,n,t1,t2,t3);
		if(t4==2) findmax(root,1,n,t1,t2,t3);
		if(t4==3) findmin(root,1,n,t1,t2,t3);
		if(t4==4) printf("%lld\n",qsum(root,1,n,t1,t2));
		if(t4==5) printf("%d\n",qmax(root,1,n,t1,t2));
		if(t4==6) printf("%d\n",qmin(root,1,n,t1,t2));
	}
}
