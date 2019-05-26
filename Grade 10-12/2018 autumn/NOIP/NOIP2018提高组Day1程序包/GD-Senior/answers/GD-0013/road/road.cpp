#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int a[100010],ins[100010];
int last[100010],next[100010];
int maxi (int x,int y) {
	return x>y?x:y;
}
int main ()
{
	freopen("road.in", "r", stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	    scanf("%d", &a[i]);
	int k=0;
	for(int i=2;i<=n-k;i++) {
	    a[i]=a[i+k];
	    if (a[i]==a[i-1]) k++,i--;
	}
	n -=k;
	for(int i=1;i<=n;i++) ins[i]=1;
	a[0]=0; last[1]=0;
	for(int i=2,j;i<=n;i++) {
		if (ins[i]) {
		    for(j=i-1;j>0;j=last[j])
		        if (a[j]<a[i]) break;
		        else if (a[j]==a[i]) ins[j]=0;
		    }
		last[i]=j;
	}
	a[n+1]=0; next[n]=n+1;
	for(int i=n-1,j;i>0;i--) {
		if (ins[i]) {
		    for(j=i+1;j<=n;j=next[j])
		        if (a[j]<a[i]) break;
		        else if (a[j]==a[i]) ins[j]=0;
		    }
		next[i]=j;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	    if (ins[i])
	        ans=ans+(a[i]-maxi(a[last[i]],a[next[i]]));
	printf("%d", ans);
	return 0;
}
