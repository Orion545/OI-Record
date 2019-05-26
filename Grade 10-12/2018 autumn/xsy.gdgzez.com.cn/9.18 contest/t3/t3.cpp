#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
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
int root[1000010]={0},cnt=0,ch[8000010][2],siz[8000010],lazy[8000010];
void push(int l,int r,int cur){
	if(l==r||(!lazy[cur])) return;
//	cout<<"	push : "<<l<<' '<<r<<' '<<lazy[cur]<<'\n';
	int mid=(l+r)>>1;
	if(!ch[cur][0]) ch[cur][0]=++cnt;
	siz[ch[cur][0]]+=lazy[cur]*(mid-l+1),lazy[ch[cur][0]]+=lazy[cur];
	if(!ch[cur][1]) ch[cur][1]=++cnt;
	siz[ch[cur][1]]+=lazy[cur]*(r-mid),lazy[ch[cur][1]]+=lazy[cur];
	lazy[cur]=0;
}
int change(int l,int r,int ql,int qr,int cur){
	push(l,r,cur);
//	cout<<"change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<cur<<'\n';
	if(!cur) cur=++cnt;
	if(l>=ql&&r<=qr){siz[cur]+=(r-l+1);lazy[cur]++;return cur;}
	int mid=(l+r)>>1;
	if(mid>=ql) ch[cur][0]=change(l,mid,ql,qr,ch[cur][0]);
	if(mid<qr) ch[cur][1]=change(mid+1,r,ql,qr,ch[cur][1]);
	siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]];
//	cout<<"finish change "<<l<<' '<<r<<' '<<cur<<' '<<siz[cur]<<' '<<siz[ch[cur][0]]<<' '<<siz[ch[cur][1]]<<'\n';
	return cur;
}
int query(int l,int r,int ql,int qr,int cur){
	push(l,r,cur);
//	cout<<"query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<cur<<' '<<siz[cur]<<'\n';
	if(!cur) return 0;
	if(l>=ql&&r<=qr) return siz[cur];
	int mid=(l+r)>>1,re=0;
	if(mid>=ql) re+=query(l,mid,ql,qr,ch[cur][0]);
	if(mid<qr) re+=query(mid+1,r,ql,qr,ch[cur][1]);
	return re;
}
#define mp make_pair
int n,m,c[200010];
vector<pair<int,int> >s;
set<int>ins;
int main(){
	n=read();m=read();int ans,i,t1,t2,t3,t4,lastp=0,tmp;
	for(i=1;i<=n;i++) c[i]=read(),root[0]=change(1,n,i,i,root[0]);
	ins.insert(0);
	while(m--){
		t4=read();t1=read();t2=read();t3=read();
		if(t4){
			ans=0;s.clear();
			for(auto k:ins) if((tmp=query(1,n,t1,t2,root[k]))){
				ans+=tmp;s.push_back(mp(k,ans));
//				cout<<"getans "<<k<<' '<<tmp<<'\n';
			}
			if(ans<=t3){printf("1 %d\n",ans-s[0].second);}
			else{
				for(i=0;ans-s[i].second>t3;i++);
				printf("%d %d\n",s[i].first+1,ans-s[i].second);
				lastp=s[i].first+1;
			}
		}
		else{
			t3^=lastp;ins.insert(t3);
//			cout<<"****doing change "<<t1<<' '<<t2<<' '<<t3<<'\n';
			root[t3]=change(1,n,t1,t2,root[t3]);
		}
	}
}

