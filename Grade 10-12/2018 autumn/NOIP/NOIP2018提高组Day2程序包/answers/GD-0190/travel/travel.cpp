#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,i,j,k,s[5005],a,b,v[5005],u[5005],ok;
bool mp[5005][5005];
int h[5005],q[5005],f[5005],erzi[5005][3005];
struct hhh{
	int a,b,n;
}d[5005];
void charu(int a,int b){
	d[++j].a=a,d[j].b=b;
	d[j].n=h[a],h[a]=j;
}
/*void dfs(int a,int k){
	int i,b;
	if(k==n){
		ok=1;
		return;
	}
	if(ok)return;
	for(i=2;i<=n;i++){
		if(mp[a][i]){
			if(u[i]!=-1){
				if(!v[i])v[i]=v[a]+1;
				dfs(i,k+1);
			}
		}
	}
	u[a]=-1;
	if(ok)return;
}*/
void bfs(){
	int i,j;
	q[1]=1;v[1]=1;
	for(i=j=1;i<=j;i++){
		a=q[i];
		for(k=h[a];k;k=d[k].n){
			b=d[k].b;
			if(!v[b]){
				f[b]=a;
				erzi[a][++erzi[a][0]]=b;
				v[b]=v[a]+1;
				q[++j]=b;
			}
		}
	}
}
void zhao(int a,int k){
	int xiao=1e9,i,j,x,y;
	if(k==n)return;
	printf("%d ",a);
	for(i=1;i<=erzi[a][0];i++){
		x=erzi[a][i];
		if(!u[x]){
			xiao=min(xiao,x);
			for(j=1;j<=erzi[f[a]][0];j++){
				y=erzi[f[a]][j];
				if(!u[y]){
					xiao=min(xiao,y);
				}
			}
		}
	}
	u[xiao]=1;
	zhao(xiao,k+1);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d", &n, &m);
	if(m==n-1){
		for(i=1;i<=m;i++){
			scanf("%d%d", &a, &b);
			mp[a][b]=mp[b][a]=1;
			//charu(a,b);charu(b,a);
		}
		s[1]=1;k=1;
		for(j=1;j<=k;j++){
			for(i=2;i<=n;i++){
				if(!u[i]&&mp[i][s[j]])u[i]=1,s[++k]=i;
			}
		}
		for(i=1;i<=n;i++)printf("%d ",s[i]);
		/*v[1]=1;
		bfs();
		zhao(1,1);*/
		//dfs(1,1);
		
		/*for(i=1;i<=n;i++){
			s[v[i]]=i;
		}
		for(i=1;i<=n;i++)printf("%d ",v[i]);*/
	}
	return 0;
}
