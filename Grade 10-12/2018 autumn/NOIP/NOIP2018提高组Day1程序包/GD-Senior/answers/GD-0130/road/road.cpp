#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define ll long long
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)

using namespace std;

const int maxn=100007;

int n,a[maxn];

void Init(){
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
}

int Ans=0;
void Solve(){
	fo(i,2,n) if (a[i-1]>a[i]) Ans+=a[i-1]-a[i];
	Ans+=a[n];
}

void Print(){
	printf("%d\n",Ans);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Init();
	Solve();
	Print();
	return 0;
}
