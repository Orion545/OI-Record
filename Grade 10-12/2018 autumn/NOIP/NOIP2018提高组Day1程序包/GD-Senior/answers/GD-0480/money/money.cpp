#include<algorithm>
#include<cmath>
#include<cctype>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<iostream>
using namespace std;

char RR[1000000],*RS=RR,*RT=RR;

#define mygetc() (RS==RT&&(\
RT=(RS=RR)+fread(RR,1,1000000,stdin)\
,RS==RT)?EOF:*RS++)

inline int reint()
{
	register int x=0;
	
	register char ch=mygetc();
	
	while (!isdigit(ch))
	ch=mygetc();
	
	while (isdigit(ch))
	x=x*10+ch-'0',ch=mygetc();
	
	return x;
}

int T,n,ans,a[150],f[30000];

int main()
{
	freopen("money.in","r",stdin),
	freopen("money.out","w",stdout);
	
	T=reint();
	
	while (T--)
	{
		n=reint(),ans=0;
		
		for (register int i=n;i;--i)
		a[i]=reint();
		
		sort(a+1,a+n+1);
		
		for (register int i=1;i<=a[n];++i)
		f[i]=1;
		
		for (register int i=1;i<=n;++i)
		{
			ans+=f[a[i]];
			
			if (f[a[i]])
			for (register int j=a[i];j<=a[n];++j)
			if (!f[j-a[i]])f[j]=0;
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
