#include <cstdio>
#include <cstring>
#include <algorithm>
#define ele int
using namespace std;
const ele maxn=100010;
const ele maxk=18;
ele n,d[maxn],st[maxn][maxk],idx[maxn][maxk],_log[maxn];
inline ele qry(ele l,ele r){
	ele j=_log[r-l+1],L=1<<j;
	return st[l][j]<st[r-L+1][j]?idx[l][j]:idx[r-L+1][j];
}
ele solve(ele l,ele r,ele m){
	if (l>r) return 0;
	if (l==r) return d[l]-m;
	ele i=qry(l,r);
	return solve(l,i-1,d[i])+solve(i+1,r,d[i])+d[i]-m;
}
int main(){
	freopen("road.in","r",stdin); freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=0; i<n; ++i) scanf("%d",d+i),st[i][0]=d[i],idx[i][0]=i;
	for (int j=1; (1<<j)<=n; ++j)
		for (int i=0; i+(1<<j)<=n; ++i)
			if (st[i][j-1]<st[i+(1<<(j-1))][j-1]){
				st[i][j]=st[i][j-1];
				idx[i][j]=idx[i][j-1];
			}
			else{
				ele i1=i+(1<<(j-1));
				st[i][j]=st[i1][j-1];
				idx[i][j]=idx[i1][j-1];
			}
	_log[1]=0;
	for (int i=2; i<=n; ++i) _log[i]=_log[i>>1]+1;
	printf("%d\n",solve(0,n-1,0));
	return 0;
}
