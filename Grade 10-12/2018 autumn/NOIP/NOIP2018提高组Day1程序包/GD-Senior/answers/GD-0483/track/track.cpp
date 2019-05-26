#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 50010
using namespace std;
int n,m,head[N],tot=0,ans=0,sum=0,s[N],t[N],rt,ma=0;
bool f,h;
struct Edge{
	int to,link,v;
}edge[N*2];
void add(int a,int b,int c){
	edge[++tot].to=b;
	edge[tot].v=c;
	edge[tot].link=head[a];
	head[a]=tot;
}
void dfs(int x,int fa,int now){
	if (now>ma){
		ma=now; rt=x;
	}
	for (int i=head[x];i;i=edge[i].link){
		int u=edge[i].to;
		if (u==fa) continue;
		dfs(u,x,now+edge[i].v);
	}
}
void dfs2(int x,int fa,int now){
//	printf("%d %d %d\n",x,fa,now);
	if (now>ans) ans=now;
	for (int i=head[x];i;i=edge[i].link){		
		int u=edge[i].to;
//		printf("%d\n",u);
		if (u==fa) continue;
//		printf(")
		dfs2(u,x,edge[i].v+now);
	}
}
bool pd(int x){
	int now=0,cnt=0;
	for (int i=1;i<n;i++){
		if (now+s[i]<x) now+=s[i];
		else {
			now=0; cnt++;
		}
	}
	if (now>0) cnt++;
	if (cnt>=m) return true;
	return false;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int a,b,c;
	scanf("%d %d",&n,&m);
	f=true; h=true;
	for (int i=1;i<n;i++){
		scanf("%d %d %d",&a,&b,&c);
		t[i]=c;
		sum+=c;
		if (b!=a+1) f=false;
		if (a!=1) h=false;
		add(a,b,c);
		add(b,a,c);
	}
	if (m==1){
		dfs(1,0,0);
//		printf("%d\n",rt);
		dfs2(rt,0,0);
	}
	else if (f){
		for (int i=1;i<n;i++){
			for (int j=head[i];j;j=edge[j].link){
				if (edge[j].to==i+1) s[i]=edge[j].v;
			}
		}
//		for (int i=1;i<n;i++) printf("%d ",s[i]);
		int l=1,r=sum;
		while(l<=r){
			int mid=(l+r)/2;
			if (pd(mid)) l=mid+1;
			else r=mid-1;
		}
		ans=r;
	}
	printf("%d",ans);
	return 0;
}
