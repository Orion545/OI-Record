#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <set>
#include <bitset>
#include <algorithm>
using namespace std;

namespace Solution_zzc
{
template <typename tp>
void read(tp &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

bitset<25005> able;
int a[101];

int main()
{
	int T;
	read(T);
	while(T--)
	{
		int n;
		int ans=0;
		read(n);
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			read(a[i]);
		}
		sort(a,a+n);
		if(n==1||a[0]==1)
		{
			puts("1");
			continue;
		}
		able=1;
		int end=a[n-1]+2;
//		cout<<end<<endl;
		for(int i=0;i<n;i++)
		{
			if(able[a[i]])continue;
			for(int j=1;a[i]*j<=end;j*=2)
			{
				able|=(able<<(a[i]*j));
			}
//			cout<<able<<endl;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	return Solution_zzc::main();
}
