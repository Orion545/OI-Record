#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<iostream>
#define N 110
using namespace std;
long p[N],pl,h[N],a[N],len,n;
bool chk(long aug,long *t,long now)
{
	if (aug==0)return true;
		else if (now==0)return false;
	
	for (long z=aug/t[now];z>=0;z--)
		if (chk(aug-z*t[now],t,now-1))return true;
	return false;
}
bool chkk(long leng)
{
	long i,l;
	for (i=1,l=0;i<=2*len;i++)
		if (!chk(i,h,leng))
			if (l==pl||i!=p[l+1])return false;
				else l++;
	if (l==pl)return true;
		else return false;
}
bool form(long now,long leng,long aug)
{
	if (now>leng){
		return chkk(leng);
	}
	for (long i=aug+1;i<=len-(leng-now);i++){
		bool ox=true;
		for (long j=1;j<now;j++)
			if (i%h[j]==0){
				ox=false;
				break;
			}
		if (!ox)continue;
		h[now]=i;
		if (form(now+1,leng,i))return true;
	}
	return false;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	long T,Min1,Min2,Max1,i,j;
	scanf("%ld",&T);
	for (;T>0;T--){
		scanf("%ld",&n);
		Min1=Min2=~(1<<31);
		for (i=1;i<=n;i++)scanf("%ld",&a[i]);
		for (i=1;i<=n;i++){
			for (j=1;j<=n;j++)
				if (a[i]%a[j]==0)a[i]=a[j];
		}
		sort(a+1,a+n+1);
		a[0]=0;
		for (i=1,j=0;i<=n;i++)
			if (a[i]!=a[j])a[++j]=a[i];
		n=j;
		if (n<=2||n>4){
			printf("%ld\n",n);
			continue;
		}
		
		Min1=Min2=~(1<<31);
		for (i=1;i<=n;i++){
			if (a[i]<=Min1)Min2=Min1,Min1=a[i];
				else if (a[i]<Min2)Min2=a[i];
		}
		len=Min2*Min1-Min2-Min1;
		pl=0;
		for (i=1;i<=len;i++){
			if (!chk(i,a,n))p[++pl]=i;
		}
		for (i=1;i<n;i++){
			if (form(1,i,0)){
				printf("%ld\n",i);
				break;
			}
		}
		if (i==n)printf("%ld\n",n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
