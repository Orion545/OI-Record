# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>
# include <set>
# include <map>
# define Fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 110;
const int maxs = 25010;
int n;
int a[maxn];
int s[maxs];
void solve(){
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1) - (a+1);
	memset(s,0,sizeof s);
	Fo(i,1,n)s[a[i]]=1;
	Fo(i,1,n)Fo(j,0,25000){
		if(s[j] && j+a[i]<=25000)s[j+a[i]]=2;
	}
	int cnt=0;
	Fo(i,1,n)if(s[a[i]]==1)++cnt;
	printf("%d\n",cnt);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		Fo(i,1,n)scanf("%d",a+i);
		solve();
	}
	return 0;
}
