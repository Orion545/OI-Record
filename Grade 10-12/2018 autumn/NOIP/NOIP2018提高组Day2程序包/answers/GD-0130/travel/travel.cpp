#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)
using namespace std;

const int maxn=5007,maxm=maxn*2;

int n,m,fi[maxn],la[maxm],ne[maxm],tot;
void add(int a,int b){
	tot++;
	ne[tot]=fi[a];
	la[tot]=b;
	fi[a]=tot;
}

void Init(){
	scanf("%d%d",&n,&m);
	fo(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
}
int Ans[maxn],Now[maxn];
void update(){
	if (Now[0]<n) return;
	bool ok=false;
	fo(i,1,n) if (Ans[i]>Now[i]){
		ok=true;
		break;
	}else if (Ans[i]<Now[i]) break;
	if (ok || Ans[1]==0) memcpy(Ans,Now,sizeof Ans);
}
int c[maxm],hd[maxn],tl[maxn];
bool ban[maxn],bz[maxn];
void dfs(int v){
	Now[++Now[0]]=v;
	bz[v]=true;
	int BAN=0;
	for(int k=fi[v];k;k=ne[k]) if (ban[k+1>>1]) BAN=la[k];
	fo(i,hd[v],tl[v]) if (!bz[c[i]] && c[i]!=BAN) dfs(c[i]);
}
void Solve(){
	fo(i,1,n){
		hd[i]=c[0]+1;
		for(int k=fi[i];k;k=ne[k]) c[++c[0]]=la[k];
		tl[i]=c[0];
		sort(c+hd[i],c+tl[i]+1);
	}
	if (m==n-1){
		dfs(1);
		update();
	}else{
		fo(i,1,n){
			memset(Now,0,sizeof Now);
			memset(bz,0,sizeof bz);
			ban[i]=true;
			dfs(1);
			update();
			ban[i]=false;
		}
	}
}
void Print(){
	fo(i,1,n) printf("%d ",Ans[i]);
	printf("\n");
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	Init();
	Solve();
	Print();
	return 0;
}
