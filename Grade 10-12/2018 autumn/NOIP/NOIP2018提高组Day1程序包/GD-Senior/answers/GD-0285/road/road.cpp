#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
inline int rd(){
	char c=getchar();int x=0,flag=1;
	for(;c<'0'||c>'9';c=getchar())
		if(c=='-')
			flag=-1;
	for(;c>='0'&&c<='9';c=getchar())
		x=x*10+c-'0';
	return x*flag;
}
int n,ans=0,a[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++)
		a[i]=rd();
	for(int i=1;i<=n;i++)
		if(a[i]>a[i-1])
			ans+=a[i]-a[i-1];
	printf("%d\n",ans);
	return 0;
}
