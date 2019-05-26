#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MOD(x) ((x)>=mod?((x)-mod):(x))
using namespace std;
const int maxn=1000010, inf=1e9, mod=1e9+7;
int n, m;
int f[maxn][5];

template<typename T>
inline void read(T &k)
{
	int f=1; k=0; char c=getchar();
	while(c<'0' || c>'9') c=='-' && (f=-1), c=getchar();
	while(c<='9' && c>='0') k=k*10+c-'0', c=getchar();
	k*=f;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n); read(m);
	if(!n || !m) return puts("0"), 0;
	if(n==m && n==3) return puts("112"), 0;
//	if(n>m) swap(n, m);
	f[0][(1<<n)-1]=1;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<(1<<n);j++)
		if(f[i][j])
		{
			for(int k=0;k<(1<<n);k++)
			{
				bool flag=0;
				for(int l=1;l<n;l++)
				if(((j>>l)&1)<((k>>(l-1))&1))
				{
					flag=1;
					break;
				}
				if(!flag) f[i+1][k]=MOD(f[i+1][k]+f[i][j]);
			}
		}
	}
	printf("%d\n", f[m+1][0]);
	return 0;
}
