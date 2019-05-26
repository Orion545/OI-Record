#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#define Maxn 300020
#define Maxm 500030
#define Maxans 30000000010
using namespace std;
int n,m;
int wv[Maxn];
int r1[Maxm],r2[Maxm],rr1[Maxm],rr2[Maxm];
long long int f[Maxm][3];
long long int mini (long long int x,long long int y) {
	if (x<y) return x;
	return y;
}
int main ()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	cin>>n>>m;
	char r;
	scanf("%c%c%c", &r, &r, &r);
	for(int i=1;i<=n;i++)
	    scanf("%d", &wv[i]);
	for(int i=1;i<=m;i++)
	    scanf("%d%d%d%d", &r1[i], &rr1[i], &r2[i], &rr2[i]);
	for(int i=1;i<=m;i++) {
	    f[i][0]=wv[1], f[i][1]=-1, f[i][2]=0;
	    if (r1[i]==1) {
	        if (rr1[i]) f[i][1]=f[i][2]=-1;
	        else f[i][0]=-1;
	    }
	    else if (r2[i]==1) {
	    	if (rr2[i]) f[i][1]=f[i][2]=-1;
	    	else f[i][0]=-1;
	    }
	}
	for(int i=2;i<=n;i++)
	    for(int j=1;j<=m;j++)
	    {
	    	long long int x,y,z; x=Maxans;
	    	if (f[j][0]!=-1) x=mini(x,f[j][0]);
			if (f[j][1]!=-1) x=mini(x,f[j][1]);
			if (f[j][2]!=-1) x=mini(x,f[j][2]);
			if (x!=Maxans) x+=wv[i]; else x=-1;
	    	y=f[j][0]; z=f[j][1];
	    	f[j][0]=x; f[j][1]=y; f[j][2]=z;
	        if (r1[i]==1) {
	            if (rr1[i]) f[i][1]=f[i][2]=-1;
	            else f[i][0]=-1;
	        }
	        else if (r2[i]==1) {
	        	if (rr2[i]) f[i][1]=f[i][2]=-1;
	        	else f[i][0]=-1;
	        }
    	}
    for(int i=1;i<=m;i++) {
    	long long int x=Maxans;
	    if (f[i][0]!=-1) x=mini(x,f[i][0]);
		if (f[i][1]!=-1) x=mini(x,f[i][1]);
		if (x==Maxans) x=-1;
		printf("%lld\n", x);
	}
	return 0;
}
