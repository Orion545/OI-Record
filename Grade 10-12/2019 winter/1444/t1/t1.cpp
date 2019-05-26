#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<set>
#define mp make_pair
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
int n,m;
namespace BIT{
	int a1[100010],a2[100010];
	inline void ADD(int x,int val){
		int re=x*val;
		for(;x<=n;x+=(x&(-x))){
			a1[x]+=val;
			a2[x]+=re;
		}
	}
	inline void add(int l,int r,int val){
//		cout<<"add "<<l<<' '<<r<<' '<<val<<'\n';
		ADD(l,val);
		ADD(r+1,-val);
	}
	inline int SUM(int x){
		int t=x+1,re1=0,re2=0;
		for(;x;x^=(x&(-x))){
			re1+=a1[x];
			re2+=a2[x];
		}
		return re1*t-re2;
	}
	inline int sum(int l,int r){
		return SUM(r)-SUM(l-1);
	}
}
set<pair<int,int> >s[100010];
void change(int l,int r,int id){
	set<pair<int,int> >::iterator it=s[id].lower_bound(mp(l,0)),cur;
	if(it!=s[id].begin()){
		cur=it;cur--;
		if(l<=cur->second){
			if(r>cur->second){
				s[id].insert(mp(cur->first,l-1));
				BIT::add(l,cur->second,1);
				s[id].erase(cur);
			}
			else{
				s[id].insert(mp(cur->first,l-1));
				s[id].insert(mp(r+1,cur->second));
				BIT::add(l,r,1);
				s[id].erase(cur);
			}
		}
	}
	for(it=s[id].lower_bound(mp(l,0));it!=s[id].end()&&it->second<=r;it=s[id].lower_bound(mp(l,0))){
		BIT::add(it->first,it->second,1);
		s[id].erase(it);
	}
	it=s[id].lower_bound(mp(l,0));
	if(it!=s[id].end()&&it->first<=r){
		s[id].insert(mp(r+1,it->second));
		BIT::add(it->first,r,1);
		s[id].erase(it);
	}
}
int main(){
	n=read();m=read();int i,t1,t2,t3,t4;
	for(i=1;i<=n;i++) s[i].insert(mp(1,n));
	while(m--){
		t4=read();
		if(t4==0){
			t1=read();t2=read();t3=read();
			change(t1,t2,t3);
		}
		else{
			t1=read();t2=read();
			printf("%d\n",BIT::sum(t1,t2));
		}
	}
}
