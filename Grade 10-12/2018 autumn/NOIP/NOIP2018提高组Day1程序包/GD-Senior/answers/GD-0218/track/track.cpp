#include <cstdio>
#include <algorithm>
#include <cstring>
#define ch0 ch[u][0]
#define ch1 ch[u][1]
using namespace std;
const int SCP=682*999/12, MAXV=1000, INF=1e5;



/* Global */
int pre[SCP<<1], to[SCP<<1], wdis[SCP], head[SCP], wcnt;
int x[SCP], y[SCP], z[SCP];
int ans;
int n, m;
inline int max(int a, int b){ return (a>b)?a:b; }
inline int min(int a, int b){ return (a<b)?a:b; }
inline int max(int a, int b, int c){ return max(a, max(b, c)); }
inline void addedge(int u, int v, int w){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; wdis[wcnt]=w; }
inline void add2edge(int u, int v, int w){ addedge(u, v, w); addedge(v, u, w); }



/* Subtask 1, 4, 5, 6 */
int f1456[SCP], far[SCP], todis[SCP];
void dfs1456(int u){
	int i, son=0, son2=0;
	for(i=head[u]; i; i=pre[i]) if(!far[to[i]]){
		far[to[i]]=u;
		todis[to[i]]=wdis[i];
		dfs1456(to[i]);
		if(f1456[son]+todis[son]<f1456[to[i]]+todis[to[i]]) son=to[i];
	}
	for(i=head[u]; i; i=pre[i]) if(far[to[i]]==u and to[i]^son and f1456[son2]+todis[son2]<f1456[to[i]]+todis[to[i]]) son2=to[i];
	f1456[u]=f1456[son]+todis[son];
	ans=max(ans, max(f1456[u], f1456[son]+todis[son]+f1456[son2]+todis[son2]));
}
inline void subtask1_4_5_6(){
	int i;
	far[1]=1;
	for(i=1; i<n; i++) add2edge(x[i], y[i], z[i]);
	dfs1456(1);
	printf("%d\n", ans);
} 



/* Subtask 2, 9, 10, 11 */
inline void subtask2_9_10_11(){
	int i, j, l=1, r=1e9, mid, sum;
	for(i=1; i<n; i++) todis[x[i]]=z[i];
	for(i=2; i<=n; i++) todis[i]+=todis[i-1];
	while(l<r){
		mid=(l+r+1)>>1;
		sum=0;
		for(i=1; i<=n; i=j+1){
			for(j=i; todis[j]-todis[i-1]<mid and j<=n; j++);
			if(j<=n) sum++;
		}
		if(sum>=m) l=mid;
		else r=mid-1;
	}
	printf("%d\n", l);
}



/* Subtask 3, 7, 8 */
inline void subtask3_7_8(){
	int i, j, rn, l=1, r=1e9, mid, sum;
	sort(z+1, z+n);
	while(l<r){
		mid=(l+r+1)>>1;
		i=1;
		j=n-1;
		sum=0;
		while(i<j){
			while(i<j and z[i]+z[j]<mid) i++;
			if(i<j){
				sum++;
				if(z[j]<mid) i++;
			}
			j--;
		}
		if(sum>=m) l=mid;
		else r=mid-1;
	} 
	printf("%d\n", l);
}



int f[205][MAXV+5], ch[205][2], deg[205];
int limit;
void predfs(int u){
	int i;
	for(i=head[u]; i; i=pre[i]) if(!far[to[i]]){
		far[to[i]]=u;
		todis[to[i]]=wdis[i];
		predfs(to[i]);
		if(!ch0) ch0=to[i];
		else ch1=to[i];
	}
}

/*
对于儿子数为0的节点：
f[u][0]=0									//没有任何节点
f[u][i]=-INF								//不可能有链 

对于儿子数为1的节点：
f[u][0]=max{f[ch0][0]+(todis[ch0]>=limit), f[ch0][limit-todis[ch0]]+1}

f[u][i]=f[ch0][i-todis[ch0]]				//...->ch0->u->...

对于儿子数为2的节点， 
f[u][0]=max{f[ch0][0]+(todis[ch0]>=limit), f[ch0][limit-todis[ch0]]+1}
	   +max{f[ch1][0]+(todis[ch1]>=limit), f[ch1][limit-todis[ch1]]+1}
f[u][0]=max{f[ch0][i]+f[ch1][limit-i-todis[ch0]-todis[ch1]]+1}
f[u][i]=max{f[ch0][i-todis[ch0]]+f[ch1][0]+(todis[ch1]>=limit),
			f[ch1][i-todis[ch1]]+f[ch0][0]+(todis[ch0]>=limit)} 
*/
inline void dfs12p(int u){
	int i;
	if(!ch0){
		f[u][0]=0;
		for(i=1; i<=MAXV; i++) f[u][i]=-INF;
	}
	else if(!ch1){
		dfs12p(ch0);
		f[u][0]=max(f[ch0][0]+(todis[ch0]>=limit), f[ch0][min(max(0, limit-todis[ch0]), MAXV+1)]+1);
		for(i=1; i<=MAXV; i++) f[u][i]=f[ch0][max(0, i-todis[ch0])];
	}
	else{
		dfs12p(ch0);
		dfs12p(ch1);
		f[u][0]=max(f[ch0][0]+(todis[ch0]>=limit), f[ch0][min(max(0, limit-todis[ch0]), MAXV+1)]+1)
			   +max(f[ch1][0]+(todis[ch1]>=limit), f[ch1][min(max(0, limit-todis[ch1]), MAXV+1)]+1);
		for(i=0; i<=MAXV; i++){
			f[u][0]=max(f[u][0], f[ch0][i]+f[ch1][min(max(0, limit-i-todis[ch0]-todis[ch1]), MAXV+1)]+1);
			f[u][i]=max(f[u][i],
						f[ch0][max(0, i-todis[ch0])]+f[ch1][0]+(todis[ch1]>=limit),
						f[ch1][max(0, i-todis[ch1])]+f[ch0][0]+(todis[ch0]>=limit));
		}
	}
	for(i=MAXV-1; ~i; i--) f[u][i]=max(f[u][i], f[u][i+1]);
	f[u][MAXV+1]=-INF;
}


inline void subtask12p(){
	int i, l=1, r=1e7, rt, mid;
	for(i=1; i<=n; i++) add2edge(x[i], y[i], z[i]), deg[x[i]]++, deg[y[i]]++;
	for(rt=1; rt<=n and deg[rt]>=3; rt++);
	far[rt]=rt;
	predfs(rt);
	while(l<r){
		memset(f, 0x80, sizeof(f));
		limit=mid=(l+r+1)>>1;
		dfs12p(rt);
		if(f[rt][0]>=m) l=mid;
		else r=mid-1;
	}
	printf("%d\n", l);
	
}
int main(){
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	int i;
	scanf("%d %d", &n, &m);
	for(i=1; i<n; i++) scanf("%d %d %d", &x[i], &y[i], &z[i]);
	
	// Subtask 1,4,5,6
	if(m==1){
		subtask1_4_5_6();
		return 0;
	}
	
	// Subtask 2,9,10,11
	for(i=1; i<n and y[i]==x[i]+1; i++);
	if(i>=n){
		subtask2_9_10_11();
		return 0;
	}
	
	// Subtask 3,7,8
	for(i=1; i<n and x[i]==1; i++);
	if(i>=n){
		subtask3_7_8();
		return 0;
	}
	
	subtask12p();
	return 0;
}
