#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define N 125
#define M 30005
using namespace std;
int a[N],b[N],mi,n,m,dis[M],m1,bz[M];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(bz,0,sizeof(bz));
		memset(dis,107,sizeof(dis));
		m1=0;
		cin>>n;
		mi=25000;
		fo(i,1,n) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		mi=a[1];
		int s=0;
		fo(i,1,n)
		{
			int c=a[i]%mi;
			if(dis[c]>a[i])
			{
				dis[c]=a[i];
				s++;
				fo(j,0,mi-1)
				{
					if(bz[j]!=i&&dis[j]!=1802201963)
					{
						int mw=j,ms=dis[j],k=(j+c)%mi,p;
						while(k!=j) 
						{
							if(dis[k]<ms) ms=dis[k],mw=k;
							k+=c;
							if(k>=mi) k-=mi;
						}
						k=mw,p=(k+c)%mi;
						bz[k]=i;
						while(p!=mw) 
						{
							bz[p]=i;
							dis[p]=min(dis[p],dis[k]+a[i]);
							k=p,p+=c;
							if(p>=mi) p-=mi;
						}
					}
				}
			} 
		}
		printf("%d\n",s);
	}
}
