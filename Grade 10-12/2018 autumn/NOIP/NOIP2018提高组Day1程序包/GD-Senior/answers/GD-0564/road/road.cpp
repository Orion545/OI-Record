#include<bits/stdc++.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
typedef long long ll;
inline int read(){
	int n=0,f=1;char c;
	for(c=getchar();c!='-'&&(c<'0'||c>'9');c=getchar());
	if (c=='-') c=getchar(),f=-1;
	for(;c>='0'&&c<='9';c=getchar()) n=n*10+c-48;
	return n*f;
}
const int maxn=1e5+5,N=1e4;
int i,j,n,cnt;
ll ans;
vector<int>g[N+5];
bool bz[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	fo(i,1,n) j=read(),g[j].push_back(i);
	fd(i,N,1){
		for(j=0;j<g[i].size();j++){
			int x=g[i][j];
			cnt++;
			if (bz[x-1]) cnt--;
			if (bz[x+1]) cnt--;
			bz[x]=1;
		}ans+=cnt;
	}
	printf("%lld\n",ans);
	return 0;
}
