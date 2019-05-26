#include<fstream>
using namespace std;
ifstream cin ("road.in" ,ios::in );
ofstream cout("road.out",ios::out);

long long *a,n;
long long split(long long s,long long e)
{
	if(s>e)
		return 0;
	
	long long minx=0x7fffffffffffffff,i,j;
	for(i=s;i<=e;++i)
		minx=min(minx,a[i]);
	for(i=s;i<=e;++i)
		a[i]-=minx;
	
	for(j=i=s;j<=e;++j)
		if(a[j]==0&&!(i==s&&j-1==e))
			minx+=split(i,j-1),
			i=j+1;
	if(a[j]==0&&!(i==s&&j-1==e))
		minx+=split(i,j-1);
	
	return minx;
}

int main()
{
	long long i;
	cin>>n;
	a=new long long[n+2];
	a[n+1]=0;
	for(i=1;i<=n;++i)
		cin>>a[i];
	
	cout<<split(1,n);
	cin.close(),cout.close();
	delete []a;
	return 0;
}
