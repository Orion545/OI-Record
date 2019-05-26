#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> vint;
int n;
vint g[5010];
namespace tree{
	void dfs(int fa,int x){
		printf("%d ",x);
		for(vint::iterator it=g[x].begin();it!=g[x].end();it++){
			if(*it!=fa)dfs(x,*it);
		}
	}
	void work(){
		dfs(0,1);
	}
}
namespace ctree{
	bool v[5010],flag;
	int fa[5010],cy[5010],C;
	void dfs(int x){
		v[x]=1;
		for(vint::iterator it=g[x].begin();it!=g[x].end();it++){
			if(*it!=fa[x]){
				if(!v[*it]){
					fa[*it]=x;
					dfs(*it);
				}else if(flag){
					for(int y=x;y!=*it;y=fa[y])cy[++C]=y;
					cy[++C]=*it;
					flag=0;
				}
			}
		}
	}
	struct per{
		int p[5010];
		int&operator[](int k){return p[k];}
	}res,tmp;
	bool operator<(per a,per b){
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i])return a[i]<b[i];
		}
		return 0;
	}
	int a,b,M;
	void dfs(int fa,int x){
		tmp[++M]=x;
		for(vint::iterator it=g[x].begin();it!=g[x].end();it++){
			if((x==a&&*it==b)||(x==b&&*it==a))continue;
			if(*it!=fa)dfs(x,*it);
		}
	}
	void work(){
		int i;
		flag=1;
		dfs(1);
		for(i=1;i<=n;i++)res[i]=n;
		for(i=1;i<C;i++){
			a=cy[i];
			b=cy[i+1];
			M=0;
			dfs(0,1);
			if(tmp<res)res=tmp;
		}
		for(i=1;i<=n;i++)printf("%d ",res[i]);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
	if(m==n-1)
		tree::work();
	else
		ctree::work();
}
