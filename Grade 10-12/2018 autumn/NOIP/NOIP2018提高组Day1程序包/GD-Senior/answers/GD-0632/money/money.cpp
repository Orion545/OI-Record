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
const int N=110;
int t,a[N];int n;
bool f[30000];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(register int o=1;o<=t;o++)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		cin>>n;
		int ans=n;int maxn=0;
		for(register int i=1;i<=n;i++)
		{
			cin>>a[i];maxn=max(maxn,a[i]);
		}
		sort(a+1,a+1+n);
		f[0]=1;
        for(register int i=1;i<=n;i++)
        {
        	if(f[a[i]])ans--;
        	for(register int j=a[i];j<=maxn;j++)
        	{
        		if(f[j])continue;
        		if(f[j-a[i]])f[j]=1;
        	}
        }
        cout<<ans<<endl;
	}
	return 0;
}
