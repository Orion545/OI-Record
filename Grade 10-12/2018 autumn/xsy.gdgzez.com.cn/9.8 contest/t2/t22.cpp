#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cassert>
#define next DEEP_DARK_FANTASY
#define mp make_pair
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
priority_queue<int>q[100010];
int n,m,ans=0,pre[100010],next[100010],tot[100010];
namespace seg{
	int a[400010],pos[400010];
	void change(int l,int r,int num,int p,int val){
//		cout<<"change "<<l<<' '<<r<<' '<<p<<' '<<val<<'\n';
		if(l==r){
			a[num]=val;
			pos[num]=l;
			return;
		}
		int mid=(l+r)>>1;
		if(mid>=p) change(l,mid,num<<1,p,val);
		else change(mid+1,r,num<<1|1,p,val);
		a[num]=max(a[num<<1],a[num<<1|1]);
		if(a[num]==a[num<<1]) pos[num]=pos[num<<1];
		else pos[num]=pos[num<<1|1];
	}
	pair<int,int> query(int l,int r,int ql,int qr,int num){
//		cout<<"query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<a[num]<<' '<<pos[num]<<'\n';
		if(l>=ql&&r<=qr) return mp(a[num],pos[num]);
		int mid=(l+r)>>1;pair<int,int>re=mp(0,0),tmp;
		if(mid>=ql){
			tmp=query(l,mid,ql,qr,num<<1);
			if(re.first<tmp.first) re=tmp;
		}
		if(mid<qr){
			tmp=query(mid+1,r,ql,qr,num<<1|1);
			if(re.first<tmp.first) re=tmp;
		}
		return re;
	}
}
void del(int x){
	int l=pre[x],r=next[x];pair<int,int>re;
//	cout<<"del "<<x<<' '<<l<<' '<<r<<'\n';
	while(1){
		re=seg::query(1,n,1,r-1,1);
		if(re.first<=l) break;
//		cout<<"	check "<<re.first<<' '<<re.second<<' '<<q[re.second].top()<<' '<<q[re.second].size()<<'\n';
		q[re.second].pop();
		ans++;
		if(!q[re.second].empty()) seg::change(1,n,1,re.second,q[re.second].top());
		else seg::change(1,n,1,re.second,0);
	}
	pre[next[x]]=pre[x];next[pre[x]]=next[x];
}
int main(){
	n=read();m=read();int i,t1,t2,Q,lasta=0,cnt=0;
	for(i=1;i<=n;i++) tot[i]=read(),pre[i]=i-1,next[i]=i+1;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		q[t2].push(t1);
	}
	for(i=1;i<=n;i++) if(!q[i].empty()) seg::change(1,n,1,i,q[i].top());
	for(i=1;i<=n;i++) if(!tot[i]) del(i);
	Q=read();
	while(Q--){
		t1=read();t1=(t1+lasta-1)%n+1;
//		cout<<"do query "<<(++cnt)<<'\n';
		tot[t1]--;
		if(!tot[t1]) del(t1);
		lasta=ans;
		printf("%d\n",ans);
	}
}
