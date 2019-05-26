#include<bits/stdc++.h>
#define M 500005
using namespace std;

struct edge{int u,next;}e[M]={0}; int head[M]={0},use=0;
void add(int x,int y){use++;e[use].u=y;e[use].next=head[x];head[x]=use;}
int l[M]={0},r[M]={0},p[M]={0},f[M]={0},ans[M]={0},s[M]={0};
int n,m,xfzsb=0,cnt=0;

void dfs(int x){
	s[++cnt]=x;
	if(x<=m){
		for(int i=xfzsb;;i++)
		if(s[cnt-i]>=m+x){
			ans[x]=i;
			break;
		}
	}
	for(int i=head[x];i;i=e[i].next) dfs(e[i].u);
	s[cnt--]=0;
}

int main(){
	freopen("3.in","r",stdin);
//	freopen("shenxian.out","w",stdout);
	scanf("%d%d",&n,&m); m=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",l+i,r+i);
		p[++m]=l[i]; p[++m]=r[i];
	}
	sort(p+1,p+m+1); 
	m=unique(p+1,p+m+1)-p-1;
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(p+1,p+m+1,l[i])-p;
		r[i]=lower_bound(p+1,p+m+1,r[i])-p;
		
		if(l[i]<r[i]){
			f[l[i]]=max(f[l[i]],r[i]);
			f[l[i]+m]=max(f[l[i]+m],r[i]+m);
		}else{
			f[l[i]]=max(f[l[i]],r[i]+m);
			f[l[i]+m]=max(f[l[i]+m],m<<1);
			f[1]=max(f[1],r[i]);
		}
	}
	for(int i=1;i<=(m<<1);i++) f[i]=max(f[i],f[i-1]);
	for(int i=f[1];i<=m;i=f[i]) xfzsb++; 
	for(int i=1;i<(m<<1);i++) add(f[i],i);
	dfs(m<<1);
	for(int i=1;i<=n;i++) printf("%d ",ans[l[i]]);
}
