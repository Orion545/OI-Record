#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
inline int read(){
	int p=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-t;ch=getchar();}
	while(ch>='0'&&ch<='9')p=p*10+ch-48,ch=getchar();
	return p*t;
}
struct line{
	int x,y,z;
}s[2500000];
vector<int>son[50005],ti[50005],li[50005],lev;
int fa[50005][18],d[50005],l[50005],log_2[50005],t=0,ff[50005],ans=0,n,m;
bool cmp(line i,line k){
	return i.z>k.z;
}
void dfs(int num,int dad){
//	printf("%d %d %d\n",num,l[num],dad);
	fa[num][0]=dad;
	d[num]=d[dad]+1;
	for(int i=1;i<=log_2[d[num]]+1;i++)fa[num][i]=fa[fa[num][i-1]][i-1];
	for(int i=0;i<ti[num].size();i++){
		int p=ti[num][i];
		if(d[p])continue;
		l[p]=l[num]+li[num][i];
		son[num].push_back(p);
		dfs(p,num);
	}
	if(son[num].size()==0)lev.push_back(num);
}
int lca(int x,int y){
//	printf("%d %d ",x,y);
	if(d[x]<d[y]){
		int t=x;
		x=y;
		y=t;
	}
	while(d[x]!=d[y]){
		int p=log_2[d[x]-d[y]];
		x=fa[x][p];
	}
	if(x==y)return x;
	for(int i=log_2[d[x]]+1;i>=0;i--){
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
void solve(){
	int n=lev.size();
	for(int i=0;i<n;i++){
		int a=lev[i];
		for(int k=i+1;k<n;k++){
			int b=lev[k];
			int len=l[a]+l[b]-l[lca(a,b)]*2;
			s[t++]=(line){a,b,len};
		}
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	log_2[1]=0;
	for(int i=2;i<=n;i++)log_2[i]=log_2[i/2]+1;
	for(int i=1;i<n;i++){
		int x,y,z;
		x=read();y=read();z=read();
		ti[x].push_back(y);
		li[x].push_back(z);
		ti[y].push_back(x);
		li[y].push_back(z);
	}
	dfs(1,0);
/*	for(int i=1;i<=n;i++)printf("%d ",l[i]);
	printf("\n");*/
	if(son[1].size()==1)lev.push_back(1);
	solve();
	sort(s,s+t,cmp);
/*	for(int i=0;i<t;i++){
		printf("%d %d %d\n",s[i].x,s[i].y,s[i].z);
	}*/
	int cnt=0,ans;
	for(int i=0;i<t;i++){
		if(ff[s[i].x]||ff[s[i].y])continue;
		ff[s[i].x]=1;
		ff[s[i].y]=1;
		cnt++;
		if(cnt==m){
			ans=s[i].z;break;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
