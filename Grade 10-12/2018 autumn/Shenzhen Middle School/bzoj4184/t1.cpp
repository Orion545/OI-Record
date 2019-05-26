#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<unordered_map>
#include<vector>
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
struct lb{
	vector<int>s;
	inline void insert(int w){
		int i;
		for(i=0;i<s.size();i++) if((w^s[i])<w) w^=s[i];
		if(w){
			s.push_back(w);
			for(i=s.size()-1;i>0;i--) if(s[i]>s[i-1]) swap(s[i],s[i-1]);
		}
	}
	inline void join(lb b){
		for(int i=0;i<b.s.size();i++) insert(b.s[i]);
	}
	inline int getmax(){
		int i,re=0;
		for(i=0;i<s.size();i++){
//			cout<<"getmax "<<s[i]<<'\n';
			if((re^s[i])>re) re^=s[i];
		}
		return re;
	}
}seg[2000010],emp;
inline void change(int l,int r,int ql,int qr,int num,int val){
	if(l>=ql&&r<=qr){seg[num].insert(val);return;}
	int mid=(l+r)>>1;
	if(mid>=ql) change(l,mid,ql,qr,num<<1,val);
	if(mid<qr) change(mid+1,r,ql,qr,num<<1|1,val);
}
inline void query(int l,int r,int num,lb cur){
	cur.join(seg[num]);
	if(l==r){printf("%d\n",cur.getmax());return;}
	int mid=(l+r)>>1;
	query(l,mid,num<<1,cur);
	query(mid+1,r,num<<1|1,cur);
}
unordered_map<int,int>mp;int cnt,l[500010],r[500010],val[500010];
int main(){
	int n=read();int i,tmp;
	for(i=1;i<=n;i++){
		tmp=read();
		if(tmp<0) r[mp[-tmp]]=i-1;
		else mp[tmp]=++cnt,val[cnt]=tmp,l[cnt]=i;
	}
//	cout<<"finish readin\n";
	for(i=1;i<=cnt;i++){
		if(l[i]&&!r[i]) r[i]=n;
//		cout<<i<<' '<<l[i]<<' '<<r[i]<<' '<<val[i]<<'\n';
		change(1,n,l[i],r[i],1,val[i]);
	}
	query(1,n,1,emp);
}
