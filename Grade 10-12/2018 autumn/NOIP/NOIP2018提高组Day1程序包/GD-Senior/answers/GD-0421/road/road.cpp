#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N = 100005;
int d[N];
int n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		d[i] = read();
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(d[i] < d[i+1])
		{
			 ans += d[i+1] - d[i];
		}
	}
	cout<<ans+d[1]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
