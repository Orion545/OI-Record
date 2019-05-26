#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=100000+10;
const ll inf=1000000000000;
int father[maxn],pp[maxn],tree[maxn][2],p[maxn],q[maxn];
int h[maxn],go[maxn*2],nxt[maxn*2],sta[80];
ll dp[maxn][2][2],g[2][2],c[maxn][2],cc[maxn][2];
int i,j,k,l,t,n,m,a,x,b,y,tot,top;
ll ans;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void add(int x,int y){
	go[++tot]=y;
	nxt[tot]=h[x];
	h[x]=tot;
}
int pd(int x){
	return tree[father[x]][1]==x;
}
void update(int x){
	int i,j,k,l,r;
	fo(l,0,1)
		fo(r,0,1)
			dp[x][l][r]=inf;
	dp[x][0][0]=c[x][0];
	dp[x][1][1]=c[x][1]+(ll)p[x];
	if (q[x]==0) dp[x][1][1]=inf;
	else if (q[x]==1) dp[x][0][0]=inf;
	if (tree[x][0]){
		fo(l,0,1)
			fo(r,0,1)
				g[l][r]=inf;
		fo(i,0,1)
			fo(j,0,1)
				if (dp[x][i][j]<inf)
					fo(k,0,1)
						fo(l,1-i,1) 
							if (dp[tree[x][0]][k][l]<inf) g[k][j]=min(g[k][j],dp[x][i][j]+dp[tree[x][0]][k][l]);
		fo(l,0,1)
			fo(r,0,1)
				dp[x][l][r]=g[l][r];
	}
	if (tree[x][1]){
		fo(l,0,1)
			fo(r,0,1)
				g[l][r]=inf;
		fo(i,0,1)
			fo(j,0,1)
				if (dp[x][i][j]<inf)
					fo(k,1-j,1)
						fo(l,0,1) 
							if (dp[tree[x][1]][k][l]<inf) g[i][l]=min(g[i][l],dp[x][i][j]+dp[tree[x][1]][k][l]);
		fo(l,0,1)
			fo(r,0,1)
				dp[x][l][r]=g[l][r];
	}
}
void rotate(int x){
	int y=father[x],z=pd(x);
	father[x]=father[y];
	if (father[y]) tree[father[y]][pd(y)]=x;
	tree[y][z]=tree[x][1-z];
	if (tree[x][1-z]) father[tree[x][1-z]]=y;
	tree[x][1-z]=y;
	father[y]=x;
	update(y);
	//update(x);
	if (pp[y]){
		pp[x]=pp[y];
		cc[x][0]=cc[y][0];
		cc[x][1]=cc[y][1];
		pp[y]=cc[y][0]=cc[y][1]=0;
	}
}
void splay(int x,int y){
	while (father[x]!=y){
		if (father[father[x]]!=y)
			if (pd(x)==pd(father[x])) rotate(father[x]);else rotate(x);
		rotate(x);
	}
	update(x);
}
void access(int x){
	int y,z;
	int i,j;
	ll t;
	splay(x,0);
	z=tree[x][1];
	if (z){
		tree[x][1]=0;
		father[z]=0;
		pp[z]=x;
		t=inf;
		fo(i,0,1) t=min(t,dp[z][1][i]);
		c[x][0]+=t;
		cc[z][0]=t;
		t=inf;
		fo(i,0,1)
			fo(j,0,1)
				t=min(t,dp[z][i][j]);
		c[x][1]+=t;
		cc[z][1]=t;
		update(x);
	}
	while (pp[x]){
		y=pp[x];
		splay(y,0);
		z=tree[y][1];
		if (z){
			father[z]=0;
			pp[z]=y;
			t=inf;
			fo(i,0,1) t=min(t,dp[z][1][i]);
			c[y][0]+=t;
			cc[z][0]=t;
			t=inf;
			fo(i,0,1)
				fo(j,0,1)
					t=min(t,dp[z][i][j]);
			c[y][1]+=t;
			cc[z][1]=t;
		}
		tree[y][1]=x;
		father[x]=y;
		pp[x]=0;
		c[y][0]-=cc[x][0];
		c[y][1]-=cc[x][1];
		update(y);
		splay(x,0);
	}
}
void dfs(int x,int y){
	int i,j,r=h[x];
	ll t;
	while (r){
		if (go[r]!=y) dfs(go[r],x);
		r=nxt[r];
	}
	update(x);
	if (y){
		pp[x]=y;
		t=inf;
		fo(i,0,1) t=min(t,dp[x][1][i]);
		c[y][0]+=t;
		cc[x][0]=t;
		t=inf;
		fo(i,0,1)
			fo(j,0,1)
				t=min(t,dp[x][i][j]);
		c[y][1]+=t;
		cc[x][1]=t;
	}
}
void write(ll x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (!x){
		putchar('0');
		putchar('\n');
		return;
	}
	top=0;
	while (x){
		sta[++top]=x%10;
		x/=10;
	}
	while (top) putchar('0'+sta[top--]);
	putchar('\n');
}
int main(){
	freopen("defense.in","r",stdin);freopen("defense.out","w",stdout);
	n=read();m=read();t=read();
	fo(i,1,n) p[i]=read();
	fo(i,1,n-1){
		j=read();k=read();
		add(j,k);add(k,j);
	}
	fo(i,1,n) q[i]=-1;
	dfs(1,0);
	while (m--){
		a=read();x=read();b=read();y=read();
		q[a]=x;
		access(a);
		q[b]=y;
		access(b);
		splay(b,0);
		ans=inf;
		fo(i,0,1)
			fo(j,0,1)
				ans=min(ans,dp[b][i][j]);
		if (ans>=inf) write(-1);
		else write(ans);
		q[b]=-1;
		access(b);
		q[a]=-1;
		access(a);
	}
}
