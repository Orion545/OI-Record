#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;


int main()
{
	int t,n,a,m,A[1000005];
	int bj=0;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d", &t);
	for(int k=1;k<=t;k++)
	{
		bj=0;
		scanf("%d", &n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d", &A[i]);
		}
		if(A[2]%A[1]==0)
		    bj=1;
		if(A[1]%A[2]==0)
		    bj=1;
		    
		if(bj==1)
		    m=1;
		else m=n+1;
		printf("%d\n", m);
	}
}
