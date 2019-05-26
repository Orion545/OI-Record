/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
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
struct node{
	int minn[5],maxn[5],siz;
	inline bool operator <(const node &b) const{
		for(int i=0;i<m;i++) if(maxn[i]>b.minn[i]) return 0;
		return 1;
	}
	inline bool operator >(const node &b) const{
		for(int i=0;i<m;i++) if(minn[i]<b.maxn[i]) return 0;
		return 1;
	}
	void merge(node b){
		siz+=b.siz;
		for(int i=0;i<m;i++){
			minn[i]=min(minn[i],b.minn[i]);
			maxn[i]=max(maxn[i],b.maxn[i]);
		}
	}
}a[100010];
set<node>s;
int main(){
//	cout<<"begin\n";
	n=read();m=read();int i,j;set<node>::iterator it,cur;
	for(i=1;i<=n;i++){
		for(j=0;j<m;j++) a[i].maxn[j]=a[i].minn[j]=read();
		a[i].siz=1;
	}
	for(i=1;i<=n;i++){
		it=s.lower_bound(a[i]);
		while(it!=s.end()&&!((*it)>a[i])){
			cur=it;it++;
			a[i].merge(*cur);
			s.erase(cur);
		}
		s.insert(a[i]);
		it=s.end();it--;
		printf("%d ",it->siz);
	}
}
