#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
const int N=50010;
int head[N],to[N],next[N],edge[N],tot=0;
int n,m;
int p,q;
int far1,farq;int maxn1=0,maxn2=0;
bool vis[N];
inline void add(int x,int y,int z)
{
	next[++tot]=head[x],head[x]=tot,to[tot]=y,edge[tot]=z;
}
void dfs(int x,int sum)
{
	if(sum>maxn1)
	{
		maxn1=sum;far1=x;
	}
	for(register int i=head[x];i;i=next[i])
	{
		int y=to[i],z=edge[i];
		if(vis[y])continue;
		vis[y]=1;
		dfs(y,sum+z);
		vis[y]=0;
	}
}
void dfs2(int x,int sum)
{
	if(sum>maxn2)
	{
		maxn2=sum;farq=x;
	}
	for(register int i=head[x];i;i=next[i])
	{
		int y=to[i],z=edge[i];
		if(vis[y])continue;
		vis[y]=1;
		dfs2(y,sum+z);
		vis[y]=0;
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	bool flag=0;long long pum=0;
	for(register int i=1;i<=n-1;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(y!=x+1)flag=1;
		add(x,y,z);add(y,x,z);
		pum+=z;
	}
	if(!flag){
		cout<<pum/m<<endl;return 0;
	}
	maxn1=0;far1=1;
	vis[1]=1;
	dfs(1,0);
	for(register int i=1;i<=n;i++)vis[i]=0;
	vis[far1]=1;
	dfs2(far1,0);
	cout<<maxn2/m<<endl;
	return 0;
}
