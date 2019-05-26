#include<iostream>
#include<cstdio>
const int N=110;
int T,n,i,j,k,l;
int a[N];
void q(int l,int r)
{
	int z,y,mid;
	z=l;
	y=r;
	mid=a[(l+r)/2];
	while (l<r)
	{
		while (a[l]<mid) l++;
		while (a[r]>mid) r--;
		if (l<=r)
		{
			int jh;
			jh=a[l];
			a[l]=a[r];
			a[r]=jh;
			l++;
			r--;
		}
	}
	if (l<y) q(l,y);
	if (z<r) q(z,r);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		q(1,n);
		int ans=0;
		if (n==1) ans=1;
		if (n==2)
		{
			if (a[2]%a[1]==0) ans=1;
			else
				ans=2;
		}
		if (n==3)
		{
			if (a[2]%a[1]==0)
			{
				n--;
				a[2]=a[3];
				if (a[2]%a[1]==0) ans=1;
				else
					ans=2;
			}
			else
			{
				int b=a[3]/a[1]+1;
				ans=3;
				bool bz=false;
				for (i=0;i<=b;i++)
				{
					for (j=0;j<=b;j++)
					{
						if (a[1]*i+a[2]*j==a[3])
						{
							bz=true;
							ans=2;
							break;
						}
					}
					if (bz) break;
				}
			}
		}
		if (n==4)
		{
			ans=4;
			if (a[2]%a[1]==0) ans--;
			int b=a[3]/a[1]+1;
			bool bz=false;
			for (i=0;i<=b;i++)
			{
				for (j=0;j<=b;j++)
				{
					if (a[1]*i+a[2]*j==a[3])
					{
						bz=true;
						ans--;
						break;
					}
				}
				if (bz) break;
			}
			b=a[4]/a[1]+1;
			bz=false;
			for (i=0;i<=b;i++)
			{
				for (j=0;j<=b;j++)
				{
					for (k=0;k<=b;k++)
					{
						if (a[1]*i+a[2]*j+a[3]*k==a[4])
						{
							bz=true;
							ans--;
							break;
						}
					}
					if (bz) break;
				}
				if (bz) break;
			}
		}
		if (n==5)
		{
			ans=5;
			if (a[2]%a[1]==0) ans--;
			int b=a[3]/a[1]+1;
			bool bz=false;
			for (i=0;i<=b;i++)
			{
				for (j=0;j<=b;j++)
				{
					if (a[1]*i+a[2]*j==a[3])
					{
						bz=true;
						ans--;
						break;
					}
				}
				if (bz) break;
			}
			bz=false;
			b=a[4]/a[1]+1;
			for (i=0;i<=b;i++)
			{
				for (j=0;j<=b;j++)
				{
					for (k=0;k<=b;k++)
					{
						if (a[1]*i+a[2]*j+a[3]*k==a[4])
						{
							bz=true;
							ans--;
							break;
						}
					}
					if (bz) break;
				}
				if (bz) break;
			}
			b=a[5]/a[1]+1;
			bz=false;
			for (i=0;i<=b;i++)
			{
				for (j=0;j<=b;j++)
				{
					for (k=0;k<=b;k++)
					{
						for (l=0;l<=b;l++)
						{
							if (a[1]*i+a[2]*j+a[3]*k+a[4]*l==a[5])
							{
								bz=true;
								ans--;
								break;
							}
						}
						if (bz) break;
					}
					if (bz) break;
				}
				if (bz) break;
			}
		}
		printf("%d\n",ans);
		T--;
	}
	return 0;
}
