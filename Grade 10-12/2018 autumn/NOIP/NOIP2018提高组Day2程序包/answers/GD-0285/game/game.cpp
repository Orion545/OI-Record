#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
inline int rd(){
	char c=getchar();int x=0,flag=1;
	for(;c<'0'||c>'9';c=getchar())
		if(c=='-')
			flag=-1;
	for(;c>='0'&&c<='9';c=getchar())
		x=x*10+c-'0';
	return x*flag;
}
const int bin[5]={16,8,4,2,1};
const int mod=1000000007;
int n,m,ans=0,a[3][3]={0},v[110];
void solve(int x,int y,int val){
	if(x==n-1&&y==m-1){
		v[++v[0]]=val+a[x][y];
		return;
	}
	if(y<m-1)
		solve(x,y+1,val+a[x][y]);
	if(x<n-1)
		solve(x+1,y,val+a[x][y]);
	return;
}
bool check(){
	v[0]=0;
	solve(0,0,0);
	for(int i=2;i<=v[0];i++)
		if(v[i]>v[i-1])
			return false;
	return true;
}
void dfs(int x,int y){
	if(y==m)
		x++,y=0;
	if(x==n){
		if(check())
			ans++;
		return;
	}
	a[x][y]=0;
	dfs(x,y+1);
	a[x][y]=bin[x+y];
	dfs(x,y+1);
	return;
}
int power(int x,int k){
	int res=1,s=x;
	for(;k;k>>=1){
		if(k&1)
			res=(ll)res*s%mod;
		s=(ll)s*s%mod;
	}
	return res;
}
ll dp[1000010][4]={0};
int solve3(){
	ll res=0;
	if(m&1){
		dp[1][0]=dp[1][2]=dp[1][3]=1;
		for(int i=2;i<=m/2;i++){
			dp[i][0]=dp[i][2]=dp[i][3]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
			dp[i][1]=dp[i-1][2];
		}
		res=((dp[m/2][0]+dp[m/2][1]+dp[m/2][2]+dp[m/2][3])*2+dp[m/2][2])%mod;
		dp[1][1]=1;
		for(int i=2;i<=m/2;i++){
			dp[i][0]=dp[i][2]=dp[i][3]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
			dp[i][1]=dp[i-1][2];
		}
		res=res*(dp[m/2][0]+dp[m/2][1]+dp[m/2][2]+dp[m/2][3])%mod;
	}
	else{
		dp[1][0]=dp[1][2]=dp[1][3]=1;
		for(int i=2;i<=m/2;i++){
			dp[i][0]=dp[i][2]=dp[i][3]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
			dp[i][1]=dp[i-1][2];
		}
		res=(dp[m/2][0]+dp[m/2][1]+dp[m/2][2]+dp[m/2][3])%mod;
		dp[1][1]=1;
		for(int i=2;i<m/2;i++){
			dp[i][0]=dp[i][2]=dp[i][3]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
			dp[i][1]=dp[i-1][2];
		}
		res=res*((dp[m/2-1][0]+dp[m/2-1][1]+dp[m/2-1][2]+dp[m/2-1][3])*2+dp[m/2-1][2])%mod;
	}
	return res*4%mod;
}
ll f[2000010][9]={0};
int solve8(){
	ll res=0;int s=m+n-3;
	f[1][0]=f[1][n-1]=f[1][n]=1;
	for(int i=2;i<=s-s/2;i++){
		for(int j=0;j<=n;j++){
			f[i][0]+=f[i-1][j];
			f[i][n-1]+=f[i-1][j];
			f[i][n]+=f[i-1][j];
		}
		for(int j=1;j<n-1;j++)
			f[i][j]=f[i-1][j+1];
		if(i*2<n)
			for(int j=1;j<=n-i*2;j++)
				f[i][j]=0;
		if(i*2>m)
			for(int j=m-i*2+n+1;j<=n;j++)
				f[i][j]=0;
	}
	for(int i=0;i<=n;i++)
		res+=f[s-s/2][i];
	res%=mod;
	f[1][n-2]=1;
	for(int i=2;i<=s/2;i++){
		for(int j=0;j<=n;j++){
			f[i][0]+=f[i-1][j];
			f[i][n-1]+=f[i-1][j];
			f[i][n]+=f[i-1][j];
		}
		for(int j=1;j<n-1;j++)
			f[i][j]=f[i-1][j+1];
		if(i*2<n)
			for(int j=1;j<=n-i*2;j++)
				f[i][j]=0;
		if(i*2>m)
			for(int j=m-i*2+n+1;j<=n;j++)
				f[i][j]=0;
	}
	ll sum=0;
	for(int i=0;i<=n;i++)
		sum+=f[s/2][i];
	sum%=mod;
	res=(ll)res*sum%mod;
	return res*4%mod;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=rd();m=rd();
	if(n>=m)
		swap(n,m);
	if(n==2)
		printf("%d\n",(ll)power(3,m-1)*4%mod);
	else if(n==3)
		printf("%d\n",solve3());
	else if(n<=3&&m<=3){
		dfs(0,0);
		printf("%d\n",ans);
	}
	else
		printf("%d\n",solve8());
	return 0;
}
