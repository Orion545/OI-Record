#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
struct node{
	int x,y,next;
}a[210000];int len,last[110000];
void ins(int x,int y){
	a[++len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
bool bk[210000];
ll f[210000][2],p[210000];char t[4];
int a1,x1,b1,y1;
ll mymin(ll x,ll y) {return x<y?x:y;}
void dfs(int x){
	bk[x]=false;bool pd=true;
	f[x][0]=f[x][1]=0;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bk[y]){
			pd=false;dfs(y);
			f[x][0]+=f[y][1];
			f[x][1]+=mymin(f[y][0],f[y][1]);
		}
	}
	f[x][1]+=p[x];
	if(x==a1) f[x][1-x1]=999999999;
	if(x==b1) f[x][1-y1]=999999999;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);scanf("%s",t);
	for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&a1,&x1,&b1,&y1);
		for(int j=1;j<=n;j++) bk[j]=true;
		dfs(1);
		ll ans=mymin(f[1][0],f[1][1]);
		if(ans<999999999) printf("%lld\n",ans);
		else printf("-1\n");
	}
	return 0;
}
