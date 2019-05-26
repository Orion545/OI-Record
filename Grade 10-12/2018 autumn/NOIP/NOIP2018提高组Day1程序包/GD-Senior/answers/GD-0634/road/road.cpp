#include <cstdio>
#include <algorithm>
#define Add(x,y) (nxt[++num]=head[x],head[x]=num,v[num]=y)
#define For(x) for(int h=head[x],o=v[h]; h; o=v[h=nxt[h]])
using namespace std;
int head[10005],nxt[100005],v[100005],num;
long long ST[100005][30];
int n,a[100005],k;
long long ans;

long long Min(int x,int y){
	long long ret= 10005;
	for (int i=20; i>=0; i--) if (y&(1<<i))
		ret=min(ret,ST[x][i]),x+=(1<<i);
	return ret;
}

long long wk(int l,int r,int cnt){
	if (l==r) return a[l]-cnt;
	if (l>r) return 0;
	long long ret=0,lst=r+1;
	k=Min(l,r-l+1);
	ret+=k-cnt;
	cnt=k;
	For(k){
		if (o>r) continue;
		if (o<l){
			ret+=wk(l,lst-1,cnt);
			lst=l;
			break;
		}
		ret+=wk(o+1,lst-1,cnt);
		lst=o;
	}
	ret+=wk(l,lst-1,cnt);
	return ret;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),ST[i][0]=a[i],Add(a[i],i);
	for (int j=1; j<=20; j++)
		for (int i=1; i<=n; i++){
			if (i+(1<<(j-1))>n) break;
			ST[i][j]=min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
		}
	ans=wk(1,n,0);
	printf("%lld",ans);
	return 0;
}
