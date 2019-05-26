#include <cstdio>

using namespace std;

int n;
int d[10005];
int f[10003][10003][3];
long long ans;

void read(int i){
	char c;
	c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') d[i]=d[i]*10+c-'0',c=getchar();
}

void dfs(int l,int r,int cnt){
	if (l>r) return;
	ans+=f[l][r][0]-cnt;	
	if (l==r) return;
	cnt=f[l][r][0];
	if (f[l][r][2]) dfs(f[l][r][1]+1,r-1,cnt);
			   else dfs(f[l][r][1]+1,r,cnt);
	int i=f[l][r][1]-1;
	for (;i>l;i=f[l][i][1]-1){		
		dfs(f[l][i][1]+1,i,cnt);		
	}
	if (i==l) dfs(l,l,cnt);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		read(i);
		f[i][i][0]=d[i];
		f[i][i][1]=i;
	}
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			if (d[j]<f[i][j-1][0]){
				f[i][j][0]=d[j];
				f[i][j][1]=j;
			} else
			if (d[j]==f[i][j-1][0]){
				f[i][j][0]=d[j];
				f[i][j][1]=f[i][j-1][1];
				if (f[i][j-1][2]) f[i][j][1]=f[i][j-1][2];
				f[i][j][2]=j;
			} else
			{
				f[i][j][0]=f[i][j-1][0];
				f[i][j][1]=f[i][j-1][1];
				if (f[i][j-1][2]) f[i][j][1]=f[i][j-1][2];
			}
	dfs(1,n,0);
	printf("%lld",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
