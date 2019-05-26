#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

const int mn=5010;
vector <int> e[mn];
bool vis[mn];
int ans[mn],s[mn],a[mn],b[mn],p[mn],
n,m,K;

void cpy() {
	for (int i=1;i<=n;++i)
	if (ans[i]<s[i]) return;
	else if (ans[i]>s[i]) {
		for (int j=i;j<=n;++j)
		ans[j]=s[j];
		break;
	}
	return;
}

void dfs(int fa,int ro,int X,int Y) {
	vis[ro]=0;s[++K]=ro;int l=e[ro].size();
	for (int i=0;i<l;++i) 
	if (e[ro][i]!=fa && (e[ro][i]!=X||ro!=Y) &&
	(e[ro][i]!=Y||ro!=X) && vis[e[ro][i]])
	dfs(ro,e[ro][i],X,Y);
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i) {
		scanf("%d%d",&a[i],&b[i]);
		e[a[i]].push_back(b[i]);
		e[b[i]].push_back(a[i]);
	}
	
	for (int i=1;i<=n;++i) ans[i]=n;
	for (int i=1;i<=n;++i) {
		int l=e[i].size();
		for (int j=0;j<l;++j) p[j]=e[i][j];
		sort(p,p+l);
		for (int j=0;j<l;++j) e[i][j]=p[j];
	}
	
	if (m==n-1) {
		K=0;
		for (int j=1;j<=n;++j) vis[j]=1;
		dfs(1,1,0,0);
		for (int i=1;i<=n;++i) ans[i]=s[i];
	} else {
		for (int i=1;i<=m;++i){
			K=0;
			for (int j=1;j<=n;++j) vis[j]=1;
			dfs(1,1,a[i],b[i]);
			if (K==n) cpy();
		}
	}
	
	for (int i=1;i<=n;++i)
	printf("%d ",ans[i]);
	
	return 0;
}
