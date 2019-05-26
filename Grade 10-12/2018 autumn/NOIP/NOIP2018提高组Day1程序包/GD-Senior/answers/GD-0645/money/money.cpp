#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

#define fo(i,j,l) for(int i=j;i<=l;++i)
#define fd(i,j,l) for(int i=j;i>=l;--i)

using namespace std;
typedef long long ll;
const ll N=27000,M=200,sx=25000;

int T,n;
int a[M];
bool f[N];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	fo(tt,1,T){
		scanf("%d",&n);
		fo(i,1,n)scanf("%d",&a[i]);
		fo(i,1,sx)f[i]=false;
		f[0]=true;
		sort(a+1,a+n+1);
		int ans=0;
		fo(i,1,n)if(f[a[i]]==true)++ans;
		else 
		fo(l,0,sx-a[i])if(f[l]==true)f[l+a[i]]=true;
		ans=n-ans;
		printf("%d\n",ans);
	}
}
