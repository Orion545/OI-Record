#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mxn=100010,m=10000;
int n,exist[mxn],ans;
struct nd{int id,val;}a[mxn];
int cmp(const nd &x,const nd &y){return x.val>y.val;}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i].val),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for (int i=m,cnt=0,cur=1;i;--i,ans+=cnt)
		for (;cur<=n&&a[cur].val>=i;++cur)
			exist[a[cur].id]=1,cnt+=1-exist[a[cur].id-1]-exist[a[cur].id+1];
	printf("%d\n",ans);
	return 0;
}
