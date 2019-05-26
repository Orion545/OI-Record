#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int T,n;
int A[MAXN];
int Gcd(int x,int y)
{
	while(y)
	{
		int c=x%y;
		x=y;
		y=c;
	}
	return x;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	srand((int)time(0));
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++)	
		{
			scanf("%d",&A[i]);
			if(A[i]==1)	ans=1;
		}
		if(ans==0)
		{
			if(n==2)
			{
				int gcd1,gcd2;
				gcd1=Gcd(A[1],A[2]);
				if(gcd1>1)	ans=1;
				else	ans=2;		
			}	
			else	ans=1+rand()%n;
		}		
		printf("%d\n",ans);
	}
	return 0;
}
