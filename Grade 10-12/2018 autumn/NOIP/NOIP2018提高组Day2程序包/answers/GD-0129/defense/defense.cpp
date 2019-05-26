#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
int a[100005];
struct node{
	int to,nxt;
}e[200050];
int h[100056];
int cnt;
void add(int x,int y){
	e[++cnt].nxt=h[x];
	e[cnt].to=y;
	h[x]=cnt;
}
int x,xx,y,yy;
char ch[5];
bool vis[100005];
long long ans;
long long minn(long long a,long long b){
	return a<b?a:b;;
}
int n,m;
void dfs(int u,int fa,long long anss,int tot){
	if(anss>ans) return;
	if(tot==n-1){
		ans=minn(ans,anss);
		return;
	}
	if(u==x){
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(v!=fa){
				dfs(v,x,anss+a[u]*xx,tot+1);
			}
		}
	}
	else if(u==y){
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(v!=fa){
				dfs(v,x,anss+a[u]*yy,tot+1);
			}
		}
	}
	else{
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(v!=fa){
				vis[u]=true;
				dfs(v,x,anss+a[u],tot+1);
				vis[u]=false;
				if(vis[fa]||(v==x&&xx==1)||(v==y&&yy==1)) dfs(v,x,anss,tot+1);
			}
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",ch+1);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=m;++i){
		ans=0x7fffffffffffffff;
		scanf("%d%d%d%d",&x,&xx,&y,&yy);
		bool f=false;
		for(int i=h[x];i;i=e[i].nxt){
			if(e[i].to==y){
				cout<<"-1"<<endl;
				f=true;
				break;
			}
		}
		if(f) continue;
		vis[x]=xx;
		vis[y]=yy;
		dfs(1,0,0,0);
		vis[x]=0;
		vis[y]=0;
		printf("%lld\n",ans);
	}
	return 0;
}
