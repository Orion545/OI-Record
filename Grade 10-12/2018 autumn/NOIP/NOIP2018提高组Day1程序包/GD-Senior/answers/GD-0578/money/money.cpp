#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define N 110
#define M 55000
using namespace std;
int n,a[N],c[M];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int ac;scanf("%d",&ac);
	while(ac--)
	{
		scanf("%d",&n);
		fo(i,1,n) scanf("%d",&a[i]);
		if(n==1){printf("1\n");continue;}
		sort(a+1,a+n+1);
		int m=a[n],ans=0;
		c[0]=1;
		fo(i,1,n)
		if(c[a[i]]==0)
		{
			ans++;
			fo(j,0,m-a[i]) if(c[j]) c[j+a[i]]=1;
		}
		fo(i,1,m) c[i]=0;
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
