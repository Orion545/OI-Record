#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
inline int getint()
{
	register int r=0,f=1;
	register char c=getchar();
	while (!isdigit(c))
		f=c=='-'?-f:f,c=getchar();
	while (isdigit(c))
		r=(r<<3)+(r<<1)+(c^48),c=getchar();
	return r*f;
}
const int N=1e5+10;
int n,d[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=getint();
	for (int i=1;i<=n;i++)
		d[i]=getint();
	int ans=0;
	for (int i=1;i<=n;i++)
		ans+=max(d[i]-d[i-1],0);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
