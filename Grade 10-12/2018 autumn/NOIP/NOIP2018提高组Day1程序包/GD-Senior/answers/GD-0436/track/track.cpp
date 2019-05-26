#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const int maxn=50000+10,inf=1000000000;
int tree[maxn*5],ad[maxn*5];
int f[maxn],g[maxn],a[maxn],zz[maxn];
int h[maxn],go[maxn*2],dis[maxn*2],nxt[maxn*2],d[maxn];
int i,j,k,l,r,mid,t,n,m,tot,top,cnt,ans;
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
void add(int x,int y,int z){
	go[++tot]=y;
	dis[tot]=z;
	nxt[tot]=h[x];
	h[x]=tot;
}
void dfs(int x,int y){
	int t=h[x];
	while (t){
		if (go[t]!=y){
			d[go[t]]=d[x]+dis[t];
			dfs(go[t],x);
		}
		t=nxt[t];
	}
}
void build(int p,int l,int r){
	if (l==r){
		tree[p]=cnt++;
		ad[p]=0;
		return;
	}
	int mid=(l+r)/2;
	build(p*2+1,mid+1,r);
	build(p*2,l,mid);
	tree[p]=min(tree[p*2],tree[p*2+1]);
	ad[p]=0;
}
void mark(int p,int v){
	tree[p]+=v;
	ad[p]+=v;
}
void down(int p){
	if (ad[p]){
		mark(p*2,ad[p]);
		mark(p*2+1,ad[p]);
		ad[p]=0;
	}
}
void change(int p,int l,int r,int a,int b,int v){
	if (l==a&&r==b){
		mark(p,v);
		return;
	}
	down(p);
	int mid=(l+r)/2;
	if (b<=mid) change(p*2,l,mid,a,b,v);
	else if (a>mid) change(p*2+1,mid+1,r,a,b,v);
	else{
		change(p*2,l,mid,a,mid,v);
		change(p*2+1,mid+1,r,mid+1,b,v);
	}
	tree[p]=min(tree[p*2],tree[p*2+1]);
}
int getwz(int p,int l,int r){
	if (l==r) return l;
	down(p);
	int mid=(l+r)/2;
	if (tree[p*2]==0) return getwz(p*2,l,mid);
	else return getwz(p*2+1,mid+1,r);
}
void solve(int x,int y){
	int t=h[x],r=0;
	f[x]=0;g[x]=-inf;
	while (t){
		if (go[t]!=y){
			solve(go[t],x);
			r+=f[go[t]];
		}
		t=nxt[t];
	}
	top=0;
	t=h[x];
	while (t){
		if (go[t]!=y) a[++top]=g[go[t]];
		t=nxt[t];
	}
	a[++top]=-inf;
	sort(a+1,a+top+1);
	while (top&&a[top]>=ans+d[x]){
		r++;
		top--;
	}
	a[++top]=inf;
	cnt=0;
	build(1,1,top);
	int i,j=top,k=1,l;
	fo(i,1,top)
		if (a[i]*2>=ans+d[x]*2) break;
	l=i;
	fo(i,1,l-1){
		if (a[i]+a[top]<ans+d[x]*2){
			k++;
			continue;
		}
		while (a[i]+a[j-1]>=ans+d[x]*2) j--;
		zz[i]=j;
		change(1,1,top,1,j,-1);
		if (tree[1]<0){
			change(1,1,top,1,zz[k],1);
			k++;
		}
		if (i-k+1>f[x]){
			f[x]=i-k+1;
			g[x]=-inf;
		}
		g[x]=max(g[x],a[getwz(1,1,top)-1]);
	}
	i=l;
	while (i+1<j){
		zz[i]=zz[i+1]=j;
		f[x]++;
		g[x]=-inf;
		i+=2;
	}
	if (i<j){
		zz[i]=j;
		change(1,1,top,1,j,-1);
		if (tree[1]<0){
			change(1,1,top,1,zz[k],1);
			k++;
			l=max(l,k);
			int o;
			fo(o,l,i-1){
				if (i-1+l-o<=o) break;
				change(1,1,top,1,i-1+l-o,-1);
			}
		}
		else{
			f[x]++;
			g[x]=-inf;
			int o;
			fo(o,l,i-1){
				if (i-1+l-o<=o) break;
				change(1,1,top,1,i-1+l-o,-1);
			}
		}
		g[x]=max(g[x],a[getwz(1,1,top)-1]);
	}
	/*else{
		int o;
			fo(o,l,i-1){
				if (i-1+l-o<=o) break;
				change(1,1,top,1,i-1+l-o,-1);
			}
		g[x]=max(g[x],a[getwz(1,1,top)-1]);
	}*/
	f[x]+=r;
	g[x]=max(g[x],d[x]);
}
bool check(int x){
	ans=x;
	solve(1,0);
	return f[1]>=m;
}
int main(){
	freopen("track.in","r",stdin);freopen("track.out","w",stdout);
	n=read();m=read();
	fo(i,1,n-1){
		j=read();k=read();l=read();
		add(j,k,l);add(k,j,l);
	}
	dfs(1,0);
	l=0;r=500000000;
	//r=58;
	while (l<r){
		mid=(l+r+1)/2;
		if (check(mid)) l=mid;else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}
