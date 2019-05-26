#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int i,n,m,j,a,b,o,f[5005],h[5005],ne[5005][5005],v[5005];
struct ha{
	int a,b,n;
}d[10005];
void dfs(int a){
	int b=1e9,i;
	printf("%d ",a);
	v[a]=1;
	for(i=h[a];i;i=d[i].n){
		if(v[d[i].b])continue;
		ne[a][++ne[a][0]]=d[i].b;
	}
	sort(ne[a]+1,ne[a]+ne[a][0]+1);
	for(i=1;i<=ne[a][0];i++)dfs(ne[a][i]);
}
void charu(int a,int b){
	d[++j].a=a,d[j].b=b;
	d[j].n=h[a],h[a]=j;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void ch(int a,int q){
	int i,b;
	for(i=h[a];i;i=d[i].n){
		b=d[i].b;
		if(b==q)continue;
		if(!v[b]){
			v[b]=v[a]+1;
			ch(b,a);
		}
		if(v[find(b)]>0){
			if(v[f[b]]<v[find(a)])f[f[a]]=f[b];
			else f[f[b]]=f[a];
		}
	}
	v[a]=-1;
}
void dfs2(int a){
	int i,x=0,xx=0;
	printf("%d ",a);
	v[a]=1;
	for(i=h[a];i;i=d[i].n){
		if(v[d[i].b])continue;
		ne[a][++ne[a][0]]=d[i].b;
		if(f[d[i].b]!=d[i].b){
			if(x)xx=d[i].b;
			else x=d[i].b;
		}
	}
	if(o>0){
		if(ne[a][0]>1)o=-1;
		else if(ne[a][1]>o)return;
	}
	sort(ne[a]+1,ne[a]+ne[a][0]+1);
	for(i=1;i<=ne[a][0];i++){
		if(f[ne[a][i]]==ne[a][i])dfs2(ne[a][i]);
		else{
			if(x&&xx&&o>=0){
				if(o) o=0;
				else o=(x==ne[a][i])?xx:x;	
			}
			dfs2(ne[a][i]);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		charu(a,b);
		charu(b,a);
	}
	if(m==n-1){
		dfs(1);
	}
	else{
		for(i=1;i<=n;i++)f[i]=i;
		v[1]=1,ch(1,0);
		memset(v,0,sizeof(v));
		dfs2(1);
	}
	return 0;
}
