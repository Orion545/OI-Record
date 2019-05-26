#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,dp[2010][2],head[100005],tot,p[100005],x,y,xx,yy,cnt;
long long ans,sum[100005][2];
char t;
bool pd[2010][2],f;
struct Edge{
	int to,link;
}edge[200005];
void add(int a,int b){
	edge[++tot].to=b;
	edge[tot].link=head[a];
	head[a]=tot;
}
void dfs(int now,int fa){
	if (!f) return;
	for (int i=head[now];i;i=edge[i].link){
		int u=edge[i].to;
		if (u==fa) continue;
		if (!pd[now][1]&&!pd[u][1]){
			f=false; return;
		} 
		dfs(u,now);
		if (!pd[now][1])
			dp[now][0]+=dp[u][1];
		else if (!pd[now][0]){
			if (!pd[u][0]) dp[now][1]+=dp[u][1];
			else if (!pd[u][1]) dp[now][1]+=dp[u][0];
			else dp[now][1]+=min(dp[u][1],dp[u][0]);
		}
		else{
			if (!pd[u][0]){
				dp[now][1]+=dp[u][1];
				dp[now][0]+=dp[u][1];
			}
			else if (!pd[u][1]) dp[now][1]+=dp[u][0];
			else {
				dp[now][0]+=dp[u][1];
				dp[now][1]+=min(dp[u][0],dp[u][1]);
			}
		}
	}
	if (pd[now][1]) dp[now][1]+=p[now];
}
long long getans(int l,int r){
	if (l>=r) return 0;
	if ((r-l+1)&1)
		return min(sum[r][1]-sum[l-1][0],sum[r][0]-sum[l][0]);
	else
		return min(sum[r][1]-sum[l][0],sum[r][0]-sum[l-1][0]);
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int a,b;
	scanf("%d %d %c %d",&n,&m,&t,&cnt);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<n;i++){
		scanf("%d %d",&a,&b);
		add(a,b);
		add(b,a);
	}
	if (n<=2000&&m<=2000)	
		while(m--){
			f=true;
			memset(dp,0,sizeof(dp));
			for (int i=1;i<=n;i++){
				pd[i][0]=true; pd[i][1]=true;
			}
			scanf("%d %d %d %d",&x,&xx,&y,&yy);
			if (xx==0){
				pd[x][1]=false;
				for (int i=head[x];i;i=edge[i].link){				
					int u=edge[i].to;
					pd[u][0]=false;
				}
			} 
			if (yy==0){
				pd[y][1]=false;
				for (int i=head[y];i;i=edge[i].link){
					int u=edge[i].to;
					pd[u][0]=false;
				}
			} 
			if (xx==1) pd[x][0]=false;
			if (yy==1) pd[y][0]=false;
			if (xx==1){
				dfs(x,0);
				ans=dp[x][1];
			}
			else if (yy==1){
				dfs(y,0);
				ans=dp[y][1];
			} 
			else{
				dfs(1,0);
				if (!pd[1][0]) ans=dp[1][1];
				else if (!pd[1][1]) ans=dp[1][0];
				else ans=min(dp[1][1],dp[1][0]);
			} 
			if (!f) printf("-1\n");
			else printf("%lld\n",ans);
		}
	else{
		sum[1][1]=p[1]; sum[1][0]=0;
		for (int i=2;i<=n;i++){
			sum[i][1]=sum[i-2][1]+p[i];
			sum[i][0]=sum[i-1][1];
		}
		if (t=='A'&&cnt==1){
			while(m--){
				scanf("%d %d %d %d",&x,&xx,&y,&yy);	
				if (yy==1) ans=getans(2,y-1)+getans(y+1,n)+p[1]+p[y];
				else ans=p[1]+p[y-1]+p[y+1]+getans(2,y-2)+getans(y+2,n);
				printf("%lld\n",ans);
			}	
		}
		else if (t=='A'&&cnt==3){
			while(m--){
				scanf("%d %d %d %d",&x,&xx,&y,&yy);				
				if (x>y){ swap(x,y); swap(xx,yy);}
				if (xx==0&&yy==0&&y==x+1){printf("-1\n");continue;} 
				if (xx==1){
					if (yy==1) ans=p[x]+p[y]+getans(1,x-1)+getans(x+1,y-1)+getans(y+1,n);
					else ans=p[x]+p[y-1]+p[y+1]+getans(1,x-1)+getans(x+1,y-2)+getans(y+2,n);
				}
				else{
					if (yy==1) ans=p[x-1]+p[x+1]+p[y]+getans(1,x-2)+getans(x+2,y-1)+getans(y+1,n);
					else ans=p[x-1]+p[x+1]+p[y-1]+p[y+1]+getans(1,x-2)+getans(x+2,y-2)+getans(y+2,n);
				}
				printf("%lld\n",ans);
			}		
		}
		else if (t=='A'&&cnt==2){
			while(m--){
				scanf("%d %d %d %d",&x,&xx,&y,&yy);
				if (xx==0&&yy==0){ printf("-1\n"); continue;}
				if (x>y) { swap(x,y); swap(xx,yy);}
				if (xx==1){
					if (yy==1) ans=p[x]+p[y]+getans(1,x-1)+getans(y+1,n);
					else ans=p[x]+p[y+1]+getans(1,x-1)+getans(y+2,n);
				}
				else ans=p[y]+p[x-1]+getans(1,x-2)+getans(y+1,n);
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
