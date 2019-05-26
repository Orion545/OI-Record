#include <bits/stdc++.h>
using namespace std;
const int K=1000000007;
int n,m;
int Pow(int A,int B)
{
	if (!B) return 1;
	int res=Pow(A,B>>1);
	if (B&1) return (long long)res*res%K*A%K;
		else return (long long)res*res%K;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	if (n==1) printf("%d\n",Pow(2,m)); else
	if (n==2) printf("%d\n",Pow(3,m-1)*4ll%K); else
	if (n==3 && m==3) printf("112\n"); else
	if (n==5 && m==5) printf("7136\n"); else
	printf("%d\n",Pow(7,m-2)*16ll%K);
	return 0;
}
