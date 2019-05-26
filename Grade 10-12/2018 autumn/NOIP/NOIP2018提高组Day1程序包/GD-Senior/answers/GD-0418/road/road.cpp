#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=500010, inf=1e9;
struct poi{int w, pos;}q[maxn];
int n, now, ans;
bool v[maxn];

template<typename T>
inline void read(T &k)
{
	int f=1; k=0; char c=getchar();
	while(c<'0' || c>'9') c=='-' && (f=-1), c=getchar();
	while(c<='9' && c>='0') k=k*10+c-'0', c=getchar();
	k*=f;
}

bool operator < (poi a, poi b) {return a.w>b.w;}

inline void insert(int x)
{
	if(!v[x-1] && !v[x+1]) now++;
	else if(v[x-1] && v[x+1]) now--;
	v[x]=1; 
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n);
	for(int i=1;i<=n;i++) read(q[i].w), q[i].pos=i;
	sort(q+1, q+1+n);
	now=0; ans=0;
	for(int i=10000, j=1;i;i--)
	{
		while(j<=n && q[j].w==i) insert(q[j].pos), j++;
		ans+=now;
	}
	printf("%d\n", ans);
	return 0;
}
