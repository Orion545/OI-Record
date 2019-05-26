#include <bits/stdc++.h>
using namespace std;

long long rea()
{
	long long x=0, f=1;
	char ch=getchar();
	while (!(isdigit(ch) || ch=='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=x * 10 + ch - 48, ch=getchar();
	return x * f;
}

typedef vector<pair <long long , long long> > vect;
vector <vect> vec(50500);

long long n,m,sum,a[50500];

void adde(long long x, long long y, long long z)
{
	vec[x].push_back(make_pair(y,z));
	vec[y].push_back(make_pair(x,z));
}

bool check(long long x)
{
	long long tmp=0,tot=0;
	for (long long i=1; i<=n-1; i++)
	{
		if (vec[i][0].first==i+1) tmp+=(long long)vec[i][0].second;
		else tmp+=(long long)vec[i][1].second;
		if (tmp>=x) tot++,tmp=0;
		if (tot==m) return 1;
	}
	return 0;
}

void work1()
{
	long long l=1,r=sum,ans=sum;
	while (l<=r)
	{
		long long mid=(l+r) / 2;
		if (check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
}

bool cmp(long long x, long long y)
{
	return x > y;
}

void work2()
{
	for (long long i=2; i<=n; i++)
	a[i]=vec[i][0].second;
	sort(a+2,a+n+1,cmp);
	cout<<a[m+1];
}

long long f[1050][1050];

void work3()
{
	long long maxx=0;
	for (long long i=1; i<=n; i++)
	for (long long j=1; j<=n; j++) f[i][j]=9999999999;
	for (long long i=1; i<=n; i++)
	{
		long long si=vec[i].size();
		for (long long j=0; j<si; j++)
		f[i][vec[i][j].first]=vec[i][j].second;
	}
	for (long long k=1; k<=n; k++)
	for (long long i=1; i<=n; i++)
	for (long long j=1; j<=n; j++)
		if (k!=i && i!=j && k!=j) 
		f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
	for (long long i=1; i<=n; i++)
	for (long long j=1; j<=n; j++) if (f[i][j]!=9999999999) maxx=max(maxx,f[i][j]);
	cout<<maxx;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=rea(),m=rea();
	bool bo=0,bo1=0;
	for (long long i=1; i<=n-1; i++)
	{
		long long x=rea(),y=rea(),z=rea();sum+=z;
		adde(x,y,z);
		if (y!=x+1) bo=1;
		if (x!=1) bo1=1;
	}
	if (bo==0) work1();
	else if (bo1==0) work2();
	else if (m==1) work3();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
