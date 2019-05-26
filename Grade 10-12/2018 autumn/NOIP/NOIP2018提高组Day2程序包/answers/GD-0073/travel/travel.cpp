#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<stack>
using namespace std;
struct edge{
	int v,next;
}a[10001];
int n,m,stp=0,top=0,tot=1,u[5001],v[5001],f[5001],ss[5001],head[5001],s[5001],st[5001];
bool used[5001],cir[5001],ban[10001];
void add(int u,int v){
	a[++tot].v=v;
	a[tot].next=head[u];
	head[u]=tot;
}
void dfs(int u,int fa){
	int ss[5001],tp=0;
	s[++top]=u;
	for(int tmp=head[u];tmp!=-1;tmp=a[tmp].next){
		int v=a[tmp].v;
		if(v!=fa&&!ban[tmp])ss[++tp]=v;
	}
	sort(ss+1,ss+tp+1);
	for(int i=1;i<=tp;i++){
		dfs(ss[i],u);
	}
}
void gao_tree(){
	dfs(1,0);
	for(int i=1;i<=n;i++){
		printf("%d ",s[i]);
	}
}
void dfscir(int u,int fa){
	used[u]=true;
	st[++stp]=u;
	for(int tmp=head[u];tmp!=-1;tmp=a[tmp].next){
		int v=a[tmp].v;
		if(v!=fa&&!cir[v]){
			if(!used[v])dfscir(v,u);
			else{
				int x=st[stp];
				cir[v]=true;
				while(x!=v){
					cir[x]=true;
					x=st[--stp];
				}
			}
		}
	}
	stp--;
}
bool cmp(int s[],int ss[],int n){
	for(int i=1;i<=n;i++){
		if(s[i]!=ss[i])return s[i]<ss[i];
	}
	return false;
}
void gao_huan(){
	dfscir(1,0);
	for(int i=1;i<=n;i++)ss[i]=n+1;
	for(int i=1;i<=m;i++){
		if(cir[u[i]]&&cir[v[i]]){
			ban[i*2+1]=ban[i*2]=true;
			top=0;
			dfs(1,0);
			if(cmp(s,ss,top))memcpy(ss,s,sizeof(s));
			ban[i*2+1]=ban[i*2]=false;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ss[i]);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		add(u[i],v[i]);
		add(v[i],u[i]);
	}
	if(m==n-1)gao_tree();
	else gao_huan();
	return 0;
}
