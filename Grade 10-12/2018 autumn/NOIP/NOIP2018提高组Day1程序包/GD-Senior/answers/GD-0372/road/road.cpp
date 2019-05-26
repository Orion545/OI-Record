#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
 
using namespace std;

long long n,cnt=0,ans=0,a[100010],pi,pj,len,maxlen,maxi,maxj,minnum,num;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) {scanf("%lld",&a[i]); if (a[i]!=0) ++cnt;}
	while(cnt>0)
	{
		pi=0; pj=1;
		maxlen=0; minnum=0;
		while(pj<=n)
		{
			num=10000000;
			while(a[pj]!=0) {if (a[pj]<num) num=a[pj]; ++pj;}
			len=pj-pi-1; 
			if (len>maxlen) {maxi=pi; maxj=pj; minnum=num;}
			pi=pj;
			++pj;
		}
		for(int i=maxi+1; i<maxj; i++)
		{
			a[i]-=minnum;
			if (a[i]==0) --cnt;
		}
		ans+=minnum;
	}
	printf("%lld\n",ans);
	
	return 0;
}
