#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef long long LL;
const int mn=100010;
const LL oo=10000000010;
vector <int> e[mn];
LL f[mn],g[mn];
int fa[mn],v[mn];
int n,m,a1,x1,a2,x2;
char st[4];

void dfs1(int Fa,int ro) {
	fa[ro]=Fa;int l=e[ro].size();
	for (int i=0;i<l;++i)
	if (e[ro][i]!=Fa) dfs1(ro,e[ro][i]);
}

void dfs(int ro) {
	f[ro]=v[ro];g[ro]=0;
	if ((ro==a1&&x1==0)||(x2==0&&ro==a2)) f[ro]=oo;
	if ((ro==a1&&x1==1)||(x2==1&&ro==a2)) g[ro]=oo;
	int l=e[ro].size();
	for (int i=0;i<l;++i)
	if (e[ro][i]!=fa[ro]) {
		dfs(e[ro][i]);
		f[ro]=f[ro]+min(f[e[ro][i]],g[e[ro][i]]);
		g[ro]=g[ro]+f[e[ro][i]];
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d%d%s",&n,&m,&st);
	for (int i=1;i<=n;++i) 
	scanf("%d",&v[i]);
	for (int i=1;i<n;++i) {
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);e[y].push_back(x);
	}
	
	dfs1(1,1);
//	if (m<=2000) {
		for (int i=1;i<=m;++i) {
			scanf("%d%d%d%d",&a1,&x1,&a2,&x2);
			if ((fa[a1]==a2||fa[a2]==a1)&&x1==0&&x2==0) 
			{printf("-1\n");continue;}
			dfs(1);
			printf("%lld\n",min(f[1],g[1]));
		}
//	}
	
	return 0;
}
