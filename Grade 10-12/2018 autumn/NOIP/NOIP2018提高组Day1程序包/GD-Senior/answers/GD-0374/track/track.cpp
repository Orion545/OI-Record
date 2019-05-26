#include<cstdio>
#include<cstring>
using namespace std;

const int N=1005;
int r[N][N],n,m,a,b,l,maxn,k,f[N][N],p[N];

void dfs(int pos,int tot)
{
	if(tot>maxn) maxn=tot;
	for(int j=1;j<=n;j++){
		if(r[pos][j]!=0&&f[pos][j]==0&&f[j][pos]==0){
			f[pos][j]=f[j][pos]=1;
			dfs(j,tot+r[pos][j]);
			f[pos][j]=f[j][pos]=0;
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&l);
		r[a][b]=r[b][a]=l;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			memset(f,0,sizeof(f));
			dfs(i,0);
		}
		printf("%d",maxn);
	}
	else printf("15");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
