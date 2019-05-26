#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
const int N=1e5+7;
using namespace std;
int read(){
	int ans=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-48;c=getchar();}
	return ans*f;
}
inline LL Min(LL x,LL y){return x>y?y:x;}
inline LL Max(LL x,LL y){return x>y?x:y;}
int n,m,ne[N*2],tot=0,fi[N],to[N],fa[N][20];
LL f[N][2],s[N];
int dep[N],yi[N];
bool so[N];
char ch[10];
void ins(int x,int y){
	tot++;ne[tot]=fi[x];fi[x]=tot;to[tot]=y;
}
void dfs(int x){
	f[x][0]=0;f[x][1]=s[x];
	for(int i=fi[x];i;i=ne[i]){
		int tt=to[i];
		if(tt==fa[x][0])continue;
		fa[tt][0]=x;dep[tt]=dep[x]+1;
		dfs(tt);
		f[x][0]+=f[tt][1];
		f[x][1]+=Min(f[tt][0],f[tt][1]);
	}
	if(f[x][0]<f[x][1])so[x]=1;
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;i>=0;i--)
		if(dep[y]<=dep[fa[x][i]])x=fa[x][i];
	if(x==y)return x;
	for(int i=17;i>=0;i--){
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
void dfs2(int x){
	for(int i=fi[x];i;i=ne[i]){
		int tt=to[i];
		if(tt==fa[x][0])continue;
		yi[tt]=yi[x]^so[tt];dfs2(tt);
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();scanf("%s",ch+1);
	for(int i=1;i<=n;i++)s[i]=(LL)read();
	for(int i=1,a,b;i<n;i++){
		a=read();b=read();
		ins(a,b);ins(b,a);
	}
	fa[1][0]=0;dep[1]=1;
	dfs(1);yi[1]=0;
	dfs2(1);
	for(int i=1;i<=n;i++)
	for(int i=1,a,x,b,y;i<=m;i++){
		a=read();x=read();b=read();y=read();
		int lc=lca(a,b);LL an,an1;
		if(x==0&&y==0){
			if(fa[a][0]==b||fa[b][0]==a){printf("-1\n");continue;}
		}
		printf("%lld\n",f[a][x]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
