#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define N 701
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
bool fl[N][N],fr[N][N],g[N][N]; int a[N];
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int main()
{	int n; cin>>n;
	for(rint i=1;i<=n;i++) scanf("%d",&a[i]);
	for(rint i=1;i<n;i++) fl[i][i]=(gcd(a[i],a[i+1])!=1);
	for(rint i=2;i<=n;i++) fr[i][i]=(gcd(a[i],a[i-1])!=1);
	for(rint i=1;i<=n;i++)
	for(rint j=1;j<=n;j++) g[i][j]=(gcd(a[i],a[j])!=1);
	for(rint i=2;i<=n;i++)
	for(rint l=1;l+i-1<=n;l++) 
	{	int r=l+i-1,tag=0;
		for(rint k=l;k<=r;k++)
		if((k==l&&fr[k+1][r])||(k==r&&fl[l][k-1])||(fl[l][k-1]&fr[k+1][r]))
		{	tag=1;
			if(r!=n) fl[l][r]|=g[k][r+1];
			if(l!=1) fr[l][r]|=g[k][l-1];
		}
		if(l==1&&r==n) return !printf(tag?"Yes":"No");
	}
	return 0;
}
