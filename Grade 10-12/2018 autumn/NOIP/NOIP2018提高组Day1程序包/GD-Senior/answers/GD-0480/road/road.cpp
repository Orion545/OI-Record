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

int n,nowx,lasx,ans;

int main()
{
	freopen("road.in","r",stdin),
	freopen("road.out","w",stdout);
	
	n=reint();
	
	while (n--)
	ans+=((nowx=reint())>lasx)?nowx-lasx:0,
	lasx=nowx;
	
	printf("%d",ans);
	
	return 0;
}
