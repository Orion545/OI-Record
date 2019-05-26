#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
long long p[100007],ans1,ans2;
char str[7];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d %d %s",&n,&m,str);
	for(int i=1;i<=n;i++) scanf("%lld",&p[i]); 
	for(int i=1,a,b;i<n;i++)
	{
		scanf("%d %d",&a,&b);
	}
	for(int i=1;i<=n;i+=2) ans1+=p[i];
	for(int i=2;i<=n;i+=2) ans2+=p[i];
	for(int i=1;i<=m;i++)
	{
		int l,x,r,y; scanf("%d %d %d %d",&l,&x,&r,&y);
		if((l%2!=r%2 && x==y) || (l%2==r%2 && x!=y) ) printf("-1\n");
		else if(l%2==1 && x==1) printf("%lld\n",ans1);
		else if(l%2==0 && x==0) printf("%lld\n",ans1);
		else if(l%2==0 && x==1) printf("%lld\n",ans2);
		else if(l%2==1 && x==0) printf("%lld\n",ans2);
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
