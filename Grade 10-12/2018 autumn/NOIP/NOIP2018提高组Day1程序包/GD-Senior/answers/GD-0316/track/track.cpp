#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline int read() {
	int x=0, f=1; char ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar()) if(ch=='-') f=-1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

const int N=50000+5;

struct Node {
	int u, v, len;
};
bool operator < (Node a, Node b) {
	return a.u<b.u;
}

int n, m, l=0, r=500000000;

int add_cnt, first[N], to[N<<1], next[N<<1], len[N<<1]; // 从0开始 
void add(int u, int v, int l) {
	to[add_cnt]=v; next[add_cnt]=first[u]; first[u]=add_cnt; len[add_cnt]=l; ++add_cnt;
	to[add_cnt]=u; next[add_cnt]=first[v]; first[v]=add_cnt; len[add_cnt]=l; ++add_cnt;
}

int al[N], ab[N];
int work_a() {
	//int l=0, r=500000000;
	sort(al+1, al+n);
	for(int mid=(l+r+1)>>1; l<r; mid=(l+r+1)>>1) {
		int ans=0;
		memset(ab, 0, sizeof(ab));
		for(int i=1; i<n; i++)
			if(ab[i]) continue;
			else if(al[i]<mid) {
				for(int w=lower_bound(al+i+1, al+n, mid-al[i])-al; w<n&&al[w]<mid&&al[w]+al[i]>=mid; w++)
					if(ab[w]==0) {
						ans++;
						ab[i]=ab[w]=1;
						break;
					}
			}
			else ans++;
		if(ans>=m) l=mid;
		else r=mid-1;
	}
	return l;
}

Node bb[N];
int work_b() {
	sort(bb+1, bb+n);
	//int l=0, r=500000000;
	for(int mid=(l+r+1)>>1; l<r; mid=(l+r+1)>>1) {
		int ans=0, tmp=0;
		for(int i=1; i<n; i++) {
			tmp+=bb[i].len;
			if(tmp>=mid) ++ans, tmp=0;
		}
		if(ans>=m) l=mid;
		else r=mid-1;
	}
	return l;
}

int flag[N], mark[N<<1];
int limit, wow;
void dfs(int now, int sum) {
	if(sum==0) { //不考虑从点now开始搜索 
		flag[now]=1;
		for(register int i=1; i<=n; i++) if(!flag[i]) dfs(i, 0);
		if(wow>=m) return;
		flag[now]=0;
	}
	if(sum>=limit) {
		++wow;
		if(wow>=m) return;
		for(register int i=1; i<=n; i++) if(!flag[i]) dfs(i, 0);
		--wow;
		return;
	}
	for(register int p=first[now]; p; p=next[p]) if(!mark[p]) {
		mark[p]=mark[p^1]=1;
		dfs(to[p], sum+len[p]);
		if(wow>=m) return;
		mark[p]=mark[p^1]=0;
	}
	return;
}
int work() {
	//int l=15, r=16;
	for(limit=(l+r+1)>>1; l<r; limit=(l+r+1)>>1) {
		wow=0;
		memset(mark, 0, sizeof(mark));
		memset(flag, 0, sizeof(flag));
		dfs(1, 0);
		if(wow>=m) l=limit;
		else r=limit-1;
	}
	return l;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);

	n=read(), m=read();
	bool AAA=true, BBB=true;
	for(int i=1, u, v, l; i<n; i++) {
		u=read(), v=read(), l=read();
		if(u>v) swap(u, v);
		add(u, v, l);
		
		if(u!=1) AAA=false;
		else al[i]=l;
		
		if(v!=u+1) BBB=false;
		else bb[i]=(Node){u, v, l};
	}
	if(AAA) printf("%d", work_a());
	else if(BBB) printf("%d", work_b());
	else printf("%d", work());

	fclose(stdin); fclose(stdout);
	return 0;
}
