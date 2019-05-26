#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int t,n,ans,m;
int a[110];
int bo[25100];

void sort(int ,int );
void swap(int &,int &);

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	srand(141355);
	scanf("%d",&t);
	while (t--)
	{
		memset(bo,-1,sizeof(bo));
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(1,n);
		int c=1;
		while (a[c]==0)
			c++;
		ans=1;bo[0]=0;m=a[c];
		for (int i=2;i<=n;i++)
		{
			int now=a[i]/m;
			if ((bo[a[i]%m]==-1)||(bo[a[i]%m]>now))
			{
				bo[a[i]%m]=now;ans++;
				for (int k=1;k<m;k++)
					if (bo[k]>=0)
						for (int f=1;f<m;f++)
							if (bo[(k+f*a[i])%m]==-1)
								bo[(k+f*a[i])%m]=(f*a[i]+k)/m+bo[k];
							else
								bo[(k+f*a[i])%m]=min(bo[(k+f*a[i])%m],(f*a[i]+k)/m+bo[k]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

void sort(int l,int r)
{
	int le=l,ri=r;
	int mid=a[rand()%(ri-le+1)+le];
	while (le<=ri)
	{
		while (a[le]<mid)
			le++;
		while (a[ri]>mid)
			ri--;
		if (le<=ri)
		{
			swap(a[le],a[ri]);
			le++;ri--;
		}
	}
	if (l<ri)
		sort(l,ri);
	if (le<r)
		sort(le,r);
	return ;
}

void swap(int &s1,int &s2)
{
	int f=s1;s1=s2;s2=f;
	return ;
}
