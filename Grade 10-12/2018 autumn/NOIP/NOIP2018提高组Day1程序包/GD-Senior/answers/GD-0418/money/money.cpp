#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=500010, inf=1e9;
int n, T;
int a[maxn];
bool v[25010];

template<typename T>
inline void read(T &k)
{
	int f=1; k=0; char c=getchar();
	while(c<'0' || c>'9') c=='-' && (f=-1), c=getchar();
	while(c<='9' && c>='0') k=k*10+c-'0', c=getchar();
	k*=f;
}

inline void clear()
{
	memset(v, 0, sizeof(v));
}

inline void solve()
{
	read(n); v[0]=1;
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1, a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)
	if(!v[a[i]])
	{
		ans++;
		for(int j=0;j+a[i]<=25000;j++)
		if(v[j]) v[j+a[i]]=1;
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	read(T);
	while(T--) clear(), solve();
	return 0;
}
