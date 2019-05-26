#include<bits/stdc++.h>

#define imax(a,b) ((a>b)?(a):(b))
#define imin(a,b) ((a<b)?(a):(b))

using namespace std;

typedef long long ll;

const int N=105;
const int M=25000;

int T,ans;
int n,d[N],f[M+5];

bool cmp(int A,int B) { return (A<B); }

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&d[i]);
		sort(d+1,d+1+n,cmp);
		f[0]=1;
		for(int i=0;i<=M;++i)
		if(f[i])
		{
			for(int j=1;j<=n;++j)
			if(i+d[j]<=M) ++f[i+d[j]]; else break;
		}
		ans=0;
		for(int i=1;i<=n;++i)
		if(f[d[i]]==1) ++ans; printf("%d\n",ans);
		for(int i=0;i<=M;++i) f[i]=0;
	}
	return 0;
}
