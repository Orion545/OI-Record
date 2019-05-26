#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;
const int N = 5e4+10;
int n,m,sum;
int final[N],nex[N*2],to[N*2],tot,w[N*2];
void link(int x,int y,int ww) {
	to[++tot] = y,nex[tot] = final[x],final[x] = tot;
	w[tot] = ww;
}

int lim,cnt,fa[N],t[N];
multiset<int> s;
multiset<int>::iterator it;

void dfs(int x){
	for (int i = final[x]; i; i=nex[i]){
		if (to[i] != fa[x]) {
			fa[to[i]]=x;
			dfs(to[i]);
		}
	}
	if (cnt>=m) return;
	s.clear();
	for (int i = final[x]; i; i=nex[i]){
		int y = to[i]; if (y != fa[x]) {
			if (t[y] + w[i] >= lim) {
				cnt++;
			} else {
				s.insert(t[y]+w[i]);
			}
		}
	}
	t[x] = 0;
	while (s.size()) {
		int mi = *s.begin();
		s.erase(s.begin());
		it = s.lower_bound(lim - mi);
		if (it == s.end()) {
			t[x] = mi;
			continue;
		}
		s.erase(it);
		cnt++;
	}
	if (s.size()) t[x] = *(--s.end());
}

bool ok(int mid){
	lim=mid;cnt=0;
	dfs(1);
	return cnt>=m;
}

char c;
void read(int &x) {
	while ((c=getchar())>'9' || c < '0');
	x=c-'0'; while((c=getchar())>='0' && c<='9')x=x*10+c-'0';
}

int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for (int i = 1; i < n; i++) {
		int u,v,l; read(u),read(v),read(l);
		link(u,v,l), link(v,u,l);
		sum+=l;
	}
	int l = 1, r = sum, ans = 0;
	while (l <= r) {
		if (ok(l+r>>1)){
			ans = l = l+r>>1; l++;
		} else r=(l+r>>1)-1;
	}
	cout<<ans<<endl;
}
