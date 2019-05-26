#include<algorithm>
#include<cstdio>
using namespace std;
int n,sl,fh,ans,a[100010];
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;++i) a[i]=rd();
	for(int i=n;i>=1;--i)
	{
		a[i]-=a[i-1];
		if(a[i]>0) ans+=a[i];
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
