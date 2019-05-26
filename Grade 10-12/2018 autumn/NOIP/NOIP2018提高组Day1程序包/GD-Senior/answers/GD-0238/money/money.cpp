#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i) 
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define max(q,w) ((q)<(w)?(w):(q))
#define min(q,w) ((q)<(w)?(q):(w))
using namespace std;
const int N=200500;
int read(int &n)
{
	int w=1;n=0;
	char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return n=n*w;
}
int n,m,ans;
int a[N],d[N];
int z[N],TI;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int q,w,_,mx;
	read(_);
	fo(I_,1,_)
	{
		read(n);
		mx=0;
		fo(i,1,n)read(a[i]),mx=max(mx,a[i]);
		sort(a+1,a+1+n);
		++TI;
		ans=0;
		z[0]=TI;d[0]=0;
		fo(i,1,n)if(z[a[i]]<TI)
		{
			++ans;d[++d[0]]=a[i];
			fo(j,0,mx-a[i])if(z[j]==TI)z[j+a[i]]=TI;
		}
		printf("%d\n",ans);
//		fo(i,1,ans)printf("%d ",d[i]);
	}
	return 0;
}
