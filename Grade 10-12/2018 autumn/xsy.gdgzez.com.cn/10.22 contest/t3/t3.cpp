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
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
namespace c{
	ll cnt;queue<ll>q;
	ll newnode(){
		if(!q.empty()){ll re=q.front();q.pop();return re;}
		else return ++cnt;
	}
	void del(ll num){
		q.push(num);
	}
}
int siz[4000010],ch[4000010][2];ll sum[4000010];
namespace seg0{
	void insert(int &cur,int l,int r,int pos){
		if(!cur){
			cur=c::newnode();
			ch[cur][0]=ch[cur][1]=sum[cur]=siz[cur]=0;
		}
		sum[cur]+=(ll)pos;siz[cur]++;
//		cout<<"SEG0 insert "<<cur<<' '<<l<<' '<<r<<' '<<pos<<' '<<sum[cur]<<' '<<siz[cur]<<'\n';
		if(l==r) return;
		int mid=(l+r)>>1;
		if(mid>=pos) insert(ch[cur][0],l,mid,pos);
		else insert(ch[cur][1],mid+1,r,pos);
	}
	void del(int &cur,int l,int r,int pos){
		sum[cur]-=(ll)pos;siz[cur]--;
		if(l^r){
			int mid=(l+r)>>1;
			if(mid>=pos) del(ch[cur][0],l,mid,pos);
			else del(ch[cur][1],mid+1,r,pos);
		}
		if(!siz[cur]){
			c::del(cur);
			ch[cur][0]=ch[cur][1]=0;
			siz[cur]=sum[cur]=0;
			cur=0;
		}
	}
	ll query(int &cur,int l,int r,int k){
		if(l==r) return (ll)k*(ll)l;
		int mid=(l+r)>>1;
		if(siz[ch[cur][0]]>=k) return query(ch[cur][0],l,mid,k);
		else return sum[ch[cur][0]]+query(ch[cur][1],mid+1,r,k-siz[ch[cur][0]]);
	}
}
namespace seg1{
	void insert(int &cur,int l,int r,int pos){
		if(!cur){
			cur=c::newnode();
			ch[cur][0]=ch[cur][1]=sum[cur]=siz[cur]=0;
		}
		sum[cur]+=(ll)pos;siz[cur]++;
//		cout<<"SEG1 insert "<<cur<<' '<<l<<' '<<r<<' '<<pos<<' '<<sum[cur]<<' '<<siz[cur]<<'\n';
		if(l==r) return;
		int mid=(l+r)>>1;
		if(mid>=pos) insert(ch[cur][0],l,mid,pos);
		else insert(ch[cur][1],mid+1,r,pos);
	}
	void del(int &cur,int l,int r,int pos){
		sum[cur]-=(ll)pos;siz[cur]--;
		if(l!=r){
			int mid=(l+r)>>1;
			if(mid>=pos) del(ch[cur][0],l,mid,pos);
			else del(ch[cur][1],mid+1,r,pos);
		}
		if(!siz[cur]){
			c::del(cur);
			ch[cur][0]=ch[cur][1]=0;
			siz[cur]=sum[cur]=0;
			cur=0;
		}
	}
	ll query(int &cur,int l,int r,int k){
		if(l==r) return (ll)k*(ll)l;
		int mid=(l+r)>>1;
		if(siz[ch[cur][0]]>=k) return query(ch[cur][0],l,mid,k);
		else return sum[ch[cur][0]]+query(ch[cur][1],mid+1,r,k-siz[ch[cur][0]]);
	}
}
ll n,k;
bool ops[100010],eds[100010];int opp[100010],edp[100010];//op/ed side/position
int rk[100010],cnt;
inline bool cmp(int l,int r){
	return (opp[l]+edp[l])<(opp[r]+edp[r]);
}
int main(){
	k=read();n=read();int i,root0=0,root1=0,t1,t2,t3,t4;ll uls=0;char s;
	for(i=1;i<=n;i++){
		s=getchar();
		while(s!='A'&&s!='B') s=getchar();
		t1=(s=='A');
		t2=read();
		s=getchar();
		while(s!='A'&&s!='B') s=getchar();
		t3=(s=='A');
		t4=read();
		if(t1==t3){uls+=abs(t2-t4);}
		else{
			cnt++;
			ops[cnt]=t1;opp[cnt]=t2;
			eds[cnt]=t3;edp[cnt]=t4;
//			cout<<"add "<<t2<<' '<<t4<<'\n';
		}
	}
	assert(uls>=0);
//	cout<<"finish read in "<<cnt<<' '<<uls<<'\n';
	if(k==1){
		vector<int>ans;ll re=uls;
		for(i=1;i<=cnt;i++){
			ans.push_back(opp[i]);
			ans.push_back(edp[i]);
		}
		sort(ans.begin(),ans.end());
		for(i=0;i<ans.size();i++){
			re+=(ll)abs(ans[cnt]-ans[i]);
		}
		cout<<re+cnt<<'\n';return 0;
	}
	for(i=1;i<=cnt;i++) rk[i]=i;
	sort(rk+1,rk+cnt+1,cmp);
	for(i=1;i<=cnt;i++){
		seg1::insert(root1,0,1e9,opp[rk[i]]);
		seg1::insert(root1,0,1e9,edp[rk[i]]);
	}
	ll ans=0,pos0,pos1,tmp;
	pos1=seg1::query(root1,0,1e9,cnt);
	ans=sum[root1]-pos1*2ll;
//	cout<<"original "<<ans<<'\n';
	for(i=1;i<cnt;i++){
		seg1::del(root1,0,1e9,opp[rk[i]]);
		seg1::del(root1,0,1e9,edp[rk[i]]);
		seg0::insert(root0,0,1e9,opp[rk[i]]);
		seg0::insert(root0,0,1e9,edp[rk[i]]);
		pos0=seg0::query(root0,0,1e9,i);
		pos1=seg1::query(root1,0,1e9,cnt-i);
		tmp=0;
		tmp+=sum[root0]-pos0*2ll;
		tmp+=sum[root1]-pos1*2ll;
		ans=min(ans,tmp);
//		cout<<"finish time "<<i<<' '<<pos0<<' '<<pos1<<' '<<tmp<<' '<<ans<<'\n';
	}
	cout<<ans+cnt+uls<<'\n';
}
