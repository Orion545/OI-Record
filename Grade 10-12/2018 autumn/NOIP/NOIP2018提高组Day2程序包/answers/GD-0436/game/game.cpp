#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int mo=1000000007;
int id[9][300][10],cd[150],cnt[150],dis[150][30],len[1000000+50];
int f[2][150];
int i,j,k,l,t,n,m,tot,now,ans;
void dfs(int len,int s,int p){
	int i,j,k,l,r,t;
	id[len][s][p]=++tot;
	cd[tot]=len;
	int now=tot;
	int a[10],b[10];
	if (len+1<=n){
		t=s;
		l=0;
		fo(i,1,len){
			a[l++]=t%2;
			t/=2;
		}
		fo(i,0,l){
			b[i]=0;
			if (i<l) b[i]|=a[i];
			if (i) b[i]|=a[i-1];
			if (i&&i<l&&p!=i) b[i]=1;
		}
		r=0;
		fo(i,0,l) r+=b[i]*(1<<i);
		fo(i,0,l)
			if (!i||i&&!a[i-1]){
				if (!id[len+1][r][i]) dfs(len+1,r,i);
				cnt[now]++;
				dis[now][cnt[now]]=id[len+1][r][i];
				if (!i){
					cnt[now]++;
					dis[now][cnt[now]]=id[len+1][r][i];
				}
			}
	}
	if (len-1>0){
		t=s;
		l=0;
		fo(i,1,len){
			a[l++]=t%2;
			t/=2;
		}
		fo(i,0,l-2){
			b[i]=0;
			b[i]|=a[i];
			b[i]|=a[i+1];
			if (p!=i+1) b[i]=1;
		}
		r=0;
		fo(i,0,l-2) r+=b[i]*(1<<i);
		fo(i,0,l-2)
			if (!i||i&&!a[i]){
				if (!id[len-1][r][i]) dfs(len-1,r,i);
				cnt[now]++;
				dis[now][cnt[now]]=id[len-1][r][i];
				if (!i){
					cnt[now]++;
					dis[now][cnt[now]]=id[len-1][r][i];
				}
			}
	}
	if (len==n){
		t=s;
		l=0;
		fo(i,1,len){
			a[l++]=t%2;
			t/=2;
		}
		fo(i,0,l-1){
			b[i]=0;
			b[i]=a[i];
			if (i<l-1) b[i]|=a[i+1];
			if (i<l-1&&p!=i+1) b[i]=1;
		}
		r=0;
		fo(i,0,l-1) r+=b[i]*(1<<i);
		fo(i,0,l-1)
			if (!i||i&&!a[i]){
				if (!id[len][r][i]) dfs(len,r,i);
				cnt[now]++;
				dis[now][cnt[now]]=id[len][r][i];
				if (!i){
					cnt[now]++;
					dis[now][cnt[now]]=id[len][r][i];
				}
			}
	}
}
int main(){
	freopen("game.in","r",stdin);freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	dfs(1,0,0);
	//printf("%d\n",tot);
	fo(i,1,n) len[i]=i;
	fo(i,n+1,m) len[i]=n;
	fd(i,n-1,1) len[++m]=i;
	f[0][id[1][0][0]]=2;
	fo(i,1,m-1){
		fo(j,1,tot) f[1-now][j]=0;
		fo(j,1,tot)
			if (f[now][j])
				fo(k,1,cnt[j])
					if (cd[dis[j][k]]==len[i+1]){
						f[1-now][dis[j][k]]=f[1-now][dis[j][k]]+f[now][j]>=mo?f[1-now][dis[j][k]]+f[now][j]-mo:f[1-now][dis[j][k]]+f[now][j];
					}
		now^=1;
	}
	fo(i,1,tot) (ans+=f[now][i])%=mo;
	printf("%d\n",ans);
}
