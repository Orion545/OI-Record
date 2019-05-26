#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int maxn=5000+10;
int h[maxn],go[maxn*2],nxt[maxn*2],a[maxn*2],ans[maxn],b[maxn];
int L[maxn],R[maxn];
bool bz[maxn],pd[maxn];
int i,j,k,l,t,n,m,tot,top,cnt;
void add(int x,int y){
	go[++tot]=y;
	nxt[tot]=h[x];
	h[x]=tot;
}
bool cmp(int x,int y){
	return go[x]<go[y];
}
void dfs(int x){
	bz[x]=1;
	b[++cnt]=x;
	int i;
	fo(i,L[x],R[x])
		if (!bz[go[a[i]]]&&!pd[(a[i]+1)/2]) dfs(go[a[i]]);
}
void update(){
	if (cnt<n) return;
	int i;
	fo(i,1,n)
		if (b[i]!=ans[i]) break;
	if (i<=n&&b[i]<ans[i]){
		fo(i,1,n) ans[i]=b[i];
	}
}
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m){
		scanf("%d%d",&j,&k);
		add(j,k);add(k,j);
	}
	fo(i,1,n){
		L[i]=top+1;
		t=h[i];
		while (t){
			a[++top]=t;
			t=nxt[t];
		}
		R[i]=top;
		sort(a+L[i],a+R[i]+1,cmp);
	}
	ans[1]=n+1;
	if (m==n-1){
		dfs(1);
		update();
	}
	else{
		fo(i,1,m){
			pd[i]=1;
			cnt=0;
			fo(j,1,n) bz[j]=0;
			dfs(1);
			update();
			pd[i]=0;
		}
	}
	fo(i,1,n) printf("%d ",ans[i]);
	printf("\n");
}
