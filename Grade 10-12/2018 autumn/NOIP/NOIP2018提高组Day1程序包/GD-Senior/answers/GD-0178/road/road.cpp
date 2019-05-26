#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
int a[110000],lmin[110000],rmin[110000],sta[110000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;scanf("%d",&n);
	int mmin=1<<30;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),mmin=min(a[i],mmin);
	a[0]=1<<30;
	memset(lmin,63,sizeof(lmin));
	memset(rmin,63,sizeof(rmin));
	int tp=0;
	for(int i=1;i<=n;i++)
	{
		while(tp!=0&&a[sta[tp]]>=a[i]) rmin[sta[tp--]]=i;
		sta[++tp]=i;
	}
	while(tp!=0) rmin[sta[tp--]]=0;
	tp=0;
	for(int i=n;i>=1;i--)
	{
		while(tp!=0&&a[sta[tp]]>=a[i]) lmin[sta[tp--]]=i;
		sta[++tp]=i;
	}
	while(tp!=0) lmin[sta[tp--]]=0;
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==mmin||a[lmin[i]]==a[i]) continue;
		int d=a[i],j;
		for(j=rmin[i];j!=0&&a[j]==a[i];j=rmin[j]);
		rmin[i]=j;
		if(a[lmin[i]]<a[i]&&a[rmin[i]]<a[i]) d=max(a[lmin[i]],a[rmin[i]]);
		else if(a[lmin[i]]<a[i]) d=a[lmin[i]];
		else if(a[rmin[i]]<a[i]) d=a[rmin[i]];
		ans+=a[i]-d;
	}
	printf("%lld\n",ans+mmin);
	return 0;
}
