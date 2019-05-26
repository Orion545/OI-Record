#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=1e13;
int n,m,u,v,fu,fv,x,y,cnt,a[N],head[N],to[N*2],nxt[N*2];
ll f[N][2];
char type[10];
void adde(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
void dfsk3(int pre,int u){
	f[u][0]=0;
	f[u][1]=a[u];
	int v;
	for(int i=head[u];i;i=nxt[i]){
		v=to[i];
		if(v!=pre){
			dfsk3(u,v);
			f[u][0]+=f[v][1];
			f[u][1]+=min(f[v][0],f[v][1]);
			if(f[u][0]>inf){
				f[u][0]=inf;
			}
			if(f[u][1]>inf){
				f[u][1]=inf;
			}
		}
	}
	if(u==fu){
		f[u][x^1]=inf;
	}
	if(u==fv){
		f[u][y^1]=inf;
	}
}
namespace A1{
	ll f1[N][2],f2[N][2];
	void solve(){
		f1[1][0]=inf;
		f1[1][1]=a[1];
		for(int i=2;i<=n;i++){
			f1[i][0]=f1[i-1][1];
			f1[i][1]=a[i]+min(f1[i-1][0],f1[i-1][1]);
			if(f1[i][1]>inf){
				f1[i][1]=inf;
			}
		}
		f2[n][0]=0;
		f2[n][1]=a[n];
		for(int i=n-1;i>=1;i--){
			f2[i][0]=f2[i+1][1];
			f2[i][1]=a[i]+min(f2[i+1][0],f2[i+1][1]);
			if(f2[i][1]>inf){
				f2[i][1]=inf;
			}
		}
		f2[1][0]=inf;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d%d",&u,&x,&v,&y);
			if(u>v){
				swap(u,v);
				swap(x,y);
			}
			if(v==2&&!x&&!y){
				puts("-1");
			}else{
				ll res;
				if(!y){
					res=f1[v-1][1]+(v<n?f2[v+1][1]:0);
				}else{
					res=a[v]+min(f1[v-1][0],f1[v-1][1])+(v<n?min(f2[v+1][0],f2[v+1][1]):0);
				}
				if(res>=inf){
					puts("-1");
				}else{
					printf("%lld\n",res);
				}
			}
		}
	}
}
namespace A2{
	ll f1[N][2],f2[N][2];
	void solve(){
		f1[1][0]=0;
		f1[1][1]=a[1];
		for(int i=2;i<=n;i++){
			f1[i][0]=f1[i-1][1];
			f1[i][1]=a[i]+min(f1[i-1][0],f1[i-1][1]);
		}
		f2[n][0]=0;
		f2[n][1]=a[n];
		for(int i=n-1;i>=1;i--){
			f2[i][0]=f2[i+1][1];
			f2[i][1]=a[i]+min(f2[i+1][0],f2[i+1][1]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%d%d",&u,&x,&v,&y);
			if(u>v){
				swap(u,v);
				swap(x,y);
			}
			if(!x&&!y){
				puts("-1");
			}else{
				printf("%lld\n",f1[u][x]+f2[v][y]);
			}
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,type+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	if(type[1]=='A'&&type[2]=='1'){
		A1::solve();
	}else if(type[1]=='A'&&type[2]=='2'){
		A2::solve();
	}else{
		for(int i=1;i<=m;i++){
			scanf("%d%d%d%d",&fu,&x,&fv,&y);
			dfsk3(0,1);
			if(min(f[1][0],f[1][1])==inf){
				puts("-1");
			}else{
				printf("%lld\n",min(f[1][0],f[1][1]));
			}
		}
	}
	return 0;
}
