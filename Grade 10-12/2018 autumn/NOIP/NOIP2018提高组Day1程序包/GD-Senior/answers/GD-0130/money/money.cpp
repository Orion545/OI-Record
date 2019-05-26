#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define ll long long
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)

using namespace std;

const int maxn=107,maxa=25003;

int n,a[maxn];

void Init(){
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
}

int ans;
bool bz[maxa],az[maxa];
void Solve(){
	sort(a+1,a+n+1);
	ans=0;
	memset(bz,0,sizeof bz);
	fo(i,1,n) bz[a[i]]=true;
	memset(az,0,sizeof az);
	az[0]=true;
	fo(i,1,n)
		if (!az[a[i]]){
			ans++;
			fo(j,0,maxa-1)
				if (az[j] && j+a[i]<maxa) az[j+a[i]]=true;
		}
}
void Print(){
	printf("%d\n",ans);
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--){
		Init();
		Solve();
		Print();
	}
	return 0;
}
