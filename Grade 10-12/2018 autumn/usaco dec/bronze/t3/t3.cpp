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
set<int>ans;
multiset<int>a,b;int ta=1000,tb=1000;
void dfs(int u){
	if(u==5){ans.insert(ta);return;}
	multiset<int>::iterator it,cur;
	multiset<int>tmpa=a,tmpb=b;
	if(u&1){
		for(it=tmpa.begin();it!=tmpa.end();it++){
			cur=a.find(*it);
			ta-=(*cur);tb+=(*cur);
			b.insert(*cur);a.erase(cur);
			dfs(u+1);
			cur=b.find(*it);
			ta+=(*cur);tb-=(*cur);
			a.insert(*cur);b.erase(cur);
		}
	}
	else{
		for(it=tmpb.begin();it!=tmpb.end();it++){
			cur=b.find(*it);
			tb-=(*cur);ta+=(*cur);
			a.insert(*cur);b.erase(cur);
			dfs(u+1);
			cur=a.find(*it);
			tb+=(*cur);ta-=(*cur);
			b.insert(*cur);a.erase(cur);
		}
	}
}
int main(){
	freopen("backforth.in","r",stdin);
	freopen("backforth.out","w",stdout);
	int i;
	for(i=1;i<=10;i++) a.insert(read());
	for(i=1;i<=10;i++) b.insert(read());
	dfs(1);
	cout<<ans.size();
}
