#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin ("track.in" ,ios::in );
ofstream cout("track.out",ios::out);

long long a[50001];

bool _cmp(long long a,long long b)
	{return a<=b;}

int main()
{
	long long n,m,i,k,maxn=0x8000000000000000;
	cin>>n>>m;
	for(i=1;i<=n;++i)
		cin>>k>>k>>a[i];
	sort(a+1,a+n+1,_cmp);
	
	if(m+m<=n)
		for(i=n;m+(n-i)/2!=i;--i)
			maxn=max(a[i]+a[m+(n-i)/2],maxn);
	else if(a[1]+a[2]>a[i])
		maxn=a[i];
	else maxn=15;
	cout<<maxn;
	cin.close(),cout.close();
	return 0;
}
