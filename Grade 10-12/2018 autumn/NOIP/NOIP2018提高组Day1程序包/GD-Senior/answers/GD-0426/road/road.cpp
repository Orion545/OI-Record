#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
vector <int> b[100005];
int n,m,a[100005],ST[400005][200];

long long fac(int L,int R)
{
	if (L==R) return a[L];
	if (L+1==R) return max(a[L],a[R]);
	if (L-1==R) return a[R];
	
	int mm=log(R-L)/log(2);
	int min_L_R=min(ST[L][mm],ST[R-(2<<(mm-1))][mm]);
	int mid;
	
	for (int k=0;k<b[min_L_R].size();k++) 
	  if (b[min_L_R][k]>=L&&b[min_L_R][k]<=R) 
	  {
	  	mid=b[min_L_R][k];
	  	break;
	  }
	
	return fac(L,mid-1)+fac(mid+1,R)-min_L_R;
}

long long baoli()
{
	long long ans=0;
	bool f=1;
	int i,j;
	while (f)
	{
		f=0;
		for (int o=1;o<=n;o++) 
		  if (a[o]!=0) 
		  {
		    f=1;break;
		  }
		if (!f) break;
				
		i=1,j=1;
		while (i<=n)
		{
		  int minn=99999999; 
		  while (a[i]==0&&i<=n) i++;
		  j=i;
		  while (a[j]!=0&&j<=n) j++;
		  for (int k=i;k<=j-1;k++) minn=min(minn,a[k]);
		  for (int k=i;k<=j-1;k++) a[k]-=minn;
		  i=++j;
		  ans+=minn;
		}
	}
	return ans;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
	  scanf("%d",&a[i]);
	  b[a[i]].push_back(i);
	}
	a[n+1]=213906214;
	memset(ST,127,sizeof(ST));
	for (int i=1;i<=n;i++) ST[i][0]=min(a[i],a[i+1]);
	m=log(n)/log(2)+1;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
	    if (ST[i][j-1]>ST[i+(2<<(j-1))][j-1]) ST[i][j]=ST[i+(2<<(j-1))][j-1];
	    else ST[i][j]=ST[i][j-1];
	
	if (n>1000) printf("%lld",fac(1,n));
	else printf("%lld",baoli());
	
	return 0;
}
