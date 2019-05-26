#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int mn=50100;
vector <int> e[mn];
vector <int> el[mn];
vector <int> v[mn];
multiset <int> se[mn];
int a[mn],ans,n,m,le,ri,mid,sum;

int dfs1(int fa,int ro) {
	int big1=0,big2=0,l=e[ro].size();
	for (int i=0;i<l;++i)
	if (e[ro][i]!=fa) {
		int tep=el[ro][i]+dfs1(ro,e[ro][i]);
		if (tep>big1) {big2=big1;big1=tep;}
		else if (tep>big2) {big2=tep;}
	}
	ans=max(ans,big1+big2);
	return big1;
}

int dfs(int fa,int ro) {
	int l=e[ro].size();
	for (int i=0;i<l;++i)
	if (e[ro][i]!=fa) {
		int tep=el[ro][i]+dfs(ro,e[ro][i]);
		v[ro].push_back(tep);
	}
	l=v[ro].size();int L=0;
	for (int i=0;i<l;++i) 
	if (v[ro][i]<mid) {
		se[ro].insert(v[ro][i]);
		a[L]=v[ro][i];
		++L;
	} else ++sum;
	l=L;
	sort(a,a+l);int big=0;
	for (int i=0;i<l;++i) {
		multiset <int> :: iterator tep=se[ro].find(a[i]);
		if (tep!=se[ro].end()) {
			se[ro].erase(tep);
			if (a[i]>=mid) {++sum;continue;}
			int tp=mid-a[i];
			tep=se[ro].lower_bound(tp);
			if (tep!=se[ro].end()) {
				++sum;se[ro].erase(tep);continue;
			}
			big=max(big,a[i]);
		}
	}
	v[ro].clear();se[ro].clear();
	return big;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;++i) {
		int x,y,l;
		scanf("%d%d%d",&x,&y,&l);
		e[x].push_back(y);el[x].push_back(l);
		e[y].push_back(x);el[y].push_back(l);
	}
	
	if (m==1) {
		ans=0;
		dfs1(1,1);
		printf("%d",ans);
		return 0;
	}
	
	le=1;ri=500000010;
	while (le+1<ri) {
		mid=(le+ri)>>1;sum=0;
		dfs(1,1);
		if (sum>=m) le=mid;else ri=mid;
	}
	printf("%d\n",le);
	
	return 0;
}
