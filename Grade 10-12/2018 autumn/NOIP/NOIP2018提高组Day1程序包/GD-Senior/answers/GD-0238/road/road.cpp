#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i) 
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define max(q,w) ((q)<(w)?(w):(q))
#define min(q,w) ((q)<(w)?(q):(w))
using namespace std;
const int N=100500;
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
int a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int q,w;
	read(n);
	q=0;
	fo(i,1,n)
	{
		read(a[i]);
		ans+=max(0,a[i]-q);
		q=a[i];
	}
	printf("%d\n",ans);
	return 0;
}
