#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<set>
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
int n,root[100010];
namespace t{
	int ch[3000010][2],cnt=0,siz[3000010];
	void insert(int &cur,int pre,int dep,int val){
		cur=++cnt;
		ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];siz[cur]=siz[pre]+1;
		if(dep==32) return;
		int pos=val&(1<<(31-dep));
//		cout<<"insert "<<cur<<' '<<pre<<' '<<dep<<' '<<val<<' '<<pos<<'\n';
		insert(ch[cur][pos!=0],ch[pre][pos!=0],dep+1,val);
	}
	int query(int cur,int pre,int dep,int val){
		if(dep==32) return 0;
		int pos=val&(1<<(31-dep));
//		cout<<"query "<<cur<<' '<<pre<<' '<<dep<<' '<<val<<' '<<pos<<' '<<siz[cur]<<' '<<siz[pre]<<' '<<siz[ch[cur][pos==0]]<<' '<<siz[ch[pre][pos==0]]<<'\n';
		if(siz[ch[cur][pos==0]]-siz[ch[pre][pos==0]]) return (query(ch[cur][pos==0],ch[pre][pos==0],dep+1,val)|(1<<(31-dep)));
		else return query(ch[cur][pos!=0],ch[pre][pos!=0],dep+1,val);
	}
}
struct node{
	int val,pos;
}a[100010];
inline bool cmp(node l,node r){
	return l.val>r.val;
}
set<int>s;
int main(){
	n=read();int i,lb,rb,ans=0;set<int>::iterator it1,it2;
	for(i=1;i<=n;i++){
		a[i]=(node){read(),i};
		t::insert(root[i],root[i-1],0,a[i].val);
	}
	sort(a+1,a+n+1,cmp);
	s.insert(-1);s.insert(-2);s.insert(1e9);s.insert(1e9+1);
	s.insert(a[1].pos);
	for(i=2;i<=n;i++){
		it1=it2=s.upper_bound(a[i].pos);
		it1--;it1--;lb=(*it1)+1;
		it2++;rb=(*it2)-1;
		lb=max(lb,1);rb=min(rb,n);
//		cout<<"for "<<a[i].pos<<' '<<*it1<<' '<<*it2<<' '<<lb<<' '<<rb<<'\n';
		if(lb<=rb) ans=max(ans,t::query(root[rb],root[lb-1],0,a[i].val));
		s.insert(a[i].pos);
	}
	cout<<ans<<'\n';
}
