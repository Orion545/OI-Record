#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=5010;
int n,m,x,y,s[N],duliu,xianzhi,xz[N];
bool huan[N],ins[N],vis[N];
vector<int> v[N];
int duru() {
	int re=0; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') re=re*10+ch-48,ch=getchar();
	return re;
}
void dfs(int x,int fa) {
	printf("%d ",x);
	sort(v[x].begin(),v[x].end());
	for (int i=0; i<v[x].size(); i++) if (v[x][i]!=fa) dfs(v[x][i],x);
}
void huan_dfs(int x,int fa) {
	printf("%d ",x); vis[x]=1;
	sort(v[x].begin(),v[x].end());
	if (!huan[x]||xianzhi) {
		for (int i=0; i<v[x].size(); i++) if (!vis[v[x][i]]) {
			huan_dfs(v[x][i],x);
		}
	} else {
		int cnt=0;
		for (int i=0; i<v[x].size(); i++) if (!vis[v[x][i]]) {
			if (huan[v[x][i]]) {
				cnt++;
				if (xz[0] && v[x][i]>xz[xz[0]]) {
					xianzhi=1;
					continue;
				}
				if (cnt==1) xz[++xz[0]]=v[x][i+1];
				huan_dfs(v[x][i],x);
			} else dfs(v[x][i],x);
		}
		xz[0]--;
	}
}
int zhao_huan(int x,int fa) {
	s[++s[0]]=x; ins[x]=1;
	for (int i=0; i<v[x].size(); i++) if (v[x][i]!=fa) {
		if (ins[v[x][i]]) {
			int t; duliu=v[x][i];
			do {
				t=s[s[0]--]; huan[t]=1;
			} while (t!=v[x][i]);
			return 1;
		} else {
			if (zhao_huan(v[x][i],x)) return 1;
		}
	}
	s[0]--;
	return 0;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=duru(); m=duru();
	while (m--) x=duru(),y=duru(),v[x].push_back(y),v[y].push_back(x);
	if (m==n-1) {
		dfs(1,0);
	} else {
		zhao_huan(1,0);
		huan_dfs(1,0);
	}
	return 0;
}
