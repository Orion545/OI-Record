#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define mod 1000000007
#define maxn 5010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
int a[10][10],seq[1000010];
int n,m,tot;
ll power(ll a,ll b)
{
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)ans=ans*a%mod;
	return ans;
}
void dfs(int x,int y,int k)
{
	if(x==n&&y==m){
		seq[++tot]=(k<<1)|a[n][m];
		return;
	}
	k=(k<<1)|a[x][y];
	if(x<n)dfs(x+1,y,k);
	if(y<m)dfs(x,y+1,k);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(); m=read();
	if(n<m){int tmp=n; n=m; m=tmp;}
	if(m==1){
		printf("%lld\n",power(2,n));
		fclose(stdin); fclose(stdout);
		return 0;
	}
	if(m==2){
		printf("%lld\n",4ll*power(3,n-1)%mod);
		fclose(stdin); fclose(stdout);
		return 0;
	}
	if(m==3){
		printf("%lld\n",112ll*power(3,n-3)%mod);
		fclose(stdin); fclose(stdout);
		return 0;
	}
	int ans=0;
	for(int k=0;k<(1<<(n*m));k++){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				a[i+1][j+1]=(k>>(i*m+j))&1;
		tot=0; dfs(1,1,0);
		int flag=1;
		for(int i=2;i<=tot;i++)
			if(seq[i-1]<seq[i]){
				flag=0; break;
			}
		ans+=flag;
/*		int flag2=1;
		for(int i=1;i<n;i++)
			for(int j=2;j<=m;j++)
				if(a[i][j]==1&&a[i+1][j-1]==0){
					flag2=0; break;
				}
		if(flag!=flag2){
			printf("%d %d %d ****************\n",k,flag,flag2);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++)
					printf("%d ",a[i][j]);
				printf("\n");
			}
			for(int i=1;i<=tot;i++)
				printf("%d %d\n",i,seq[i]);
		}*/
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
