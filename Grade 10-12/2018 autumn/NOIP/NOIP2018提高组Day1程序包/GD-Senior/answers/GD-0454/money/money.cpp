#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxa=25000;
const int N=26000;
int T,n,x,ans;
int a[N],f[N];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	fo(tt,1,T){
		scanf("%d",&n);
		fo(i,1,maxa)a[i]=0;
		fo(i,1,n)scanf("%d",&x),a[x]=1;
		fo(i,1,maxa)f[i]=0;
		f[0]=1;
		ans=n;
		fo(i,1,maxa)if(a[i]){
			if(f[i])ans--;
			else fo(j,i,maxa)f[j]|=f[j-i];
		}
		printf("%d\n",ans);
	}
}
