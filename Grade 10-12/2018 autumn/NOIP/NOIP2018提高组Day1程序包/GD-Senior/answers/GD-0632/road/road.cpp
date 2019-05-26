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
const int N=101000;
int n,a[N];bool vis[N];
long long ans=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    ans=0;
    memset(a,0,sizeof(a));
    a[n+1]=0;
    for(register int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    for(register int i=1;i<=n-1;i++)
    {
        if(vis[i])continue;
        int now=a[i];
        int num=i;
		while(now>=a[num]&&num<=n+1)
		{
			vis[num]=1;
			now=a[num];
			num++;
		}
		ans+=(a[i]-a[num-1]);
    }
    if(vis[n]==0)ans+=a[n];
    cout<<ans<<endl;
	return 0;
}
